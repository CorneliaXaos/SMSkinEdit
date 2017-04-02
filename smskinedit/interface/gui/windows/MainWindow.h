#ifndef SMSKINEDIT_GUI_MAINWINDOW_H
#define SMSKINEDIT_GUI_MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

namespace smskinedit {
    namespace gui {

        /**
         *  @brief The Main window of our application.
         *
         *  Responsible for loading all components and initializing setups.
         */
        class MainWindow : public Fl_Double_Window {

            public:
                MainWindow();
                ~MainWindow();
            private:
                // None, atm
        };

    }
}

#endif // SMSKINEDIT_GUI_MAINWINDOW_H
