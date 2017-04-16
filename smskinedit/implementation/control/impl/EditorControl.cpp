#include "control/impl/EditorControl.h"

namespace smskinedit {
    namespace control {

        void EditorControl::setUseInternalEditor(bool useInternalEditor) {
            _useInternalEditor = useInternalEditor;
            onControlUpdated(EditorControl::INTERNAL_EDITOR);
        }
        bool EditorControl::shouldUseInternalEditor() const {
            return _useInternalEditor;
        }

    }
}
