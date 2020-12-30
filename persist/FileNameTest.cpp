//
// Created by wangyuwei on 2020/12/30.
//


#include "gtest/gtest.h"
#include "persist/FileName.h"

TEST(logfile_name_test, logfile_name) {
    auto fileName = esq::logFileName("partitionName", 342);
   EXPECT_TRUE(fileName == "partitionName342.esq");
}

TEST(metafile_name_test, metafile_name) {
    auto fileName =  esq::metaFileName("partitionName", 342);
    EXPECT_TRUE(fileName == "partitionName342.meta");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}