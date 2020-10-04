//
// Created by wangyuwei on 2020/10/6.
//

#ifndef ESQ_CHANNEL_H
#define ESQ_CHANNEL_H

#include <string>
#include "persist/Persistor.h"

namespace esq {
    class Channel {
        std::string partition;
        Persistor persistor;
    };
}
#endif //ESQ_CHANNEL_H
