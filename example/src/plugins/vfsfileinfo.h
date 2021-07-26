//
// Created by andrey on 7/23/21.
//

#ifndef FINEFTP_VFSFILEINFO_H
#define FINEFTP_VFSFILEINFO_H

#include <fineftp/fileinfo.h>
#include "gcfilesystem.h"

class VFSFileInfo : public fineftp::Filesystem::FileInfo {
public:
    explicit VFSFileInfo(const std::string & name) : _name(name)
    {
        if (auto[found, element] = GCFS::GCFileSystem::instance().root().findChild(name); found == true) {
            _isOk = true;
            if (element->type() == GCFS::ElementType::File)
                _type = fineftp::Filesystem::FileType::RegularFile;
            else
                _type = fineftp::Filesystem::FileType::Dir;
            _size = element->size();
        }
    };

    virtual ~VFSFileInfo()
    {}

    bool isOk() const override {
        return _isOk;
    }

    fineftp::Filesystem::Permissions permissions() const override {
        return {true,false,false,true,false,false,true,false,false};
    }

    fineftp::Filesystem::FileType type() const override {
        return _type;
    }

    int64_t fileSize() const override {
        return _size;
    }

    std::string timeString() const override {
        return "Apr 1 12:00";
    }


    std::map<std::string, std::shared_ptr<FileInfo>> dirContent() override {
        std::map<std::string, std::shared_ptr<FileInfo>> result;
        if (auto[found, element] = GCFS::GCFileSystem::instance().root().findChild(_name); found == true) {
            for(const auto & e : element->children())
                result.insert({e->localName(), std::make_shared<VFSFileInfo>(e->virtualName())});
        }
        return result;
    }

    bool canOpenDir() const override {
        return isOk() && type() == fineftp::Filesystem::FileType::Dir;
    }

    std::string ownerString() const override
    {
        return "VxFTP";
    }

     std::string groupString() const override
    {
        return "VxFTP";
    }

private:
    std::string _name;
    bool _isOk = false;
    fineftp::Filesystem::FileType _type = fineftp::Filesystem::FileType::Unknown;
    int64_t _size = 0;
};


#endif //FINEFTP_VFSFILEINFO_H
