//
// Created by charles.cxh on 2021/9/4.
//

#ifndef MINIPROJECT_STOCKS_H
#define MINIPROJECT_STOCKS_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>
#include <sstream>
#include <unistd.h>
#include <map>

#include<sys/stat.h>
#include "Snapshot.h"
#include "UpdateLevel.h"
#include "DeleteLevel.h"

static const size_t msgTypeOffset = sizeof(uint8_t);

static const size_t symbolOffset = 6 * sizeof(char);

static const size_t bidPriceOffset = 5 * sizeof(FLOAT64);

static const size_t bidSizeOffset = 5 * sizeof(uint32_t);

static const size_t askPriceOffset = 5 * sizeof(FLOAT64);

static const size_t sideOffset = sizeof(uint8_t);

static const size_t levelOffset = sizeof(uint8_t);

static const size_t priceOffset = sizeof(FLOAT64);

class Stocks {
private:
    std::map<std::string, Snapshot> snapshotMap;
public:
    /**
     * 根据bufer反序列化成对象
     * @param arg
     * @param size
     */
    void deserialize(std::unique_ptr<char[]> &arg, std::streamsize size);

    Snapshot *query(std::string symbol);

    ~Stocks() {
        snapshotMap.clear();
    }
};


#endif //MINIPROJECT_STOCKS_H
