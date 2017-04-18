#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#if defined(__APPLE__)
    #include <OpenGL/gl3.h> // defines OpenGL 3.0+ functions
#else
    #if defined(WIN32)
        #define GLEW_STATIC 1
    #endif
    #include <GL/glew.h>
#endif
#include "cyGL.h"

#include "control/controls.h"
#include "control/IControl.h"
#include "gl/textures.h"
#include "gui/GLCommon.h"
#include "gui/windows/subwindows/GLTextureWindow.h"
#include "enums.h"

// using definitions
using EventFlag = smskinedit::control::EventFlag;
using ModelType = smskinedit::enums::ModelType;
using TextureType = smskinedit::enums::TextureType;

// namespace shortenings
namespace controls = smskinedit::control::controls;
namespace textures = smskinedit::gl::textures;

// constants
static const char* CALLBACK_ID = "GL_TEXTURE_WINDOW";

namespace smskinedit {
    namespace gui {

        // Constructors
        GLTextureWindow::GLTextureWindow(int x, int y, int width, int height) :
                Fl_Gl_Window{x, y, width, height} {
            mode(FL_RGB8 | FL_DOUBLE | FL_OPENGL3);
            end();

            // Set up callbacks
            controls::fileControl.addCallback(CALLBACK_ID, [&](EventFlag) {
                redraw();
            });
            controls::templateControl.addCallback(CALLBACK_ID, [&](EventFlag) {
                redraw(); // onion skinning value updated
            });
            controls::textureControl.addCallback(CALLBACK_ID, [&](EventFlag) {
                redraw(); // model or texture type changed
            });
        }
        GLTextureWindow::~GLTextureWindow() {
            if (_textureBundle) {
                delete _textureBundle;
                _textureBundle = nullptr;
            }
        }

        // Window Functions
        void GLTextureWindow::draw() {
            if (!valid()) {
                glViewport(0, 0, pixel_w(), pixel_h());
            }
            if (!_textureBundle) {
                _textureBundle = new TextureBundle{};
            }

            glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
            glClear(GL_COLOR_BUFFER_BIT);

            if (textures::texturesReady()) {

                ModelType modelType = controls::textureControl.getModelType();
                TextureType textureType =
                        controls::textureControl.getTextureType();

                cy::GLRenderBuffer<GL_TEXTURE_2D>* actualTex = nullptr;
                cy::GLRenderBuffer<GL_TEXTURE_2D>* templateTex = nullptr;
                if (modelType == ModelType::BODY) {
                    if (textureType == TextureType::DIFFUSE) {
                        actualTex = &textures::bodyDiffuse;
                    } else {
                        actualTex = &textures::bodyEmissive;
                    }

                    templateTex = &textures::bodyTemplate;
                } else { // assume ModelType::HEAD
                    if (textureType == TextureType::DIFFUSE) {
                        actualTex = &textures::helmDiffuse;
                    } else {
                        actualTex = &textures::helmEmissive;
                    }

                    templateTex = &textures::helmTemplate;
                }
                actualTex->BindTexture(0);
                templateTex->BindTexture(1);

                _textureBundle->setActualTextureUnit(0);
                _textureBundle->setTemplateTextureUnit(1);
                _textureBundle->setAlphaLevel(
                        controls::templateControl.getOnionSkinningValue());
                _textureBundle->render();
            }
        }
        int GLTextureWindow::handle(int event) {
            smskinedit::gui::glewInit(event, this); // okay to call every event
            return Fl_Gl_Window::handle(event);
        }
    }
}
