//
// Created by charles.cxh on 2021/9/4.
//

#ifndef MINIPROJECT_SNAPSHOT_H
#define MINIPROJECT_SNAPSHOT_H

#include "sysinfo.h"

#pragma pack(push)
#pragma pack(1)

using namespace sysinfo;

class Snapshot {
public:
    uint8_t msgType = 1;
    char symbol[6]; // 股票代码，比如 600000
    double bidPrice[5]; // 买价
    uint32_t bidSize[5]; // 买数量
    double askPrice[5]; // 卖价
    uint32_t askSize[5]; // 卖数量
    void show();
};

#pragma pack(pop)

#endif //MINIPROJECT_SNAPSHOT_H
