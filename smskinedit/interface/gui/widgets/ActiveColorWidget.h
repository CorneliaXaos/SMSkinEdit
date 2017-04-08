#ifndef SMSKINEDIT_GUI_ACTIVECOLORWIDGET_H
#define SMSKINEDIT_GUI_ACTIVECOLORWIDGET_H

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

//! Forward Declare Fl_Radio_Button
class Fl_Radio_Button;

namespace smskinedit {
    namespace gui {

        /**
         *  @brief A Color selector widget.  Allows the user to select between
         *  foreground and background colors.
         */
        class ActiveColorWidget : public Fl_Group {

            public:
                //! Constructor
                ActiveColorWidget(int, int, int, int);
                ~ActiveColorWidget();

                //! No Copying or moving
                ActiveColorWidget(const ActiveColorWidget&) = delete;
                ActiveColorWidget& operator=(const ActiveColorWidget&) = delete;
                ActiveColorWidget(ActiveColorWidget&&) = delete;
                ActiveColorWidget& operator=(ActiveColorWidget&&) = delete;

            private:
                Fl_Radio_Button* _foregroundButton;
                Fl_Radio_Button* _backgroundButton;
        };

    }
}

#endif // SMSKINEDIT_GUI_ACTIVECOLORWIDGET_H
