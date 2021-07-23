//
// Created by andrey on 7/22/21.
//

#ifndef FINEFTP_FILEINFO_H
#define FINEFTP_FILEINFO_H

#include <string>
#include <map>
#include <memory>
#include <functional>

namespace fineftp {

    namespace Filesystem {

        enum class FileType
        {
            Unknown,
            RegularFile,
            Dir,
            CharacterDevice,
            BlockDevice,
            Fifo,
            SymbolicLink,
            Socket
        };

        struct Permissions
        {
            bool OwnerCanRead = false;
            bool OwnerCanWrite = false;
            bool OwnerCanExec = false;
            bool GroupCanRead = false;
            bool GroupCanWrite = false;
            bool GroupCanExec = false;
            bool OthersCanRead = false;
            bool OthersCanWrite = false;
            bool OthersCanExec = false;
        };

        class FileInfo {
        public:
            virtual bool isOk() const = 0;
            virtual Permissions permissions() const = 0;
            virtual FileType type() const = 0;
            virtual int64_t fileSize() const = 0;
            virtual std::string timeString() const = 0;
            virtual bool canOpenDir() const = 0;
            virtual std::map<std::string, std::shared_ptr<FileInfo>> dirContent() = 0;


            virtual bool permissionRootRead()     const { return permissions().OthersCanRead; }
            virtual bool permissionRootWrite()    const { return permissions().OthersCanWrite; }
            virtual bool permissionRootExecute()  const { return permissions().OthersCanExec; }
            virtual bool permissionGroupRead()    const { return permissions().GroupCanRead; }
            virtual bool permissionGroupWrite()   const { return permissions().GroupCanWrite; }
            virtual bool permissionGroupExecute() const { return permissions().GroupCanExec; }
            virtual bool permissionOwnerRead()    const { return permissions().OwnerCanRead; }
            virtual bool permissionOwnerWrite()   const { return permissions().OwnerCanWrite; }
            virtual bool permissionOwnerExecute() const { return permissions().OwnerCanExec; }

            virtual std::string permissionString() const
            {
                std::string permission_string(9, '-');

                if (!isOk())
                    return permission_string;

                // Root
                permission_string[0] = permissionOwnerRead() ? 'r' : '-';
                permission_string[1] = permissionOwnerWrite() ? 'w' : '-';
                permission_string[2] = permissionOwnerExecute() ? 'x' : '-';
                // Group
                permission_string[3] = permissionGroupRead() ? 'r' : '-';
                permission_string[4] = permissionGroupWrite() ? 'w' : '-';
                permission_string[5] = permissionGroupExecute() ? 'x' : '-';
                // Owner
                permission_string[6] = permissionRootRead() ? 'r' : '-';
                permission_string[7] = permissionRootWrite() ? 'w' : '-';
                permission_string[8] = permissionRootExecute() ? 'x' : '-';

                return permission_string;
            }

            virtual std::string ownerString() const
            {
                return "ViFTP";
            }

            virtual std::string groupString() const
            {
                return "ViFTP";
            }

        };

        std::shared_ptr<FileInfo> createFileInfoObject(const std::string & name);
        void registerFileInfoFabric(const std::function<std::shared_ptr<FileInfo>(const std::string &)> & fabric);
    }
}


#endif //FINEFTP_FILEINFO_H
