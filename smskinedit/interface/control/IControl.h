#ifndef SMSKINEDIT_CONTROL_ICONTROL_H
#define SMSKINEDIT_CONTROL_ICONTROL_H

#include <functional>
#include <map>

namespace smskinedit {
    namespace control {

        //! An "event flag"
        using EventFlag = unsigned int;
        //! Events will be control defined and signaled via an EventFlag
        using Callback = std::function<void (EventFlag)>;

        /**
         *  @brief An interface for all controls within the software.
         */
        class IControl {

            public:
                IControl();
                virtual ~IControl() = default;

                IControl(const IControl&) = default;
                IControl& operator=(const IControl&) = default;
                IControl(IControl&&) = default;
                IControl& operator=(IControl&&) = default;

                void addCallback(const char*, Callback) const;
                void removeCallback(const char*) const;

            protected:
                //! Alert listeners that things have changed
                void onControlUpdated(EventFlag) const;

            private:
                mutable std::map<const char*, Callback> _callbacks;
        };

    }
}

#endif // SMSKINEDIT_CONTROL_CONTROLH
