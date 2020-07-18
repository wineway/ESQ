//
// Created by wangyuwei on 2020/7/18.
//

#include "Message.h"

namespace esq {

    void esq::Message::append(Message &message) {

    }

    void Message::append(std::vector<Message> &messages) {

    }

    Message::Message(const long offset, const std::vector<std::byte> &key, const std::vector<std::byte> &value)
            : offset(offset), key(key), value(value) {}

}
