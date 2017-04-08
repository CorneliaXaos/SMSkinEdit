#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Radio_Round_Button.H>

#include "gui/widgets/TextureSelectorWidget.h"

// Constants
const char* selectedBody = "B";
const char* selectedHead = "H";
const char* labelDiffuse = "Diffuse";
const char* labelEmissive = "Emissive";

namespace smskinedit {
    namespace gui {

        // Constructor
        TextureSelectorWidget::TextureSelectorWidget(int x, int y, int width,
                int height) : Fl_Group{x, y, width, height},
                _toggleButton(nullptr), _radioButtonDiffuse(nullptr),
                _radioButtonEmissive(nullptr) {

            // Init self & helpers
            box(FL_THIN_DOWN_BOX);
            int childWidth = (width - height) / 2;

            // Init _toggleButton
            _toggleButton = new Fl_Button{x, y, height, height, selectedBody};
            _toggleButton->visible_focus(false);

            // Init _radioButtonDiffuse
            _radioButtonDiffuse = new Fl_Radio_Round_Button{x + height, y,
                    childWidth, height, labelDiffuse};
            _radioButtonDiffuse->visible_focus(false);
            _radioButtonDiffuse->box(FL_THIN_DOWN_BOX);
            _radioButtonDiffuse->setonly();

            // Init _radioButtonEmissive
            _radioButtonEmissive = new Fl_Radio_Round_Button{x + height
                    + childWidth, y, childWidth, height, labelEmissive};
            _radioButtonEmissive->visible_focus(false);
            _radioButtonEmissive->box(FL_THIN_DOWN_BOX);

            // Finish Up
            end();
        }
        TextureSelectorWidget::~TextureSelectorWidget() {
            if (_toggleButton) {
                delete _toggleButton;
                _toggleButton = nullptr;
            }
            if (_radioButtonDiffuse) {
                delete _radioButtonDiffuse;
                _radioButtonDiffuse = nullptr;
            }
            if (_radioButtonEmissive) {
                delete _radioButtonEmissive;
                _radioButtonEmissive = nullptr;
            }
        }
    }
}
