#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Hor_Value_Slider.H>

#include "gui/constants.h"
#include "gui/widgets/ModelSelectorWidget.h"
#include "gui/windows/ModelWindow.h"
#include "gui/windows/subwindows/GLModelWindow.h"

// Constants
const int ONION_SKINNING_LABEL_PADDING = 5;
const int ONION_SKINNING_LABEL_SIZE = 10;
const int ONION_SKINNING_LABEL_TOTAL = ONION_SKINNING_LABEL_PADDING +
        ONION_SKINNING_LABEL_SIZE;

namespace smskinedit {
    namespace gui {

        using namespace constants;

        // Constructors
        ModelWindow::ModelWindow(int x, int y, int width, int height) :
                Fl_Double_Window{x, y, width, height}, _selector(nullptr),
                _modelWindow(nullptr), _onionSkinningSlider(nullptr) {
            // Init self
            box(FL_THIN_DOWN_BOX);

            // Init _selector
            _selector = new ModelSelectorWidget{0, 0, width, ROW_HEIGHT()};

            // Init _modelWindow
            _modelWindow = new GLModelWindow{0, ROW_HEIGHT(), width,
                    height - 2 * ROW_HEIGHT() - ONION_SKINNING_LABEL_TOTAL};

            // Init _onionSkinningSlider
            _onionSkinningSlider = new Fl_Hor_Value_Slider{0,
                    height - ROW_HEIGHT() - ONION_SKINNING_LABEL_TOTAL, width,
                    ROW_HEIGHT(), "Template Onion Skinning"};
            _onionSkinningSlider->labelsize(ONION_SKINNING_LABEL_SIZE);
            _onionSkinningSlider->align(FL_ALIGN_BOTTOM);
            _onionSkinningSlider->visible_focus(false);
            _onionSkinningSlider->value(0.5);

            // Finish Up
            end();
        }
        ModelWindow::~ModelWindow() {
            if (_modelWindow) {
                delete _modelWindow;
                _modelWindow = nullptr;
            }
            if (_onionSkinningSlider) {
                delete _onionSkinningSlider;
                _onionSkinningSlider = nullptr;
            }
        }

        // FLTK Event Function
        int ModelWindow::handle(int event) {
            return Fl_Double_Window::handle(event);
        }

    }
}
