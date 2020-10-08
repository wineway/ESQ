//
// Created by wangyuwei on 2020/10/5.
//

#ifndef ESQ_RINGBUFFER_H
#define ESQ_RINGBUFFER_H

#include <cstddef>
#include <cstring>
#include <atomic>

namespace esq {
    template<class T>
    class RingBuffer final {
    public:
        explicit RingBuffer(size_t size);

        int append(T *data, size_t length);

        int commit(int index);

        int getReadIndex() {
            return readIndex;
        }

        int available();

        ~RingBuffer();

    private:
        T *buf;
        size_t size;
        std::atomic<int> writeIndex;
        std::atomic<int> readIndex;

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
        writeIndex.store((writeIndex + avl) % size, std::memory_order_relaxed);
        return static_cast<int>(avl);
    }

    template<class T>
    /* must ensure access non-concurrent */unsigned int RingBuffer<T>::retain() {
        int ri = readIndex.load(std::memory_order_consume);
        int wi = writeIndex;
        if (ri <= wi) {
            return size - wi + ri;
        } else {
            return ri - wi;
        }
    }

    template<class T>
    RingBuffer<T>::~RingBuffer() {
        delete[] this->buf;
    }

    template<class T>
    int RingBuffer<T>::commit(int index) {
        readIndex = index;
        return 0;
    }

    template<class T>
    int RingBuffer<T>::available() {
        int wi = writeIndex.load(std::memory_order_consume);
        int ri = readIndex;
        if (ri >= wi) {
            return size - ri + wi;
        } else {
            return wi - ri;
        }
    }

}

#endif //ESQ_RINGBUFFER_H
