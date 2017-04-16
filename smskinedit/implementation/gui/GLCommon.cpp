#include <atomic>
#include <mutex>

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

#include "gui/GLCommon.h"

namespace smskinedit {
    namespace gui {

        void glewInit(int event, Fl_Gl_Window* window) {
            static std::atomic<bool> initialized {false};
            static std::mutex mutex{};
            if (initialized) return; // fast fail before synchronization

            std::lock_guard<std::mutex> lock {mutex};
            if (!initialized && event == FL_SHOW && window->shown()) {
                initialized = true;
                window->make_current();
                GLenum error = ::glewInit();
                if (error != GLEW_OK) {
                    Fl::warning("glewInit() failed returning %u", error);
                }
            }
        }

    }
}
