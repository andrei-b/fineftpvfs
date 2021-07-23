//
// Created by andrey on 7/22/21.
//

#include "fineftp/fileinfo.h"

namespace fineftp {

    namespace Filesystem {


        static std::function<std::shared_ptr<FileInfo>(const std::string &)> infoCallback = nullptr;


        std::shared_ptr<FileInfo> createFileInfoObject(const std::string &name) {
            if (infoCallback == nullptr)
                throw std::exception();
            return infoCallback(name);
        }

        void registerFileInfoFabric(const std::function<std::shared_ptr<FileInfo>(const std::string &)> &fabric) {
            infoCallback = fabric;
        }
    }
}