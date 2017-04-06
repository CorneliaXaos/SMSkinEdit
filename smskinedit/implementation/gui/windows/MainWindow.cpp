#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

#include "gui/windows/MainWindow.h"

// Constants
const int WIDTH = 1280;
const int HEIGHT = 720;
const char* TITLE = "StarMade Skin Editor";

namespace smskinedit {
    namespace gui {

        // Constructors / Destructor
        MainWindow::MainWindow() : Fl_Double_Window{WIDTH, HEIGHT, TITLE} {}
        MainWindow::~MainWindow() {}

    }
}
