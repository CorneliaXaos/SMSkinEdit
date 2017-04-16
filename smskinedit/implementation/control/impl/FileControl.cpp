#include "control/impl/FileControl.h"

namespace smskinedit {
    namespace control {

        void FileControl::setFileDirectory(std::string directory) {
            _directory = directory;
            onControlUpdated(FileControl::FILE_OPENED);
        }
        std::string FileControl::getFileDirectory() const {
            return _directory;
        }

        void FileControl::setFileModified(bool modified) {
            _fileModified = modified;
            onControlUpdated(FileControl::FILE_MODIFIED);
        }
        bool FileControl::isFileModified() const {
            return _fileModified;
        }

    }
}
