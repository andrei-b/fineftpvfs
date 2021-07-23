//
// Created by andrey on 7/23/21.
//

#include "fineftp/fileiointerface.h"
#include <functional>
#include <exception>

namespace fineftp {
    namespace Filesystem {

        static std::function<std::shared_ptr<FileIOInterface>()> interfaceCallback = nullptr;

        std::shared_ptr<FileIOInterface> createFileInterfaceObject() {
            if (interfaceCallback == nullptr)
                throw std::exception();
            return interfaceCallback();
        }

        void registerFileInterfaceFabric(const std::function<std::shared_ptr<FileIOInterface>()> &fabric) {
            interfaceCallback = fabric;
        }

    }
}