#ifndef SMSKINEDIT_GUI_CONSTANTS_H
#define SMSKINEDIT_GUI_CONSTANTS_H

#include <cmath>

namespace smskinedit {
    namespace gui {
        namespace constants {

            //! The application's title
            constexpr const char* APPLICATION_TITLE = "StarMade Skin Editor";

            //! The total width of the application window
            constexpr const int APPLICATION_WIDTH() {
                return 1280;
            }
            //! The total height of the application window
            constexpr const int APPLICATION_HEIGHT() {
                return 720;
            }

            //! The width of any "row-like" widgets
            constexpr int ROW_HEIGHT() {
                return static_cast<int>(
                        std::floor(1.0 / 24.0 * APPLICATION_HEIGHT()));
            }

            //! The width of the model visualizer window when internal editing
            //! is enabled.
            constexpr int MODEL_WINDOW_WIDTH() {
                return static_cast<int>(
                        std::floor(3.0 / 4.0 * APPLICATION_WIDTH()));
            }
            //! The width of the editor window whne internal editing is
            //! enabled.
            constexpr int EDITOR_WINDOW_WIDTH() {
                return APPLICATION_WIDTH() - MODEL_WINDOW_WIDTH();
            }
        }
    }
}

#endif // SMSKINEDIT_GUI_CONSTANTS_H
