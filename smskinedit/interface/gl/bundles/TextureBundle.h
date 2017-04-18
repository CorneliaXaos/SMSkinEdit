#ifndef SMSKINEDIT_GL_TEXTUREBUNDLE_H
#define SMSKINEDIT_GL_TEXTUREBUNDLE_H

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

namespace smskinedit {
    namespace gl {

        /**
         *  @brief Encapsulates a cy::GLSLProgram to render a texture to a
         *  quad to the screen orthographically.
         *
         *  This program assumes it's being executed inside of an active
         *  context.
         */
        class TextureBundle {

            public:
                TextureBundle();
                ~TextureBundle();

                TextureBundle(const TextureBundle&) = delete;
                TextureBundle& operator=(const TextureBundle&) = delete;
                TextureBundle(TextureBundle&&) = delete;
                TextureBundle& operator=(TextureBundle&&) = delete;

                //! Runs this program
                void render();

                //! Sets the Uniforms!
                void setTemplateTextureUnit(int);
                void setActualTextureUnit(int);
                void setAlphaLevel(float);

            private:
                cy::GLSLShader _vertex {};
                cy::GLSLShader _fragment {};
                cy::GLSLProgram _program {};

                GLuint VAO = GL_ZERO;
                GLuint VBO[2] = {GL_ZERO, GL_ZERO};
        };

    }
}

#endif // SMSKINEDIT_GL_TEXTUREBUNDLE_H
