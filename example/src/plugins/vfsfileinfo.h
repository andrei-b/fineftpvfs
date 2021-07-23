//
// Created by andrey on 7/23/21.
//

#ifndef FINEFTP_VFSFILEINFO_H
#define FINEFTP_VFSFILEINFO_H

#include <fineftp/fileinfo.h>

class VFSFileInfo : public fineftp::Filesystem::FileInfo {
public:
    explicit VFSFileInfo(const std::string & name) : _name(name)
    {};

    virtual ~VFSFileInfo()
    {}

    bool isOk() const override {
        return true;
    }

    fineftp::Filesystem::Permissions permissions() const override {
        return {true,true,false,true,true,false,true,true,false};
    }

    fineftp::Filesystem::FileType type() const override {
        if (_name == "/")
            return fineftp::Filesystem::FileType::Dir;;
        if (_name.find("dir") != std::string::npos)
            return fineftp::Filesystem::FileType::Dir;
        if (_name.find("file") != std::string::npos)
            return fineftp::Filesystem::FileType::RegularFile;
        return fineftp::Filesystem::FileType::Unknown;
    }

    int64_t fileSize() const override {
        if(type() == fineftp::Filesystem::FileType::RegularFile)
            return 1024;
        if(type() == fineftp::Filesystem::FileType::Dir)
            return 4096;
        return 0;
    }

    std::string timeString() const override {
        return "Apr 1 12:00";
    }


    std::map<std::string, std::shared_ptr<FileInfo>> dirContent() override {
        std::map<std::string, std::shared_ptr<FileInfo>> result;
        if (_name.find("dir1") != std::string::npos) {
            result.insert({std::string("file2"), std::make_shared<VFSFileInfo>("file2")});
            result.insert({std::string("file3"), std::make_shared<VFSFileInfo>("file3")});
        }
        if (_name.find("dir2") != std::string::npos) {
            result.insert({std::string("file4"), std::make_shared<VFSFileInfo>("file4")});
            result.insert({std::string("file5"), std::make_shared<VFSFileInfo>("file5")});
            result.insert({std::string("dir4"), std::make_shared<VFSFileInfo>("dir4")});
        }
        if(_name == "/")  {
            result.insert({std::string("dir1"), std::make_shared<VFSFileInfo>("dir1")});
            result.insert({std::string("dir2"), std::make_shared<VFSFileInfo>("dir2")});
            result.insert({std::string("file1"), std::make_shared<VFSFileInfo>("file1")});
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
};


#endif //FINEFTP_VFSFILEINFO_H
