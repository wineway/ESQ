//
// Created by wangyuwei on 2020/10/3.
//

#ifndef ESQ_FILENAME_H
#define ESQ_FILENAME_H

#include <string>

#define LOG_FILE_SUFFIX ".esq"
#define META_FILE_SUFFIX ".meta"
namespace esq {
    std::string logFileName(std::string&& partitionName, int seqId) {
        char buf[11];
        std::snprintf(buf, sizeof(buf), "%d", seqId);
        return partitionName + buf + LOG_FILE_SUFFIX;
    }

    std::string metaFileName(std::string&& partitionName, int indexId) {
        char buf[11];
        std::snprintf(buf, sizeof(buf), "%d", indexId);
        return partitionName + buf + META_FILE_SUFFIX;
    }
}

#endif //ESQ_FILENAME_H
