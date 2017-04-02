// A Very Simple Main..  Our goal.. :P

#include <FL/Fl.H>

#include "gui/windows/MainWindow.h"

using MainWindow = smskinedit::gui::MainWindow;

int main(int argc, char** argv) {
    MainWindow* window = new MainWindow{};
    window->end();
    window->show(argc, argv);

    int ret = Fl::run();

    delete window;
    return ret;
}
