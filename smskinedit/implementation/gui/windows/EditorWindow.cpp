#include <FL/Fl.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Widget.H>

#include "control/controls.h"
#include "gui/constants.h"
#include "gui/widgets/ActiveColorWidget.h"
#include "gui/widgets/TextureSelectorWidget.h"
#include "gui/windows/EditorWindow.h"
#include "gui/windows/subwindows/GLTextureWindow.h"

// namespace Declaration
namespace controls = smskinedit::control::controls;

// constants
static const char* CALLBACK_ID = "EditorWindow";

namespace smskinedit {
    namespace gui {

        using namespace constants;

        // Constructors
        EditorWindow::EditorWindow(int x, int y, int width, int height) :
                Fl_Double_Window{x, y, width, height}, _colorChooser(nullptr),
                _activeColor(nullptr), _textureSelector(nullptr),
                _textureWindow(nullptr) {

            // Init self and helpers
            box(FL_THIN_DOWN_BOX);
            int chooserHeight = height - ROW_HEIGHT() * 3 - width;

            // Init _colorChooser
            _colorChooser = new Fl_Color_Chooser{0, 0, width, chooserHeight};
            _colorChooser->rgb(0.0, 0.0, 0.0);
            _colorChooser->callback([](Fl_Widget* widget, void*) {
                Fl_Color_Chooser* colorChooser =
                        reinterpret_cast<Fl_Color_Chooser*>(widget);
                unsigned int color =
                        (static_cast<int>(colorChooser->r() * 255) << 24) +
                        (static_cast<int>(colorChooser->g() * 255) << 16) +
                        (static_cast<int>(colorChooser->b() * 255) << 8);
                if (controls::colorControl.isForegroundSelected()) {
                    controls::colorControl.setForegroundColor(color);
                } else {
                    controls::colorControl.setBackgroundColor(color);
                }
            }, nullptr);

            // Init _activeColor
            _activeColor = new ActiveColorWidget{0, chooserHeight, width,
                    ROW_HEIGHT() * 2};

            // Init _textureSelector
            _textureSelector = new TextureSelectorWidget{0, chooserHeight +
                    ROW_HEIGHT() * 2, width, ROW_HEIGHT()};

            // Init _textureWindow
            _textureWindow = new GLTextureWindow{0, chooserHeight +
                    ROW_HEIGHT() * 3, width, width};

            // Add ColorChooser callback
            controls::colorControl.addCallback(CALLBACK_ID,
                    [&](smskinedit::control::EventFlag event) {
                if (event == ColorControl::SELECTION_CHANGED) {
                    Fl_Color color{};
                    if (controls::colorControl.isForegroundSelected()) {
                        color = controls::colorControl.getForegroundColor();
                    } else {
                        color = controls::colorControl.getBackgroundColor();
                    }
                    unsigned char r = 0, g = 0, b = 0;
                    Fl::get_color(color, r, g, b);
                    _colorChooser->rgb(r / 255.0F, g / 255.0F, b / 255.0F);
                }
            });

            // Finish Up
            end();
        }
        EditorWindow::~EditorWindow() {
            if (_colorChooser) {
                delete _colorChooser;
                _colorChooser = nullptr;
            }
            if (_activeColor) {
                delete _activeColor;
                _activeColor = nullptr;
            }
            if (_textureSelector) {
                delete _textureSelector;
                _textureSelector = nullptr;
            }
            if (_textureWindow) {
                delete _textureWindow;
                _textureWindow = nullptr;
            }
            controls::colorControl.removeCallback(CALLBACK_ID);
        }

        // FLTK Event Functions
        int EditorWindow::handle(int event) {
            return Fl_Double_Window::handle(event);
        }
    }
}
