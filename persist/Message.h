//
// Created by wangyuwei on 2020/7/18.
//

#ifndef ESQ_MESSAGE_H
#define ESQ_MESSAGE_H

#include <vector>
#include <cstddef>
#include "Persister.h"

namespace esq {
    class Message {
        static Persister persister;
    private:
        const long offset;
        const std::vector<std::byte> &key;
        const std::vector<std::byte> &value;

        friend class Persister;


    public:
        explicit Message(long offset, const std::vector<std::byte> &key, const std::vector<std::byte> &value);

        void append(Message &message);

        void append(std::vector<Message> &messages);
    };


}
#endif //ESQ_MESSAGE_H
