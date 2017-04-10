#include "control/impl/ColorControl.h"

namespace smskinedit {
    namespace control {

        void ColorControl::setForegroundColor(unsigned int color) {
            _fgColor = color;
            onControlUpdated();
        }
        unsigned int ColorControl::getForegroundColor() const {
            return _fgColor;
        }

        void ColorControl::setBackgroundColor(unsigned int color) {
            _bgColor = color;
            onControlUpdated();
        }
        unsigned int ColorControl::getBackgroundColor() const {
            return _bgColor;
        }

        void ColorControl::setForegroundSelected(bool selected) {
            _fgSelected = selected;
            onControlUpdated();
        }
        bool ColorControl::isForegroundSelected() const {
            return _fgSelected;
        }

    }
}
