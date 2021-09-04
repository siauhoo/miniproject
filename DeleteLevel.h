//
// Created by charles.cxh on 2021/9/4.
//

#ifndef MINIPROJECT_DELETELEVEL_H
#define MINIPROJECT_DELETELEVEL_H

#include "sysinfo.h"

#pragma pack(push)
#pragma pack(1)

using namespace sysinfo;

class DeleteLevel {
public:
    uint8_t msgType = 3;
    char symbol[6];
    uint8_t side; //  1-Bid   2-Ask
    uint8_t level;  //  1 to 5
};

#pragma pack(pop)


#endif //MINIPROJECT_DELETELEVEL_H
