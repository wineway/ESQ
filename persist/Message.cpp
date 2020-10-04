//
// Created by wangyuwei on 2020/7/18.
//

#include "persist/Message.h"

namespace esq {

    Message::~Message() {
        delete [] key;
        delete [] value;
    }

    Message::Message(long offset, const std::byte* key, const std::byte* value)
            : offset(offset), key(key), value(value) {}

}
