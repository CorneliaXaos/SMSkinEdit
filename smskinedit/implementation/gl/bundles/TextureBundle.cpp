#if defined(__APPLE__)
    #include <OpenGL/gl3.h> // defines OpenGL 3.0+ functions
#else
    #if defined(WIN32)
        #define GLEW_STATIC 1
    #endif
    #include <GL/glew.h>
#endif
#include <FL/gl.h>
#include "cyGL.h"
#include "cyPoint.h"

#include "gl/bundles/TextureBundle.h"
#include "gl/helpers.h"

namespace helpers = smskinedit::gl::helpers;

// Constants
static const char* VERTEX_SHADER =
        "SMSkinEdit_Data/Shaders/editor/texture.vert";
static const char* FRAGMENT_SHADER =
        "SMSkinEdit_Data/Shaders/editor/texture.frag";

static const int UNIFORM_MODEL_TRANSFORM = 0;
static const int UNIFORM_TEMPLATE_TEX = 1;
static const int UNIFORM_ACTUAL_TEX = 2;
static const int UNIFORM_ALPHA = 3;

static const int VERTEX_POSITION = 0;
static const int UVS_POSITION = 1;

static const cy::Point3f VERTICES[6] = {
    cy::Point3f{-1, -1, 0},
    cy::Point3f{ 1, -1, 0},
    cy::Point3f{-1,  1, 0},
    cy::Point3f{ 1,  1, 0},
    cy::Point3f{-1,  1, 0},
    cy::Point3f{ 1, -1, 0}
};
static const cy::Point2f UVS[6] = {
    cy::Point2f{0, 0},
    cy::Point2f{1, 0},
    cy::Point2f{0, 1},
    cy::Point2f{1, 1},
    cy::Point2f{0, 1},
    cy::Point2f{1, 0}
};

namespace smskinedit {
    namespace gl {

        // Constructor / Destructor
        TextureBundle::TextureBundle() {
            // Set up GLSL Stuffs
            _vertex.CompileFile(VERTEX_SHADER, GL_VERTEX_SHADER);
            _fragment.CompileFile(FRAGMENT_SHADER, GL_FRAGMENT_SHADER);

            _program.CreateProgram();
            _program.AttachShader(_vertex);
            _program.AttachShader(_fragment);
            _program.Link();

            // Register Uniforms
            _program.RegisterUniform(UNIFORM_MODEL_TRANSFORM, "modelTransform");
            _program.RegisterUniform(UNIFORM_TEMPLATE_TEX, "templateTex");
            _program.RegisterUniform(UNIFORM_ACTUAL_TEX, "actualTex");
            _program.RegisterUniform(UNIFORM_ALPHA, "alpha");

            // Set up Quad
            glGenVertexArrays(1, &VAO);
            glBindVertexArray(VAO);

            glGenBuffers(2, VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(cy::Point3f) * 6, VERTICES,
                    GL_STATIC_DRAW);
            glEnableVertexAttribArray(VERTEX_POSITION);
            glVertexAttribPointer(VERTEX_POSITION, 3, GL_FLOAT, GL_FALSE, 0,
                    nullptr);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(cy::Point2f) * 6, UVS,
                    GL_STATIC_DRAW);
            glEnableVertexAttribArray(UVS_POSITION);
            glVertexAttribPointer(UVS_POSITION, 2, GL_FLOAT, GL_FALSE, 0,
                    nullptr);

            glBindBuffer(GL_ARRAY_BUFFER, GL_ZERO);
            glBindVertexArray(GL_ZERO);
        }
        TextureBundle::~TextureBundle() {
            glDeleteVertexArrays(1, &VAO);
            glDeleteBuffers(2, VBO);
        }

        // Render
        void TextureBundle::render() {
            _program.Bind();

            // Orthographic projection Matrix!
            auto ortho = helpers::getOrtho(1, -1, 1, -1, 1, -1);
            _program.SetUniformMatrix4(UNIFORM_MODEL_TRANSFORM, ortho.data);

            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 6 * 3);
            glBindVertexArray(GL_ZERO);
        }

        // Uniforms
        void TextureBundle::setTemplateTextureUnit(int unit) {
            _program.Bind();
            _program.SetUniform(UNIFORM_TEMPLATE_TEX, unit);
        }
        void TextureBundle::setActualTextureUnit(int unit) {
            _program.Bind();
            _program.SetUniform(UNIFORM_ACTUAL_TEX, unit);
        }
        void TextureBundle::setAlphaLevel(float alpha) {
            _program.Bind();
            _program.SetUniform(UNIFORM_ALPHA, alpha);
        }
    }
}
