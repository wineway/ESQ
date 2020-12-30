//
// Created by wangyuwei on 2020/12/30.
//

#include "RingBuffer.h"
#include "gtest/gtest.h"

namespace esq {
    TEST(ringBuffer, append_test) {
        auto rb = RingBuffer<int>(5);
        int arr[] = {1,2,3,4};

        rb.append(arr, 4);

        size_t s = 0;
        auto r = rb.drain(s);
        for (int i = 0; i < s; i++) {
            std::cout << r[i] << ' ';
        }

        rb.append(arr, 4);
        r = rb.drain(s);
        for (int i = 0; i < s; i++) {
            std::cout << r[i] << ' ';
        }
        EXPECT_TRUE(r[1] == 2);
//        delete []  r;
    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}