// A Very Simple Main..  Our goal.. :P

#include <FL/Fl.H>
#include <FL/Fl_File_Icon.H>

#include "gui/windows/MainWindow.h"
#include "gui/windows/subwindows/GLModelWindow.h"

using MainWindow = smskinedit::gui::MainWindow;

MainWindow* window = nullptr;

int main(int argc, char** argv) {
    Fl_File_Icon::load_system_icons();

    window = new MainWindow{};
    window->end();
    window->show(argc, argv);

    int ret = Fl::run();

    delete window;
    return ret;
}
