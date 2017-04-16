#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Widget.H>

#include "control/controls.h"
#include "gui/widgets/ActiveColorWidget.h"

// Constants
static const char* labelFG = "Foreground";
static const char* labelBG = "Background";
static const char* CALLBACK_ID = "ActiveColorWidget";

// Using Declarations
using EventFlag = smskinedit::control::EventFlag;

// Namespace Shortenings
namespace controls = smskinedit::control::controls;

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

            // Init _foregroundButton
            _foregroundButton = new Fl_Radio_Button{x + spaceWidth,
                    y + spaceAbove, buttonWidth, buttonHeight, labelFG};
            _foregroundButton->color(0x00000000, 0x00000000);
            _foregroundButton->align(FL_ALIGN_BOTTOM);
            _foregroundButton->visible_focus(false);
            _foregroundButton->callback([](Fl_Widget*, void*) {
                controls::colorControl.setForegroundSelected(true);
            }, nullptr);

            // Init _backgroundButton
            _backgroundButton = new Fl_Radio_Button{x + 2 * spaceWidth
                    + buttonWidth, y + spaceAbove, buttonWidth, buttonHeight,
                    labelBG};
            _backgroundButton->color(0xFFFFFF00, 0xFFFFFF00);
            _backgroundButton->align(FL_ALIGN_BOTTOM);
            _backgroundButton->visible_focus(false);
            _backgroundButton->callback([](Fl_Widget*, void*) {
                controls::colorControl.setForegroundSelected(false);
            }, nullptr);

            // Attach ColorControl callbacks
            controls::colorControl.addCallback(CALLBACK_ID,
                    [&](smskinedit::control::EventFlag) { // ignore event
                auto fgColor = controls::colorControl.getForegroundColor();
                auto bgColor = controls::colorControl.getBackgroundColor();
                _foregroundButton->color(fgColor, fgColor);
                _backgroundButton->color(bgColor, bgColor);
                this->redraw();
            });

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
            controls::colorControl.removeCallback(CALLBACK_ID);
        }

    }
}
