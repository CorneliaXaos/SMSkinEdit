#ifndef SMSKINEDIT_CONTROL_CONTROLS_H
#define SMSKINEDIT_CONTROL_CONTROLS_H

#include "control/impl/ColorControl.h"
#include "control/impl/EditorControl.h"
#include "control/impl/FileControl.h"
#include "control/impl/LightingControl.h"
#include "control/impl/ModelControl.h"
#include "control/impl/TemplateControl.h"
#include "control/impl/TextureControl.h"

namespace smskinedit {
    namespace control {

        /**
         *  @brief Contains control instances used by the application
         */
        namespace controls {

            //! Backing for the ActiveColorWidget
            extern ColorControl colorControl;
            //! Backing for the ModelSelectorWidget
            extern ModelControl modelControl;
            //! Backing for the TextureSelectorWidget
            extern TextureControl textureControl;
            //! Backing for the OnionSkinningWidget
            extern TemplateControl templateControl;
            //! Backing for the MenuBarWidget file menu
            extern FileControl fileControl;
            //! Backing for the MenuBarWidget Editor menu
            extern EditorControl editorControl;
            //! Backing for the MenuBarWidget Lighting menu
            extern LightingControl lightingControl;

        }

    }
}

#endif // SMSKINEDIT_CONTROL_CONTROLS_H
