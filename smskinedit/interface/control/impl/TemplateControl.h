#ifndef SMSKINEDIT_CONTROL_TEMPLATECONTROL_H
#define SMSKINEDIT_CONTROL_TEMPLATECONTROL_H

#include "control/IControl.h"

namespace smskinedit {
    namespace control {

        /**
         *  @brief An intermediary for controlling and using the
         *  OnionSkinningWidget.
         */
        class TemplateControl : public IControl {

            public:
                TemplateControl() = default;
                ~TemplateControl() = default;

                TemplateControl(const TemplateControl&) = default;
                TemplateControl& operator=(const TemplateControl&) = default;
                TemplateControl(TemplateControl&&) = default;
                TemplateControl& operator=(TemplateControl&&) = default;

                void setOnionSkinningValue(float);
                float getOnionSkinningValue() const;

                static const EventFlag ONION_SKINNING_VALUE_CHANGED =
                        EventFlag{0U};

            private:
                float _onionSkinningVaue = 1.0F;
        };

    }
}

#endif // SMSKINEDIT_CONTROL_TEMPLATECONTROL_H
