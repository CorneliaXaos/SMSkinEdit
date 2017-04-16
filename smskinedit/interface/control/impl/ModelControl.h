#ifndef SMSKINEDIT_CONTROL_MODELCONTROL_H
#define SMSKINEDIT_CONTROL_MODELCONTROL_H

#include "control/IControl.h"
#include "enums.h"

namespace smskinedit {
    namespace control {

        /**
         *  @brief An intermediary for controlling and using the
         *  ModelSelectorWidget.
         */
        class ModelControl : public IControl {

            using ModelType = smskinedit::enums::ModelType;

            public:
                ModelControl() = default;
                ~ModelControl() = default;

                ModelControl(const ModelControl&) = default;
                ModelControl& operator=(const ModelControl&) = default;
                ModelControl(ModelControl&&) = default;
                ModelControl& operator=(ModelControl&&) = default;

                void setModelType(ModelType);
                ModelType getModelType() const;

                static const EventFlag MODEL_TYPE_CHANGED = EventFlag{0U};

            private:
                ModelType _modelType = ModelType::BODY;
        };

    }
}

#endif // SMSKINEDIT_CONTROL_MODELCONTROL_H
