//
// Created by andrey on 7/24/21.
//

#ifndef GCFS_GCFSELEMENT_H
#define GCFS_GCFSELEMENT_H

#include <string>
#include <vector>
#include <tuple>


namespace GCFS {

    enum class ElementType {
        RealDirectory,
        VirtualDirectory,
        File
    };

    class GCFSElement {
    public:
        GCFSElement(std::string fileName, std::string virtualName, ElementType type, int64_t size,
                    int64_t offset = 0);
        ElementType type() const;
        const std::string & fileName() const;
        const std::string & virtualName() const;
        std::string localName() const;
        int64_t offset() const;
        int64_t size() const;
        const std::vector<GCFSElement> children() const;
        GCFSElement & addChild(const std::string & fileName, const std::string &relVirtualName, ElementType type, int64_t size, int64_t offset = 0);
        std::tuple<bool, const GCFSElement> findChild(const std::string &virtualName) const;
    private:
        ElementType _type;
        std::string _fsName;
        std::string _virtualName;
        int64_t _offset;
        int64_t _size;
        std::vector<GCFSElement> _children;
    };

}

#endif //GCFS_GCFSELEMENT_H
