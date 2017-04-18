#ifndef SMSKINEDIT_GL_SHAREDTEXTURES_H
#define SMSKINEDIT_GL_SHAREDTEXTURES_H

#include <string>

#include <FL/gl.H>
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
            extern GLRenderTexture bodyDiffuse {};
            extern GLRenderTexture bodyEmissive {};
            extern GLRenderTexture helmDiffuse {};
            extern GLRenderTextuer helmEmissive {};

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
