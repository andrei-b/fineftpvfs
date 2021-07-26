//
// Created by andrey on 7/25/21.
//

#include <experimental/filesystem>
#include <regex>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "fmt/format.h"
#include "gcfilesystem.h"
#include "utils.h"

namespace GCFS {

    GCFileSystem::GCFileSystem() {

    }

    GCFileSystem &GCFileSystem::instance() {
        static GCFileSystem system;
        return system;
    }

    void GCFileSystem::makeSystem(const std::string &root) {
        _fsroot = std::make_shared<GCFSElement>(root, "/", ElementType::RealDirectory, 0);
        addChildren(*_fsroot, root);

    }

    const std::string LayerTagRe = "\\(<LAYER *(number)? *= *(\\d*)>\\)\r*\n";
    const std::string LabelTagRe = "#513 *= *(\\d*)\r*\n";
    void offsetsByTag(std::string & program, const std::string & tag, std::map<int64_t, std::string> & offsets, std::string prefix, int index)
    {
        std::regex re(tag);
        std::sregex_iterator i(program.begin(), program.end(), re);
        while(i != std::sregex_iterator()) {
            offsets.insert({i->position(), fmt::format("{}{}", prefix, (*i)[index].str())});
            i++;
        }
    }

    void GCFileSystem::addChildren(GCFSElement &parent, const std::string &path) {
        using namespace std::experimental;
        if (parent.type() == ElementType::RealDirectory) {
            for (const auto &entry : filesystem::directory_iterator(path)) {
                if (filesystem::is_directory(entry.status())) {
                    auto newChild = parent.addChild(entry.path().string(), "", ElementType::RealDirectory, 0);
                    addChildren(newChild, entry.path().string());
                } else {
                    if (filesystem::is_regular_file(entry.status())) {
                        auto & newChild = parent.addChild(entry.path().string(), "", ElementType::VirtualDirectory, 0);
                        addChildren(newChild, entry.path().string());
                    }
                }
            }
        } else {
            if (parent.type() == ElementType::VirtualDirectory) {
                std::map<int64_t, std::string> offsets;
                auto mainProgram = readFile(parent.fileName());
                offsetsByTag(mainProgram, LayerTagRe, offsets, "LAYER_", 2);
                offsetsByTag(mainProgram, LabelTagRe, offsets, "label_", 1);
                parent.addChild(parent.fileName(), "", ElementType::File, mainProgram.length());
                int ord = 0;
                for(const auto & r : offsets) {
                    parent.addChild(parent.fileName(), fmt::format("{:04d}_{}.nc", ord, r.second), ElementType::File, mainProgram.length() - r.first, r.first);
                    ord++;
                }
            }
        }
    }

    FD GCFileSystem::open(const std::string &fileName) {
        auto[found, element] = _fsroot->findChild(fileName);
        if (found) {
            FD result;
            result.fd = ::open(element.fileName().c_str(), O_RDONLY);
            result.ioffset = element.offset();
            return result;
        }
        return FD();
    }

    void GCFileSystem::close(FD fd) {
        ::close(fd.fd);
    }

    uint32_t GCFileSystem::read(FD fd, int64_t offset, char *buf, uint32_t bufsize) {
        lseek(fd.fd, fd.ioffset+offset, SEEK_SET);
        return ::read(fd.fd, buf, bufsize);
    }

    const GCFSElement &GCFileSystem::root() const {
        return *_fsroot;
    }



}