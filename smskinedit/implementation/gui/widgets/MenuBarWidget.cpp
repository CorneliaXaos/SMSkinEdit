#include <cassert>
#include <cstdint>
#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Widget.H>

#include "control/controls.h"
#include "control/impl/FileControl.h"
#include "enums.h"
#include "gui/widgets/MenuBarWidget.h"
#include "main.h"

// Constants
static const char* NEW_DIRECTORY = "Choose a New Save Directory";
static const char* OPEN_DIRECTORY = "Choose an Existing Save Directory";
static const char* CALLBACK_ID = "MenuBarWidget";

// Using declarations
using EventFlag = smskinedit::control::EventFlag;
using FileControl = smskinedit::control::FileControl;
using LightingType = smskinedit::enums::LightingType;

// Namespace shortenings
namespace controls = smskinedit::control::controls;

namespace smskinedit {
    namespace gui {

        // FileChooser Function
        struct FileResult {
            std::string path {""};
            bool valid = false;
        };
        static FileResult chooseDirectory(const char* title,
                Fl_Native_File_Chooser::Type type) {
            Fl_Native_File_Chooser chooser {};
            chooser.title(title);
            chooser.type(type);
            chooser.options(Fl_Native_File_Chooser::NEW_FOLDER |
                    Fl_Native_File_Chooser::PREVIEW |
                    Fl_Native_File_Chooser::SAVEAS_CONFIRM);

            FileResult result {};
            switch (chooser.show()) {
                case -1:
                case 1:
                    break;
                default:
                    if (chooser.filename()) {
                        result.path = std::string(chooser.filename());
                        result.valid = true;
                    }
                    break;
            }
            return result;
        }

        // Callbacks
        static void NewCallback(Fl_Widget*, void*) {
            FileResult result = chooseDirectory(NEW_DIRECTORY,
                    Fl_Native_File_Chooser::BROWSE_SAVE_DIRECTORY);
            if (result.valid) {
                // copy blank files to directory of choice

                // todo pending image management
            }
        }
        static void OpenCallback(Fl_Widget*, void*) {
            FileResult result = chooseDirectory(OPEN_DIRECTORY,
                    Fl_Native_File_Chooser::BROWSE_DIRECTORY);
            if (result.valid) {
                // check to make sure directory contains the files we need

                // todo pending image management
            }
        }
        static void SaveCallback(Fl_Widget*, void*) {
            // todo pending image management
        }
        static void ExportCallback(Fl_Widget*, void*) {
            // todo pending future :P
        }
        static void QuitCallback(Fl_Widget*, void*) {
            if (controls::fileControl.isFileModified()) {
                // display a window asking if you want to save first
                // if (/* should save code */) {
                //     SaveCallback(nullptr, nullptr);
                // }
            }
            window->hide();
        }

        static void InternalEditorCallback(Fl_Widget*, void*) {
            bool internal = controls::editorControl.shouldUseInternalEditor();
            controls::editorControl.setUseInternalEditor(!internal);
        }
        static void LightingCallback(Fl_Widget*, void* which) {
            uintptr_t target = reinterpret_cast<uintptr_t>(which);
            assert(target >= uintptr_t{0} && target <= uintptr_t{2});

            LightingType type = LightingType::FLAT;
            switch(target) {
                default:
                case uintptr_t{0}:
                    type = LightingType::FLAT;
                    break;
                case uintptr_t{1}:
                    type = LightingType::ILLUMINATED;
                    break;
                case uintptr_t{2}:
                    type = LightingType::IN_DARKNESS;
                    break;
            }

            controls::lightingControl.setLightingType(type);
        }

        // Constructor
        MenuBarWidget::MenuBarWidget(int x, int y, int width, int height) :
                Fl_Menu_Bar{x, y, width, height} {

            // Create Menu
            _items[ 0] = {"File",            0, nullptr,                nullptr,                               FL_SUBMENU,                         0, 0, 0, 0};
            _items[ 1] = {"New",             0, NewCallback,            nullptr,                               0,                                  0, 0, 0, 0};
            _items[ 2] = {"Open",            0, OpenCallback,           nullptr,                               FL_MENU_DIVIDER,                    0, 0, 0, 0};
            _items[ 3] = {"Save",            0, SaveCallback,           nullptr,                               FL_MENU_INACTIVE,                   0, 0, 0, 0};
            _items[ 4] = {"Export",          0, ExportCallback,         nullptr,                               FL_MENU_DIVIDER | FL_MENU_INACTIVE, 0, 0, 0, 0};
            _items[ 5] = {"Quit",            0, QuitCallback,           nullptr,                               0,                                  0, 0, 0, 0};
            _items[ 6] = {nullptr,           0, nullptr,                nullptr,                               0,                                  0, 0, 0, 0};
            _items[ 7] = {"Edit",            0, nullptr,                nullptr,                               FL_SUBMENU,                         0, 0, 0, 0};
            _items[ 8] = {"Internal Editor", 0, InternalEditorCallback, nullptr,                               FL_MENU_TOGGLE | FL_MENU_INACTIVE,  0, 0, 0, 0};
            _items[ 9] = {nullptr,           0, nullptr,                nullptr,                               0,                                  0, 0, 0, 0};
            _items[10] = {"Lighting",        0, nullptr,                nullptr,                               FL_SUBMENU,                         0, 0, 0, 0};
            _items[11] = {"Flat",            0, LightingCallback,       reinterpret_cast<void*>(uintptr_t{0}), FL_MENU_RADIO,                      0, 0, 0, 0};
            _items[12] = {"Illuminated",     0, LightingCallback,       reinterpret_cast<void*>(uintptr_t{1}), FL_MENU_RADIO,                      0, 0, 0, 0};
            _items[13] = {"In Darkness",     0, LightingCallback,       reinterpret_cast<void*>(uintptr_t{2}), FL_MENU_RADIO,                      0, 0, 0, 0};
            _items[14] = {nullptr,           0, nullptr,                nullptr,                               0,                                  0, 0, 0, 0};
            _items[15] = {nullptr,           0, nullptr,                nullptr,                               0,                                  0, 0, 0, 0};
            menu(_items);

            _items[ 8].set();
            _items[11].setonly();

            controls::fileControl.addCallback(CALLBACK_ID, [&](EventFlag flag) {
                if (flag == FileControl::FILE_MODIFIED) {
                    if (controls::fileControl.isFileModified()) {
                        _items[3].activate(); // turn on saving option
                    } else {
                        _items[3].deactivate(); // turn saving off
                    }
                }
            });
        }
        MenuBarWidget::~MenuBarWidget() {}

    }
}
