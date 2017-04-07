#ifndef SMSKINEDIT_GUI_MAINWINDOW_H
#define SMSKINEDIT_GUI_MAINWINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>

namespace smskinedit {
    namespace gui {

        //! Forward Declare MenuBarWidget
        class MenuBarWidget;
        //! Forward Declare ModeWindow
        class ModelWindow;

        /**
         *  @brief The Main window of our application.
         *
         *  Responsible for loading all components and initializing setups.
         */
        class MainWindow : public Fl_Double_Window {

            public:
                //! Constructs a MainWindow
                MainWindow();
                ~MainWindow();
            private:
                MenuBarWidget* _menuBar;
                ModelWindow* _modelWindow;
                // EditorWindow* _editorWindow;

        };

    }
}

#endif // SMSKINEDIT_GUI_MAINWINDOW_H
