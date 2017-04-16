#ifndef SMSKINEDIT_CONTROL_TEXTURECONTROL_H
#define SMSKINEDIT_CONTROL_TEXTURECONTROL_H

#include "control/IControl.h"
#include "enums.h"

namespace smskinedit {
    namespace control {

        /**
         *  @brief An intermediary for controlling and using the
         *  TextureSelectorWidget.
         */
        class TextureControl : public IControl {

            using ModelType = smskinedit::enums::ModelType;
            using TextureType = smskinedit::enums::TextureType;

            public:
                TextureControl() = default;
                ~TextureControl() = default;

                TextureControl(const TextureControl&) = default;
                TextureControl& operator=(const TextureControl&) = default;
                TextureControl(TextureControl&&) = default;
                TextureControl& operator=(TextureControl&&) = default;

                void setModelType(ModelType);
                ModelType getModelType() const;

                void setTextureType(TextureType);
                TextureType getTextureType() const;

                static const EventFlag MODEL_TYPE_CHANGED = EventFlag{0U};
                static const EventFlag TEXTURE_TYPE_CHANGED = EventFlag{1U};

            private:
                ModelType _modelType = ModelType::BODY;
                TextureType _textureType = TextureType::DIFFUSE;

        };

    }
}

#endif // SMSKINEDIT_CONTROL_TEXTURECONTROL_H
