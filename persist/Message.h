//
// Created by wangyuwei on 2020/7/18.
//

#ifndef ESQ_MESSAGE_H
#define ESQ_MESSAGE_H

#include <vector>
#include <string>

namespace esq {
    class Message {
    private:
        const long offset;
        const std::byte* key;
        const std::byte* value;

        friend class Persistor;


    public:
        explicit Message(long offset, const std::byte* key, const std::byte* value);

        virtual ~Message();

    };


}
#endif //ESQ_MESSAGE_H
