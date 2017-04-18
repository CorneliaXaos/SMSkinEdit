#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Hor_Value_Slider.H>
#include <FL/Fl_Widget.H>

#include "control/controls.h"
#include "gui/constants.h"
#include "gui/GLCommon.h"
#include "gui/widgets/ModelSelectorWidget.h"
#include "gui/windows/ModelWindow.h"
#include "gui/windows/subwindows/GLModelWindow.h"

// Constants
static const int ONION_SKINNING_LABEL_PADDING = 5;
static const int ONION_SKINNING_LABEL_SIZE = 10;
static const int ONION_SKINNING_LABEL_TOTAL = ONION_SKINNING_LABEL_PADDING +
        ONION_SKINNING_LABEL_SIZE;

// Namespace Shortenings
namespace controls = smskinedit::control::controls;

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
            smskinedit::gui::setContextWindow(_modelWindow);

            // Init _onionSkinningSlider
            _onionSkinningSlider = new Fl_Hor_Value_Slider{0,
                    height - ROW_HEIGHT() - ONION_SKINNING_LABEL_TOTAL, width,
                    ROW_HEIGHT(), "Template Onion Skinning"};
            _onionSkinningSlider->labelsize(ONION_SKINNING_LABEL_SIZE);
            _onionSkinningSlider->align(FL_ALIGN_BOTTOM);
            _onionSkinningSlider->visible_focus(false);
            _onionSkinningSlider->value(0.5);
            _onionSkinningSlider->callback([](Fl_Widget* widget, void*) {
                Fl_Hor_Value_Slider* slider =
                        reinterpret_cast<Fl_Hor_Value_Slider*>(widget);
                controls::templateControl.setOnionSkinningValue(
                        slider->value());
            }, nullptr);

            // Finish Up
            end();
        }
        ModelWindow::~ModelWindow() {
            smskinedit::gui::setContextWindow(nullptr);

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
