#ifndef SMSKINEDIT_GUI_MODELWINDOW_H
#define SMSKINEDIT_GUI_MODELWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

//! Forward declare Fl_Value_Slider
class Fl_Hor_Value_Slider;

namespace smskinedit {
    namespace gui {

        //! Forward declar GLModelWindow
        class GLModelWindow;

        /**
         *  @brief The Model Window
         *
         *  This window is used for rendering the model during the editing
         *  process.  It should grow to fill the entire screen when internal
         *  editing is disabled.
         */
        class ModelWindow : public Fl_Double_Window {

            public:
                //! Constructs the Model visualization window
                ModelWindow(int, int, int, int);
                ~ModelWindow();

                // No copying or moving
                ModelWindow(const ModelWindow&) = delete;
                ModelWindow& operator=(const ModelWindow&) = delete;
                ModelWindow(ModelWindow&&) = delete;
                ModelWindow& operator=(ModelWindow&&) = delete;

                //! FLTK Event Function
                int handle(int) override final;

            private:
                // ModelSelectorWidget* _selector;
                GLModelWindow* _modelWindow;
                Fl_Hor_Value_Slider* _onionSkinningSlider;
        };

    }
}

#endif // SMSKINEDIT_GUI_MODELWINDOW_H
