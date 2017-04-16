#include "control/impl/ColorControl.h"

namespace smskinedit {
    namespace control {

        void ColorControl::setForegroundColor(unsigned int color) {
            _fgColor = color;
            onControlUpdated(ColorControl::FOREGROUND_SET);
        }
        unsigned int ColorControl::getForegroundColor() const {
            return _fgColor;
        }

        void ColorControl::setBackgroundColor(unsigned int color) {
            _bgColor = color;
            onControlUpdated(ColorControl::BACKGROUND_SET);
        }
        unsigned int ColorControl::getBackgroundColor() const {
            return _bgColor;
        }

        void ColorControl::setForegroundSelected(bool selected) {
            _fgSelected = selected;
            onControlUpdated(ColorControl::SELECTION_CHANGED);
        }
        bool ColorControl::isForegroundSelected() const {
            return _fgSelected;
        }

    }
}
