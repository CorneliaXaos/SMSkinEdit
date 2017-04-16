#ifndef SMSKINEDIT_CONTROL_EDITORCONTROL_H
#define SMSKINEDIT_CONTROL_EDITORCONTROL_H

#include "control/IControl.h"

namespace smskinedit {
    namespace control {

        /**
         *  @brief An intermediary for controlling and using the Editor menu
         *  of the MenuBarWidget.
         */
        class EditorControl : public IControl {

            public:
                EditorControl() = default;
                ~EditorControl() = default;

                EditorControl(const EditorControl&) = default;
                EditorControl& operator=(const EditorControl&) = default;
                EditorControl(EditorControl&&) = default;
                EditorControl& operator=(EditorControl&&) = default;

                void setUseInternalEditor(bool);
                bool shouldUseInternalEditor() const;

                static const EventFlag INTERNAL_EDITOR = EventFlag{0U};

            private:
                bool _useInternalEditor = true;
        };

    }
}

#endif // SMSKINEDIT_CONTROL_EDITORCONTROL_H
