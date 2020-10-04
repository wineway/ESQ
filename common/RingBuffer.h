//
// Created by wangyuwei on 2020/10/5.
//

#ifndef ESQ_RINGBUFFER_H
#define ESQ_RINGBUFFER_H

#include <cstddef>
#include <cstring>

namespace esq {
    template<class T>
    class RingBuffer final {
    public:
        explicit RingBuffer(size_t size);
        int append(T* data, size_t length);

        ~RingBuffer();

    private:
        T* buf;
        size_t size;
        int writeIndex;
        int readIndex;

        unsigned int retain();
    };


    template<class T>
    RingBuffer<T>::RingBuffer(size_t size):size(size), writeIndex(0), readIndex(0) {
        this->buf = new T[size];
    }

    template<class T>
    int RingBuffer<T>::append(T *data, size_t length) {
        unsigned int ret = retain();
        unsigned int avl = ret > length ? length : ret;
        std::memcpy(&buf, data, avl);
        writeIndex += avl;
        return avl;
    }

    template<class T>
    unsigned int RingBuffer<T>::retain() {
        if (readIndex <= writeIndex) {
            return writeIndex - readIndex;
        } else {
            return writeIndex + size - readIndex;
        }
    }

    template<class T>
    RingBuffer<T>::~RingBuffer() {
        delete [] this->buf;
    }

}

#endif //ESQ_RINGBUFFER_H
