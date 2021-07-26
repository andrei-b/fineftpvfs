//
// Created by andrey on 7/24/21.
//

#include "gcfselement.h"
#include "utils.h"

#include <utility>

namespace GCFS {

    GCFSElement::GCFSElement(std::string fileName, std::string virtualName, ElementType type,
                             int64_t size,
                             int64_t offset)
            : _fsName(std::move(fileName)), _virtualName(std::move(virtualName)), _type(type), _offset(offset)
    {}

    const std::string &GCFSElement::fileName() const {
        return _fsName;
    }

    ElementType GCFSElement::type() const {
        return _type;
    }

    int64_t GCFSElement::offset() const {
        return _offset;
    }

    const std::vector<GCFSElement> GCFSElement::children() const {
        return _children;
    }

    GCFSElement &GCFSElement::addChild(const std::string &fileName, const std::string &relVirtualName, ElementType type, int64_t size, int64_t offset) {
        std::string shortName = relVirtualName;
        if (shortName.empty())
            shortName = fileName.substr(fileName.find_last_of('/') + 1);
        std::string fullName = virtualName().back() == '/' ? std::string(virtualName()).append(shortName) : std::string(virtualName()).append("/").append(shortName);
        if (fullName.back() == '/')
            fullName = fullName.substr(0, fullName.length()-1);
        _children.emplace_back(fileName, fullName, type, size, offset);
        return _children.back();
    }

    int64_t GCFSElement::size() const {
        return _size;
    }

    const std::string &GCFSElement::virtualName() const {
        return _virtualName;
    }

    std::tuple<bool, const GCFSElement> GCFSElement::findChild(const std::string &virtualName) const {
        if (virtualName == this->virtualName())
            return std::tuple{true, *this};
        if (virtualName.find(this->virtualName(), 0) == 0) {
            for (const auto & ch : _children) {
                if (auto [found, child] = ch.findChild(virtualName); found)
                    return std::tuple{true, child};
            }
        }
        return std::tuple{false, *this};
    }

    std::string GCFSElement::localName() const {
        if (virtualName() == "/")
            return "";
        if (auto pos = virtualName().find_last_of('/'); pos != std::string::npos)
            return virtualName().substr(pos+1);
        return "";
    }

}