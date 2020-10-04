//
// Created by wangyuwei on 2020/7/18.
//

#include "persist/Persistor.h"
#include <sys/epoll.h>
#include <fcntl.h>
#include <cerrno>
#include "FileName.h"

void esq::Persistor::persist(esq::Message&& message) {
}

void esq::Persistor::persist(std::vector<Message>&& messages) {

}

esq::Persistor::Persistor() {

}

esq::Persistor::~Persistor() {
    int i;
}
