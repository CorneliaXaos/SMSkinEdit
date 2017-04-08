#ifndef SMSKINEDIT_GUI_TEXTURESELECTORWIDGET_H
#define SMSKINEDIT_GUI_TEXTURESELECTORWIDGET_H

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

//! Forward Declare Fl_Button
class Fl_Button;
//! Forward Declare Fl_Radio_Round_Button
class Fl_Radio_Round_Button;

namespace smskinedit {
    namespace gui {

        /**
         *  @brief The texture selector bar that will be used to select which
         *  texture the user is editing.
         */
        class TextureSelectorWidget : public Fl_Group {

            public:
                //! Constructor
                TextureSelectorWidget(int, int, int, int);
                ~TextureSelectorWidget();

                //! No copying nor moving
                TextureSelectorWidget(const TextureSelectorWidget&) = delete;
                TextureSelectorWidget& operator=(const TextureSelectorWidget&)
                        = delete;
                TextureSelectorWidget(TextureSelectorWidget&&) = delete;
                TextureSelectorWidget& operator=(TextureSelectorWidget&&)
                        = delete;

            private:
                Fl_Button* _toggleButton;
                Fl_Radio_Round_Button* _radioButtonDiffuse;
                Fl_Radio_Round_Button* _radioButtonEmissive;
        };

    }
}

#endif // SMSKINEDIT_GUI_TEXTURESELECTORWIDGET_H
