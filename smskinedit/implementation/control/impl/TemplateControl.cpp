#include "control/impl/TemplateControl.h"

namespace smskinedit {
    namespace control {

        void TemplateControl::setOnionSkinningValue(float value) {
            _onionSkinningVaue = value;
            onControlUpdated(TemplateControl::ONION_SKINNING_VALUE_CHANGED);
        }
        float TemplateControl::getOnionSkinningValue() const {
            return _onionSkinningVaue;
        }

    }
}
