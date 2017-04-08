#include <FL/Fl.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Double_Window.H>

#include "gui/constants.h"
#include "gui/widgets/ActiveColorWidget.h"
#include "gui/widgets/TextureSelectorWidget.h"
#include "gui/windows/EditorWindow.h"
#include "gui/windows/subwindows/GLTextureWindow.h"

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
            _colorChooser->rgb(1.0, 1.0, 1.0);

            // Init _activeColor
            _activeColor = new ActiveColorWidget{0, chooserHeight, width,
                    ROW_HEIGHT() * 2};

            // Init _textureSelector
            _textureSelector = new TextureSelectorWidget{0, chooserHeight +
                    ROW_HEIGHT() * 2, width, ROW_HEIGHT()};

            // Init _textureWindow
            _textureWindow = new GLTextureWindow{0, chooserHeight +
                    ROW_HEIGHT() * 3, width, width};

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
        }

        // FLTK Event Functions
        int EditorWindow::handle(int event) {
            return Fl_Double_Window::handle(event);
        }
    }
}
