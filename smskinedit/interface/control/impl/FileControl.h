#ifndef SMSKINEDIT_CONTROL_FILECONTROL_H
#define SMSKINEDIT_CONTROL_FILECONTROL_H

#include <string>

#include "control/IControl.h"

namespace smskinedit {
    namespace control {

        /**
         *  @brief An intermediary for controlling and using the File menu
         *  of the MenuBarWidget.
         */
        class FileControl : public IControl {

            public:
                FileControl() = default;
                ~FileControl() = default;

                FileControl(const FileControl&) = default;
                FileControl& operator=(const FileControl&) = default;
                FileControl(FileControl&&) = default;
                FileControl& operator=(FileControl&&) = default;

                void setFileDirectory(std::string);
                std::string getFileDirectory() const;

                void setFileModified(bool);
                bool isFileModified() const;

                static const EventFlag FILE_OPENED = EventFlag{0U};
                static const EventFlag FILE_MODIFIED = EventFlag{1U};

            private:
                std::string _directory {""};
                bool _fileModified = false;
        };

    }
}

#endif // SMSKINEDIT_CONTROL_FILECONTROL_H
