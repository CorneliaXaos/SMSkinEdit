#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

#include "gui/constants.h"
#include "gui/windows/MainWindow.h"
#include "gui/windows/ModelWindow.h"

// Constants
const int WIDTH = 1280;
const int HEIGHT = 720;
const char* TITLE = "StarMade Skin Editor";

namespace smskinedit {
    namespace gui {

        using namespace constants;

        // Constructors / Destructor
        MainWindow::MainWindow() : Fl_Double_Window{APPLICATION_WIDTH(),
                APPLICATION_HEIGHT(), APPLICATION_TITLE},
                _modelWindow(nullptr) {
            //// Init _menuBar


            //// Init _modelWindow
            _modelWindow = new ModelWindow{0, ROW_HEIGHT(),
                    MODEL_WINDOW_WIDTH(),
                    APPLICATION_HEIGHT() - ROW_HEIGHT()};

            //// Init _editorWindow


            //// Finish Up
            end();
        }
        MainWindow::~MainWindow() {
            if (_modelWindow) {
                delete _modelWindow;
                _modelWindow = nullptr;
            }
        }

    }
}
