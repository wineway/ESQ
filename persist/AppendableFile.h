//
// Created by wangyuwei on 2020/10/5.
//

#ifndef ESQ_APPENDABLEFILE_H
#define ESQ_APPENDABLEFILE_H

#include <cstddef>
#include <string>
#include "common/RingBuffer.h"

namespace esq {
    class AppendableFile final {
    public:
        AppendableFile(int fd, std::string fileName, std::string dirName);

        ~AppendableFile();

        int write(std::byte data[], size_t size);

    private:
        const int fd;
        RingBuffer<std::byte> buf;
        const std::string fileName;
        const std::string dirName;
        int writeIndex;
        int readIndex;
        constexpr static int cacheSize = 1024 * 1024;
        int close() const;


    };
}

#endif //ESQ_APPENDABLEFILE_H
