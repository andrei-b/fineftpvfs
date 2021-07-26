//
// Created by andrey on 7/25/21.
//

#ifndef GCFS_GCFILESYSTEM_H
#define GCFS_GCFILESYSTEM_H

#include <string>
#include <memory>
#include <vector>
#include "gcfselement.h"

namespace GCFS {

    struct FD
    {
        int fd = -1;
        int64_t ioffset = 0;
    };

    class GCFileSystem {
    public:
        GCFileSystem(GCFileSystem & other) = delete;
        GCFileSystem(GCFileSystem && rhs) = delete;
        FD open(const std::string & fileName);
        void close(FD fd);
        uint32_t read(FD fd, int64_t offset, char * buf, uint32_t bufsize);
        const GCFSElement & root() const;
        static GCFileSystem & instance();
        void makeSystem(const std::string & root);
    private:
        GCFileSystem();
        void addChildren(GCFSElement & parent, const std::string &path);
        std::shared_ptr<GCFSElement> _fsroot;
    };

}

#endif //GCFS_GCFILESYSTEM_H
