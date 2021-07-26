//
// Created by andrey on 7/23/21.
//

#ifndef FINEFTP_VFSFILEINTF_H
#define FINEFTP_VFSFILEINTF_H
#include <fineftp/fileiointerface.h>
#include "gcfilesystem.h"

class VFSFileIntf : public fineftp::Filesystem::FileIOInterface {
public:
    bool open(const std::string & fileName) override
    {
        fd = GCFS::GCFileSystem::instance().open(fileName);
        _fileOpen = fd.fd != -1;
        _pos = 0;
        return _fileOpen;
    }
    bool good() override
    {
        return _fileOpen;
    }
    void close() override
    {
        GCFS::GCFileSystem::instance().close(fd);
        _fileOpen = false;
    }
    size_t size() override
    {
        //       if (good())
        return fd.size;
        //      return 0;
    }
    size_t seek(size_t pos) override
    {
        if (good()) {
            if (pos <= size()) {
                _pos = pos;
            }
            return _pos;
        }
        return 0;
    }
    size_t pos() override
    {
        return _pos;
    }
    uint32_t read(char * buf, uint32_t bufSize) override
    {
        if (good()) {
            auto bytes = GCFS::GCFileSystem::instance().read(fd, _pos, buf, bufSize);
            _pos += bytes;
            return bytes;
        }
        return 0;
    }
    uint32_t write(const char * buf, uint32_t bufSize) override
    {
        return 0;
    }
    void flush() override
    {

    }
    bool eof() override
    {
        return size() - pos() == 0;
    }
    virtual ~VFSFileIntf()
    {
        close();
    }
    bool _fileOpen = false;
    GCFS::FD fd;
    int _pos = 0;
};

#endif //FINEFTP_VFSFILEINTF_H
