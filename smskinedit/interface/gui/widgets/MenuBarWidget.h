#ifndef SMSKINEDIT_GUI_MENUBARWIDGET_H
#define SMSKINEDIT_GUI_MENUBARWIDGET_H

#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>

//! Forward Declare Fl_Menu_Item
class Fl_Menu_Item;

namespace smskinedit {
    namespace gui {

        class MenuBarWidget : public Fl_Menu_Bar {

            public:
                //! Constructor
                MenuBarWidget(int, int, int, int);
                ~MenuBarWidget();

                MenuBarWidget(const MenuBarWidget&) = delete;
                MenuBarWidget& operator=(const MenuBarWidget&) = delete;
                MenuBarWidget(MenuBarWidget&&) = delete;
                MenuBarWidget& operator=(MenuBarWidget&&) = delete;

                // TODO - enums and callback setters
            private:
                Fl_Menu_Item items[15];
        };

    }
}

#endif // SMSKINEDIT_GUI_MENUBARWIDGET_H
