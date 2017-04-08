#ifndef SMSKINEDIT_GUI_MODELSELECTORWIDGET_H
#define SMSKINEDIT_GUI_MODELSELECTORWIDGET_H

#include <FL/Fl.H>
#include <FL/Fl_Group.H>

//! Forward Declare Fl_Box
class Fl_Box;
//! Forward Declare Fl_Radio_Round_Button
class Fl_Radio_Round_Button;

namespace smskinedit {
    namespace gui {

        /**
         *  @brief The model selector bar that will be used to pick the active
         *  model.
         */
        class ModelSelectorWidget : public Fl_Group {

            public:
                //! Constructor
                ModelSelectorWidget(int, int, int, int);
                ~ModelSelectorWidget();

                //! No Copying or moving
                ModelSelectorWidget(const ModelSelectorWidget&) = delete;
                ModelSelectorWidget& operator=(const ModelSelectorWidget&)
                        = delete;
                ModelSelectorWidget(ModelSelectorWidget&&) = delete;
                ModelSelectorWidget& operator=(ModelSelectorWidget&&) = delete;

            private:
                Fl_Box* _selectorLabel;
                Fl_Radio_Round_Button* _radioButtonBody;
                Fl_Radio_Round_Button* _radioButtonHead;
                Fl_Radio_Round_Button* _radioButtonBoth;
        };

    }
}

#endif // SMSKINEDIT_GUI_MODELSELECTORWIDGET_H
