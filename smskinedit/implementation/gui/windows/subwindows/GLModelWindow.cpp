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

#include "gui/windows/GLCommon.h"
#include "gui/windows/subwindows/GLModelWindow.h"

namespace smskinedit {
    namespace gui {

        // Constructors
        GLModelWindow::GLModelWindow(int x, int y, int width, int height) :
                Fl_Gl_Window{x, y, width, height} {
            mode(FL_RGB8 | FL_DOUBLE | FL_OPENGL3);
            end();
        }
        GLModelWindow::~GLModelWindow() {}

        // Window Functions
        void GLModelWindow::draw() {
            if (!valid()) {
                glViewport(0, 0, pixel_w(), pixel_h());
            }
            glClearColor(1.0F, 0.0F, 0.0F, 1.0F);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        int GLModelWindow::handle(int event) {
            smskinedit::gui::glewInit(event, this); // okay to call every event
            return Fl_Gl_Window::handle(event);
        }
    }
}
