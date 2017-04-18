#ifndef SMSKINEDIT_GL_SHAREDTEXTURES_H
#define SMSKINEDIT_GL_SHAREDTEXTURES_H

#include <string>

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
         *  @brief This namespace is utilized to hold textures used by both
         *  Fl_Gl_Windows in the application.
         *
         *  Specifically, this namespace will hold RenderBuffers that will
         *  contain the skin images loaded within.  They can be used for writing
         *  or for reading and displaying the textures in either Fl_Gl_Window
         */
        namespace textures {

            //! The textures
            extern cy::GLRenderTexture<GL_TEXTURE_2D> bodyDiffuse;
            extern cy::GLRenderTexture<GL_TEXTURE_2D> bodyEmissive;
            extern cy::GLRenderTexture<GL_TEXTURE_2D> helmDiffuse;
            extern cy::GLRenderTexture<GL_TEXTURE_2D> helmEmissive;
            extern cy::GLRenderTexture<GL_TEXTURE_2D> bodyTemplate;
            extern cy::GLRenderTexture<GL_TEXTURE_2D> helmTemplate;

            //! Returns true if all the RenderTextures are initialized
            bool texturesReady();

            //! Loads the textures from the specified directory
            bool loadTextures(std::string);
            //! Saves the textures to the specified directory
            bool saveTextures(std::string);
        }

    }
}

#endif // SMSKINEDIT_GL_SHAREDTEXTURES_H
