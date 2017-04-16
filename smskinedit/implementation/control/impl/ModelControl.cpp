#include "control/impl/ModelControl.h"
#include "enums.h"

using ModelType = smskinedit::enums::ModelType;

namespace smskinedit {
    namespace control {

        void ModelControl::setModelType(ModelType modelType) {
            _modelType = modelType;
            onControlUpdated(ModelControl::MODEL_TYPE_CHANGED);
        }

        ModelType ModelControl::getModelType() const {
            return _modelType;
        }

    }
}
