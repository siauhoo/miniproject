//
// Created by charles.cxh on 2021/9/4.
//

#include "Stocks.h"
#include <map>
#include <iostream>
#include "sysinfo.h"
#include "Snapshot.h"
#include "UpdateLevel.h"
#include "DeleteLevel.h"

using namespace sysinfo;

enum msgType {
    SNAPSHOT_TYPE = (uint8_t) 1,//存在
    UPDATE_TYPE = (uint8_t) 2,//执行
    DELETE_TYPE = (uint8_t) 3,//写
};

/**
 * 反序列化
 */
void Stocks::deserialize(std::unique_ptr<char[]> &arg, std::streamsize size) {
    if (size <= 0) {
        std::cout << "文件处理内容为空" << std::endl;
        return;
    }
    size_t offset = 0;
    while (offset < size) {
        uint8_t type = sysinfo::ReadUInt8(arg[offset]);
        //第一阶段：初始化五档行情
        if (type == SNAPSHOT_TYPE) {
            Snapshot snapshot;

            //内存初始化
            memset(&snapshot, 0, sizeof(struct Snapshot));

            snapshot.msgType = sysinfo::ReadUInt8(arg[offset]);
            memcpy(&snapshot.symbol, &arg[offset + msgTypeOffset], symbolOffset);
            for (int i = 0; i < 5; ++i) {
                snapshot.bidPrice[i] = sysinfo::ReadFloat64(
                        &arg[offset + msgTypeOffset + symbolOffset +
                             i * sizeof(FLOAT64)]);
                snapshot.bidSize[i] = sysinfo::ReadUInt32(
                        &arg[offset + msgTypeOffset + symbolOffset +
                             bidPriceOffset +
                             i * sizeof(uint32_t)]);
                snapshot.askPrice[i] = sysinfo::ReadFloat64(
                        &arg[offset + msgTypeOffset + symbolOffset +
                             bidPriceOffset + bidSizeOffset +
                             i * sizeof(FLOAT64)]);
                snapshot.askSize[i] = sysinfo::ReadUInt32(
                        &arg[offset + msgTypeOffset + symbolOffset +
                             bidPriceOffset + bidSizeOffset + askPriceOffset +
                             i * sizeof(uint32_t)]);
            }
            offset += sizeof(Snapshot);

            char *str = new char[symbolOffset + 1];
            memcpy(str, snapshot.symbol, symbolOffset);
            str[symbolOffset] = '\0';
            snapshotMap.insert(std::map<std::string, Snapshot>::value_type(std::string(str), snapshot));
            delete str;

        } else if (type == UPDATE_TYPE) {
            UpdateLevel updateLevel;
            memset(&updateLevel, 0, sizeof(struct UpdateLevel));

            updateLevel.msgType = sysinfo::ReadUInt8(arg[offset]);
            memcpy(&updateLevel.symbol, &arg[offset + msgTypeOffset], symbolOffset);
            updateLevel.side = sysinfo::ReadUInt8(
                    arg[offset + msgTypeOffset + symbolOffset]);
            updateLevel.level = sysinfo::ReadUInt8(
                    arg[offset + msgTypeOffset + symbolOffset +
                        sideOffset]);
            updateLevel.price = sysinfo::ReadFloat64(
                    &arg[offset + msgTypeOffset + symbolOffset +
                         sideOffset + levelOffset]);
            updateLevel.size = sysinfo::ReadUInt32(
                    &arg[offset + msgTypeOffset + symbolOffset +
                         sideOffset + priceOffset]);

            char *str = new char[symbolOffset + 1];
            memcpy(str, updateLevel.symbol, symbolOffset);
            str[symbolOffset] = '\0';

            const std::map<std::string, Snapshot>::iterator &iterator = snapshotMap.find(
                    str);
            if (iterator != snapshotMap.end()) {
                if (updateLevel.side == 1) {
                    iterator->second.bidPrice[updateLevel.level] = updateLevel.price;
                    iterator->second.bidSize[updateLevel.level] = updateLevel.size;
                } else if (updateLevel.side == 2) {
                    iterator->second.askPrice[updateLevel.level] = updateLevel.price;
                    iterator->second.askSize[updateLevel.level] = updateLevel.size;
                }
            }
            offset += sizeof(UpdateLevel);
            delete str;

        } else if (type == DELETE_TYPE) {
            DeleteLevel deleteLevel;
            memset(&deleteLevel, 0, sizeof(struct DeleteLevel));

            deleteLevel.msgType = sysinfo::ReadUInt8(arg[offset]);
            memcpy(&deleteLevel.symbol, &arg[offset + sizeof(deleteLevel.msgType)], symbolOffset);

            char *str = new char[symbolOffset + 1];
            memcpy(str, deleteLevel.symbol, symbolOffset);
            str[symbolOffset] = '\0';

            const std::map<std::string, Snapshot>::iterator &iterator = snapshotMap.find(
                    str);
            if (iterator != snapshotMap.end()) {
                if (deleteLevel.side == 1) {
                    iterator->second.bidPrice[deleteLevel.level] = 0;
                    iterator->second.bidSize[deleteLevel.level] = 0;
                } else if (deleteLevel.side == 2) {
                    iterator->second.askPrice[deleteLevel.level] = 0;
                    iterator->second.askSize[deleteLevel.level] = 0;
                }
            }
            offset += sizeof(DeleteLevel);
            delete str;
        }
    }

}

/**
 * 查询股票信息
 * @param symbol
 * @return
 */
Snapshot Stocks::query(std::string symbol) {
    const std::map<std::string, Snapshot>::iterator &iterator = snapshotMap.find(
            symbol);
    if (iterator != snapshotMap.end()) {
        return iterator->second;
    }
}

