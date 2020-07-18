//
// Created by wangyuwei on 2020/7/18.
//

#ifndef ESQ_PERSISTER_H
#define ESQ_PERSISTER_H

#include "Message.h"
namespace esq {
    class Persister {
        static void persist(Message message);
        static void persist(std::vector<Message>& messages);
    };
}

#endif //ESQ_PERSISTER_H
