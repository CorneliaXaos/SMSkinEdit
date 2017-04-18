#ifndef SMSKINEDIT_GL_HELPERS_H
#define SMSKINEDIT_GL_HELPERS_H

#include "cyMatrix.h"

namespace smskinedit {
    namespace gl {

        /**
         *  @brief This namespace contains some useful helper functions.
         */
        namespace helpers {

            //!  R,  L,  T,  B,  F,  N : Also:
            //! +X, -X, +Y, -Y, +Z, -Z
            cy::Matrix4f getOrtho(float, float, float, float, float, float);

        }

    }
}

#endif // SMSKINEDIT_GL_HELPERS_H
