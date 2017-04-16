#include <functional>
#include <map>

#include "control/IControl.h"

namespace smskinedit {
    namespace control {

        IControl::IControl() : _callbacks(std::map<const char*, Callback>{}) {}

        // Controller Methods
        void IControl::addCallback(const char* id, Callback callback) const {
            _callbacks[id] = callback;
        }
        void IControl::removeCallback(const char* id) const {
            _callbacks.erase(id);
        }

        // Protected Methods
        void IControl::onControlUpdated(EventFlag event) const {
            for (auto it = _callbacks.begin(); it != _callbacks.end(); it++) {
                it->second(event);
            }
        }

    }
}
