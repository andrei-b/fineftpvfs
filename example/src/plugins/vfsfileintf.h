//
// Created by andrey on 7/23/21.
//

#ifndef FINEFTP_VFSFILEINTF_H
#define FINEFTP_VFSFILEINTF_H
#include <fineftp/fileiointerface.h>

class VFSFileIntf : public fineftp::Filesystem::FileIOInterface {
public:
    bool open(const std::string & fileName) override
    {
        _fileOpen = true;
        _pos = 0;
        _fileName = fileName;
        _text = _text.append(fileName);
        return _fileOpen;
    }
    bool good() override
    {
        return _fileOpen;
    }
    void close() override
    {
        _fileOpen = false;
    }
    size_t size() override
    {
        //       if (good())
        return _text.size();
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
            auto actBytes = bufSize < size() - pos() ? bufSize : size() - pos();
            strncpy(buf, &_text.c_str()[_pos], actBytes);
            _pos += actBytes;
            return actBytes;
        }
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
    std::string _fileName;
    std::string _text = "This is the text of the file ";
    int _pos = 0;
};

#endif //FINEFTP_VFSFILEINTF_H
