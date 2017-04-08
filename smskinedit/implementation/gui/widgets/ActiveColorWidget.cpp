#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Radio_Button.H>

#include "gui/widgets/ActiveColorWidget.h"

// Constants
const char* labelFG = "Foreground";
const char* labelBG = "Background";

namespace smskinedit {
    namespace gui {

        // Constructor
        ActiveColorWidget::ActiveColorWidget(int x, int y, int width,
                int height) : Fl_Group{x, y, width, height},
                _foregroundButton(nullptr), _backgroundButton(nullptr) {

            // Init self & helpers
            box(FL_THIN_DOWN_BOX);
            int buttonWidth = static_cast<int>(width * 1.0 / 3.0);
            int spaceWidth = static_cast<int>(width * 1.0 / 9.0);
            int buttonHeight = height / 2;
            int spaceAbove = static_cast<int>(buttonHeight * 0.3);
            int spaceBelow = buttonHeight - spaceAbove;

            // Init _foregroundButton
            _foregroundButton = new Fl_Radio_Button{x + spaceWidth,
                    y + spaceAbove, buttonWidth, buttonHeight, labelFG};
            _foregroundButton->color(0xFFFF0000, 0xFFFF0000);
            _foregroundButton->align(FL_ALIGN_BOTTOM);
            _foregroundButton->visible_focus(false);

            // Init _backgroundButton
            _backgroundButton = new Fl_Radio_Button{x + 2 * spaceWidth
                    + buttonWidth, y + spaceAbove, buttonWidth, buttonHeight,
                    labelBG};
            _backgroundButton->color(0x00FFFF00, 0x00FFFF00);
            _backgroundButton->align(FL_ALIGN_BOTTOM);
            _backgroundButton->visible_focus(false);

            // Finish Up
            _foregroundButton->setonly();
            end();
        }
        ActiveColorWidget::~ActiveColorWidget() {
            if (_foregroundButton) {
                delete _foregroundButton;
                _foregroundButton = nullptr;
            }
            if (_backgroundButton) {
                delete _backgroundButton;
                _backgroundButton = nullptr;
            }
        }

    }
}
