#ifndef SMSKINEDIT_GUI_GLCOMMON_H
#define SMSKINEDIT_GUI_GLCOMMON_H

#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>

namespace smskinedit {
    namespace gui {

        //! Sets up GLEW for the application
        void glewInit(int, Fl_Gl_Window*);

        //! Sets the window pointer to use as the context for OpenGL executed
        //! outside of an Fl_Gl_Window
        void setContextWindow(Fl_Gl_Window*);
        //! Activates the context, if any
        bool activateContext();

    }
}

#endif // SMSKINEDIT_GUI_GLCOMMON_H
