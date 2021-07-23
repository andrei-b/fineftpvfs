//
// Created by andrey on 7/23/21.
//

#ifndef FINEFTP_FILEIOINTERFACE_H
#define FINEFTP_FILEIOINTERFACE_H

#include <string>
#include <cstring>
#include <memory>
#include <functional>

namespace fineftp {

    namespace Filesystem {

        class FileIOInterface
        {
        public:
            virtual bool open(const std::string & fileName) = 0;
            virtual bool good() = 0;
            virtual void close() = 0;
            virtual size_t size() = 0;
            virtual size_t seek(size_t pos) = 0;
            virtual size_t pos() = 0;
            virtual uint32_t read(char * buf, uint32_t bufSize) = 0;
            virtual uint32_t write(const char * buf, uint32_t bufSize) = 0;
            virtual void flush() = 0;
            virtual bool eof() = 0;
        };

        std::shared_ptr<FileIOInterface> createFileInterfaceObject();
        void registerFileInterfaceFabric(const std::function<std::shared_ptr<FileIOInterface>()> & fabric);
    }
}


#endif //FINEFTP_FILEIOINTERFACE_H
