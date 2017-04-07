#ifndef SMSKINEDIT_GUI_MODELSELECTORWIDGET_H
#define SMSKINEDIT_GUI_MODELSELECTORWIDGET_H

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>

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

                ModelSelectorWidget(const ModelSelectorWidget&) = delete;
                ModelSelectorWidget& operator=(const ModelSelectorWidget&)
                        = delete;
                ModelSelectorWidget(ModelSelectorWidget&&) = delete;
                ModelSelectorWidget& operator=(ModelSelectorWidget&&) = delete;

            private:
                Fl_Box* _selectorLabel;
                Fl_Round_Button* _radioButtonBody;
                Fl_Round_Button* _radioButtonHead;
                Fl_Round_Button* _radioButtonBoth;
        };

    }
}

#endif // SMSKINEDIT_GUI_MODELSELECTORWIDGET_H
