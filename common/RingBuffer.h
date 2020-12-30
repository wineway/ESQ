//
// Created by wangyuwei on 2020/10/5.
//

#ifndef ESQ_RINGBUFFER_H
#define ESQ_RINGBUFFER_H

#include <cstddef>
#include <cstring>
#include <atomic>
#include <array>

namespace esq {
    template<class T>
    class RingBuffer final {
    public:
        explicit RingBuffer(size_t size);

        int append(T *data, size_t length);

        T *drain(size_t &size);

        ~RingBuffer();

        T *buf;

    private:
        const size_t size_;
        std::atomic<int> writeIndex;
        std::atomic<int> readIndex;
        static constexpr size_t typeSize = sizeof(T);
    };



    template<class T>
    RingBuffer<T>::RingBuffer(size_t size):size_(size), writeIndex(0), readIndex(0) {
        this->buf = new T[size_];
    }

    struct Range {
        int from;
        int to;
    };

    template<class T>
    int RingBuffer<T>::append(T *data, size_t length) {

        int from = readIndex.load(std::memory_order_acquire) % size_, to =
                writeIndex.load(std::memory_order_acquire) % size_;
        if ((size_ - from + to) < length) return -1;
        if (from >= to && size_ - from < length) {
            std::memcpy(buf + from, data, (size_ - from) * typeSize);
            std::memcpy(buf, data + size_ - from, (length + from - size_) * typeSize);
        } else std::memcpy(buf + from, data, length * typeSize);
        writeIndex.store(to + length, std::memory_order_release);
        return 0;
    }

    template<class T>
    RingBuffer<T>::~RingBuffer() {
        delete[] this->buf;
    }

    template<class T>
    T *RingBuffer<T>::drain(size_t &size) {
        int from = readIndex.load(std::memory_order_acquire) % size_, to =
                writeIndex.load(std::memory_order_acquire) % size_;
        T *res;
        if (from > to) {
            size = size_ - from + to;
            res = new T[size];
            std::memcpy(res, buf + from, (size_ - from) * typeSize);
            std::memcpy(res + size_ - from, buf, to * typeSize);
        } else {
            size = to - from;
            res = new T[size];
            std::memcpy(res, buf + from, size * typeSize);
        }
        readIndex.store(from + size);
        return res;
    }


}

#endif //ESQ_RINGBUFFER_H
