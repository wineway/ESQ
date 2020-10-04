//
// Created by wangyuwei on 2020/10/5.
//

#include "persist/AppendableFile.h"

#include <utility>
#include <unistd.h>

namespace esq {
    esq::AppendableFile::AppendableFile(int fd, std::string fileName, std::string dirName)
            : fd(fd), fileName(std::move(fileName)), dirName(std::move(dirName)), buf(cacheSize) {
        writeIndex = 0;
        readIndex = 0;
    }

    int esq::AppendableFile::write(std::byte data[], size_t size) {
        int writeSize{};
        while (writeSize != size) {
            int ws = buf.append(data, size);
            writeSize += ws;
        }
        return 0;
    }

    esq::AppendableFile::~AppendableFile() {
        close();
    }

    int esq::AppendableFile::close() const {
        return ::close(fd);
    }
}


