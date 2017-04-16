#ifndef SMSKINEDIT_GENERAL_ENUMS_H
#define SMSKINEDIT_GENERAL_ENUMS_H

namespace smskinedit {

    /**
     *  @brief A namespace for holding common enums.
     */
    namespace enums {

        enum ModelType {
            BODY,
            HEAD,
            BOTH
        };

        enum TextureType {
            DIFFUSE,
            EMISSIVE
        };

        enum LightingType {
            FLAT,
            ILLUMINATED,
            IN_DARKNESS
        };

    }
}

#endif // SMSKINEDIT_GENERAL_ENUMS_H
