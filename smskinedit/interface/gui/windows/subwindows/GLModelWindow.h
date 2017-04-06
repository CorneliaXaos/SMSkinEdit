#ifndef SMSKINEDIT_GUI_GL_MODELWINDOW_H
#define SMSKINEDIT_GUI_GL_MODELWINDOW_H

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


namespace smskinedit {
    namespace gui {

        /**
         *  Represents the portion of the ModelWindow that is an OpenGL program.
         *  This class simply redirects events into and controls the drawing
         *  of the OpenGL.
         */
        class GLModelWindow : public Fl_Gl_Window {

            public:
                //! Constructs the subwindow
                GLModelWindow(int, int, int, int);
                ~GLModelWindow();

                //! No copying and moving
                GLModelWindow(const GLModelWindow&) = delete;
                GLModelWindow& operator=(const GLModelWindow&) = delete;
                GLModelWindow(GLModelWindow&&) = delete;
                GLModelWindow& operator=(GLModelWindow&&) = delete;

                void draw() override final;
                int handle(int) override final;

            private:
                // None, atm

        };

    }
}

#endif // SMSKINEDIT_GUI_GL_MODELWINDOW_H
