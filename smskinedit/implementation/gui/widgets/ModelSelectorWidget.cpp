#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Radio_Round_Button.H>

#include "gui/widgets/ModelSelectorWidget.h"

// Constants
const char* labelTag = "Model:\t";
const char* labelBody = "Body";
const char* labelHead = "Head";
const char* labelBoth = "Both";

namespace smskinedit {
    namespace gui {

        // Constructor
        ModelSelectorWidget::ModelSelectorWidget(int x, int y, int width,
                int height) : Fl_Group{x, y, width, height},
                _selectorLabel(nullptr), _radioButtonBody(nullptr),
                _radioButtonHead(nullptr), _radioButtonBoth(nullptr) {

            // Init self & helpers
            box(FL_THIN_DOWN_BOX);

            int childWidth = width / 4;

            // Init _selectorLabel
            _selectorLabel = new Fl_Box{x, y, childWidth, height, labelTag};
            _selectorLabel->box(FL_NO_BOX);
            _selectorLabel->align(FL_ALIGN_INSIDE | FL_ALIGN_RIGHT);

            // Init _radioButtonBody
            _radioButtonBody = new Fl_Radio_Round_Button{x + childWidth, y,
                    childWidth, height, labelBody};
            _radioButtonBody->visible_focus(false);
            _radioButtonBody->box(FL_THIN_DOWN_BOX);
            _radioButtonBody->setonly();

            // Init _radioButtonHead
            _radioButtonHead = new Fl_Radio_Round_Button{x + childWidth * 2, y,
                    childWidth, height, labelHead};
            _radioButtonHead->visible_focus(false);
            _radioButtonHead->box(FL_THIN_DOWN_BOX);

            // Init _radioButtonBoth
            _radioButtonBoth = new Fl_Radio_Round_Button{x + childWidth * 3, y,
                    childWidth, height, labelBoth};
            _radioButtonBoth->visible_focus(false);
            _radioButtonBoth->box(FL_THIN_DOWN_BOX);

            // Finish Up
            end();
        }
        ModelSelectorWidget::~ModelSelectorWidget() {
            if (_selectorLabel) {
                delete _selectorLabel;
                _selectorLabel = nullptr;
            }
            if (_radioButtonBody) {
                delete _radioButtonBody;
                _radioButtonBody = nullptr;
            }
            if (_radioButtonHead) {
                delete _radioButtonHead;
                _radioButtonHead = nullptr;
            }
            if (_radioButtonBoth) {
                delete _radioButtonBoth;
                _radioButtonBoth = nullptr;
            }
        }
    }
}
