#include "control/impl/TextureControl.h"
#include "enums.h"

using ModelType = smskinedit::enums::ModelType;
using TextureType = smskinedit::enums::TextureType;

namespace smskinedit {
    namespace control {

        void TextureControl::setModelType(ModelType modelType) {
            _modelType = modelType;
            onControlUpdated(TextureControl::MODEL_TYPE_CHANGED);
        }
        ModelType TextureControl::getModelType() const {
            return _modelType;
        }

        void TextureControl::setTextureType(TextureType textureType) {
            _textureType = textureType;
            onControlUpdated(TextureControl::TEXTURE_TYPE_CHANGED);
        }
        TextureType TextureControl::getTextureType() const {
            return _textureType;
        }

    }
}
