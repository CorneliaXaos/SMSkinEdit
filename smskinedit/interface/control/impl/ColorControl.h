#ifndef SMSKINEDIT_CONTROL_COLORCONTROL_H
#define SMSKINEDIT_CONTROL_COLORCONTROL_H

#include "control/IControl.h"

namespace smskinedit {
    namespace control {

        class ColorControl : public IControl {

            public:
                ColorControl() = default;
                ~ColorControl() = default;

                ColorControl(const ColorControl&) = default;
                ColorControl& operator=(const ColorControl&) = default;
                ColorControl(ColorControl&&) = default;
                ColorControl& operator=(ColorControl&&) = default;

                void setForegroundColor(unsigned int);
                unsigned int getForegroundColor() const;

                void setBackgroundColor(unsigned int);
                unsigned int getBackgroundColor() const;

                void setForegroundSelected(bool);
                bool isForegroundSelected() const;

            private:
                unsigned int _fgColor = 0x00000000, _bgColor = 0xFFFFFF00;
                bool _fgSelected = true;
        };

    }
}

#endif // SMSKINEDIT_CONTROL_COLORCONTROL_H
