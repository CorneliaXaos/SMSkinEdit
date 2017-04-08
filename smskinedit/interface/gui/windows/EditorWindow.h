#ifndef SMSKINEDIT_GUI_EDITORWINDOW_H
#define SMSKINEDIT_GUI_EDITORWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

//! Forward Declare Fl_Color_Chooser
class Fl_Color_Chooser;

namespace smskinedit {
    namespace gui {

        //! Forward declare ActiveColorWidget
        class ActiveColorWidget;
        //! Forward declare TextureSelectorWidget
        class TextureSelectorWidget;
        //! Forward declare GLTextureWindow
        class GLTextureWindow;

        /**
         *  @brief The Editor Window
         *  This window is used for providing internal editor controls to the
         *  user.  It should vanish from view when the user disables the
         *  internal editor.
         */
        class EditorWindow : public Fl_Double_Window {

            public:
                //! Constructs the editor window
                EditorWindow(int, int, int, int);
                ~EditorWindow();

                //! No coyping or moving
                EditorWindow(const EditorWindow&) = delete;
                EditorWindow& operator=(const EditorWindow&) = delete;
                EditorWindow(EditorWindow&&) = delete;
                EditorWindow& operator=(EditorWindow&&) = delete;

                //! FLTK Event Function
                int handle(int) override final;

            private:
                Fl_Color_Chooser* _colorChooser;
                ActiveColorWidget* _activeColor;
                TextureSelectorWidget* _textureSelector;
                GLTextureWindow* _textureWindow;
        };

    }
}

#endif // SMSKINEDIT_GUI_EDITORWINDOW_H
