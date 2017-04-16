#include "control/impl/LightingControl.h"
#include "enums.h"

using LightingType = smskinedit::enums::LightingType;

namespace smskinedit {
    namespace control {

        void LightingControl::setLightingType(LightingType lightingType) {
            _lightingType = lightingType;
            onControlUpdated(LightingControl::LIGHTING_CHANGED);
        }
        LightingType LightingControl::getLightingType() const {
            return _lightingType;
        }

    }
}
