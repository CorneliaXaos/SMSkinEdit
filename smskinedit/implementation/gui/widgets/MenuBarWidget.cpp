#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>

#include "gui/widgets/MenuBarWidget.h"

namespace smskinedit {
    namespace gui {

        // Constructor
        MenuBarWidget::MenuBarWidget(int x, int y, int width, int height) :
                Fl_Menu_Bar{x, y, width, height} {

            // Create Menu
            _items[ 0] = {"File",            0, nullptr, nullptr, FL_SUBMENU,      0, 0, 0, 0};
            _items[ 1] = {"New",             0, nullptr, nullptr, 0,               0, 0, 0, 0};
            _items[ 2] = {"Open",            0, nullptr, nullptr, FL_MENU_DIVIDER, 0, 0, 0, 0};
            _items[ 3] = {"Save",            0, nullptr, nullptr, 0,               0, 0, 0, 0};
            _items[ 4] = {"Export",          0, nullptr, nullptr, FL_MENU_DIVIDER, 0, 0, 0, 0};
            _items[ 5] = {"Quit",            0, nullptr, nullptr, 0,               0, 0, 0, 0};
            _items[ 6] = {nullptr,           0, nullptr, nullptr, 0,               0, 0, 0, 0};
            _items[ 7] = {"Edit",            0, nullptr, nullptr, FL_SUBMENU,      0, 0, 0, 0};
            _items[ 8] = {"Internal Editor", 0, nullptr, nullptr, FL_MENU_TOGGLE,  0, 0, 0, 0};
            _items[ 9] = {nullptr,           0, nullptr, nullptr, 0,               0, 0, 0, 0};
            _items[10] = {"Lighting",        0, nullptr, nullptr, FL_SUBMENU,      0, 0, 0, 0};
            _items[11] = {"Flat",            0, nullptr, nullptr, FL_MENU_RADIO,   0, 0, 0, 0};
            _items[12] = {"Illuminated",     0, nullptr, nullptr, FL_MENU_RADIO,   0, 0, 0, 0};
            _items[13] = {"In Darkness",     0, nullptr, nullptr, FL_MENU_RADIO,   0, 0, 0, 0};
            _items[14] = {nullptr,           0, nullptr, nullptr, 0,               0, 0, 0, 0};
            menu(_items);

            _items[ 8].set();
            _items[11].setonly();
        }
        MenuBarWidget::~MenuBarWidget() {}

    }
}
