//
// Created by wangyuwei on 2020/7/18.
//

#ifndef ESQ_PERSISTOR_H
#define ESQ_PERSISTOR_H

#include "Message.h"

namespace esq {
    class Persistor {
        void persist(Message&& message);
        void persist(std::vector<Message>&& messages);

        Persistor();
        ~Persistor();
    };

}

#endif //ESQ_PERSISTOR_H
