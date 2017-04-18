#include "cyMatrix.h"

#include "gl/helpers.h" // totally bad.. ruins the point of forward declaration

namespace smskinedit {
    namespace gl {

        namespace helpers {

            cy::Matrix4f getOrtho(float r, float l, float t, float b, float f,
                    float n) {
                cy::Matrix4f ret {};
                ret.Zero();

                ret[ 0] = 2 / (r - l);
                ret[ 5] = 2 / (t - b);
                ret[10] = -2 / (f - n);
                ret[12] = - (r + l) / (r - l);
                ret[13] = - (t + b) / (t - b);
                ret[14] = - (f + n) / (f - n);
                ret[15] = 1;

                return ret;
            }

        }

    }
}
