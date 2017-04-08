#ifndef SMSKINEDIT_GUI_GLTEXTUREWINDOW_H
#define SMSKINEDIT_GUI_GLTEXTUREWINDOW_H

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
         *  @brief A small, embeddable window for editing textures directly.
         *
         *  This window provides an interface for editing the textures directly
         *  on a flat surface as opposed to on the model itself.
         */
        class GLTextureWindow : public Fl_Gl_Window {

            public:
                //! Constructs the subwindow
                GLTextureWindow(int, int, int, int);
                ~GLTextureWindow();

                //! No copying or moving
                GLTextureWindow(const GLTextureWindow&) = delete;
                GLTextureWindow& operator==(const GLTextureWindow&) = delete;
                GLTextureWindow(GLTextureWindow&&) = delete;
                GLTextureWindow& operator=(GLTextureWindow&&) = delete;

                void draw() override final;
                int handle(int) override final;

            private:
                // None, atm
        };

    }
}

#endif // SMSKINEDIT_GUI_GLTEXTUREWINDOW_H
