#ifndef SMSKINEDIT_CONTROL_LIGHTINGCONTROL_H
#define SMSKINEDIT_CONTROL_LIGHTINGCONTROL_H

#include "control/IControl.h"
#include "enums.h"

namespace smskinedit {
    namespace control {

        /**
         *  @brief An intermediary for controlling and using the Lighting menu
         *  of the MenuBarWidget.
         */
        class LightingControl : public IControl {

            using LightingType = smskinedit::enums::LightingType;

            public:
                LightingControl() = default;
                ~LightingControl() = default;

                LightingControl(const LightingControl&) = default;
                LightingControl& operator=(const LightingControl&) = default;
                LightingControl(LightingControl&&) = default;
                LightingControl& operator=(LightingControl&&) = default;

                void setLightingType(LightingType);
                LightingType getLightingType() const;

                static const EventFlag LIGHTING_CHANGED = EventFlag{0U};

            private:
                LightingType _lightingType = LightingType::FLAT;
        };

    }
}

#endif // SMSKINEDIT_CONTROL_LIGHTINGCONTROL_H
