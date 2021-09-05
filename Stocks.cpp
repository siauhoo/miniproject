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
using namespace std;

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
                         sideOffset + levelOffset + priceOffset]);

            char *str = new char[symbolOffset + 1];
            memcpy(str, updateLevel.symbol, symbolOffset);
            str[symbolOffset] = '\0';

            const std::map<std::string, Snapshot>::iterator &iterator = snapshotMap.find(
                    str);
            if (iterator != snapshotMap.end()) {
                cout << "更新" << str << (int) updateLevel.side << "(1-Bid 2-Ask)" << (int) updateLevel.level
                     << updateLevel.size << " " << updateLevel.price << endl;

                cout << "修改前" << endl;
                iterator->second.show();

                if (updateLevel.side == 1) {
                    iterator->second.bidPrice[updateLevel.level - 1] = updateLevel.price;
                    iterator->second.bidSize[updateLevel.level - 1] = updateLevel.size;
                    for (int i = 0; i < 4; i++) {
                        if (iterator->second.bidSize[i] == 0) {
                            int j = i;
                            while (iterator->second.bidSize[j] == 0)
                                j++;
                            if (iterator->second.bidSize[j] != 0) {
                                uint32_t tmp_size = iterator->second.bidSize[j];
                                iterator->second.bidSize[j] = iterator->second.bidSize[i];
                                iterator->second.bidSize[i] = tmp_size;

                                double tmp_price = iterator->second.bidPrice[j];
                                iterator->second.bidPrice[j] = iterator->second.bidPrice[i];
                                iterator->second.bidPrice[i] = tmp_price;
                                i = j;
                            }
                        }
                    }
                } else if (updateLevel.side == 2) {
                    iterator->second.askPrice[updateLevel.level - 1] = updateLevel.price;
                    iterator->second.askSize[updateLevel.level - 1] = updateLevel.size;
                    for (int i = 0; i < 4; i++) {
                        if (iterator->second.askSize[i] == 0) {
                            int j = i;
                            while (iterator->second.askSize[j] == 0)
                                j++;
                            if (iterator->second.askSize[j] != 0) {
                                uint32_t tmp_size = iterator->second.askSize[j];
                                iterator->second.askSize[j] = iterator->second.askSize[i];
                                iterator->second.askSize[i] = tmp_size;

                                double tmp_price = iterator->second.askPrice[j];
                                iterator->second.askPrice[j] = iterator->second.askPrice[i];
                                iterator->second.askPrice[i] = tmp_price;
                                i = j;
                            }
                        }
                    }
                }

                cout << "修改后" << endl;
                iterator->second.show();
            }
            offset += sizeof(UpdateLevel);

            delete[] str;
        } else if (type == DELETE_TYPE) {
            DeleteLevel deleteLevel;
            memset(&deleteLevel, 0, sizeof(struct DeleteLevel));

            deleteLevel.msgType = sysinfo::ReadUInt8(arg[offset]);
            memcpy(&deleteLevel.symbol, &arg[offset + sizeof(deleteLevel.msgType)], symbolOffset);
            deleteLevel.side = sysinfo::ReadUInt8(
                    arg[offset + msgTypeOffset + symbolOffset]);
            deleteLevel.level = sysinfo::ReadUInt8(
                    arg[offset + msgTypeOffset + symbolOffset +
                        sideOffset]);

            char *str = new char[symbolOffset + 1];
            memcpy(str, deleteLevel.symbol, symbolOffset);
            str[symbolOffset] = '\0';

            const std::map<std::string, Snapshot>::iterator &iterator = snapshotMap.find(
                    str);
            if (iterator != snapshotMap.end()) {

                cout << "删除" << str << (int) deleteLevel.side << "(1-Bid 2-Ask)" << (int) deleteLevel.level
                     << endl;
                cout << "删除前" << endl;
                iterator->second.show();

                if (deleteLevel.side == 1) {
                    if (deleteLevel.level == 5) {
                        iterator->second.bidPrice[4] = 0;
                        iterator->second.bidSize[4] = 0;
                    } else {
                        for (int i = deleteLevel.level; i < 5; ++i) {
                            iterator->second.bidPrice[i - 1] = iterator->second.bidPrice[i];
                            iterator->second.bidSize[i - 1] = iterator->second.bidSize[i];
                        }
                        iterator->second.bidPrice[4] = 0;
                        iterator->second.bidSize[4] = 0;
                    }
                } else if (deleteLevel.side == 2) {
                    if (deleteLevel.level == 5) {
                        iterator->second.askPrice[4] = 0;
                        iterator->second.bidSize[4] = 0;
                    } else {
                        for (int i = deleteLevel.level; i < 5; ++i) {
                            iterator->second.askPrice[i - 1] = iterator->second.askPrice[i];
                            iterator->second.askSize[i - 1] = iterator->second.askSize[i];
                        }
                        iterator->second.askPrice[4] = 0;
                        iterator->second.askSize[4] = 0;
                    }
                }

                cout << "删除后" << endl;
                iterator->second.show();
            }
            offset += sizeof(DeleteLevel);
            delete[] str;
        }
    }

}

/**
 * 查询股票信息
 * @param symbol
 * @return
 */
Snapshot *Stocks::query(std::string symbol) {
    const std::map<std::string, Snapshot>::iterator &iterator = snapshotMap.find(
            symbol);
    if (iterator != snapshotMap.end()) {
        return &iterator->second;
    }
    return NULL;
}

