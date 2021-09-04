#include <iostream>


#include <array>
#include <memory>
#include <type_traits>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Stocks.h"
#include "File.h"


using namespace std;

//chunkSize代表文件读取buffer的大小，取倍数方便跨区处理
static size_t chunkSize = sizeof(Snapshot) * sizeof(UpdateLevel) * sizeof(DeleteLevel);

/**
 * 测试准备文件
 */
static void prepare() {

    //初始化对象snapshot
    Snapshot snapshot;
    snapshot.msgType = 1;
    memcpy(snapshot.symbol, "600000", 6 * sizeof(char));
    for (int i = 0; i < 5; ++i) {
        snapshot.bidPrice[i] = 100 + i;
        snapshot.bidSize[i] = 1000 * i;
        snapshot.askPrice[i] = 100 - i;
        snapshot.askSize[i] = 1000 * i;
    }

    //对象updateLevel
    UpdateLevel updateLevel;
    updateLevel.msgType = 2;
    memcpy(updateLevel.symbol, "600000", 6 * sizeof(char));
    updateLevel.side = 1;
    updateLevel.price = 100000;
    updateLevel.size = 50;
    updateLevel.level = 0;

    //deleteLevel对象
    DeleteLevel deleteLevel;
    deleteLevel.msgType = 2;
    memcpy(deleteLevel.symbol, "600000", 6 * sizeof(char));
    deleteLevel.side = 2;
    deleteLevel.level = 4;

    //写文件
    FILE *fp;
    fp = fopen("test.bin", "wb");
    fwrite(&snapshot, sizeof(snapshot), 1, fp);
    fwrite(&updateLevel, sizeof(updateLevel), 1, fp);
    fwrite(&deleteLevel, sizeof(deleteLevel), 1, fp);
    fclose(fp);
}


int main() {

    //判断系统是小端序
    assert(sysinfo::IsLittleEndian());

    //初始化文件对象
    prepare();

    //文件读取到缓冲区

    File a = File("test.bin");

    if (!a.exists("test.bin")) {
        throw "文件不存在";
    }

    a.open(std::ifstream::binary | std::ifstream::in | std::ifstream::out);
    Stocks stocks;
    while (!a.endOfFile()) {
        size_t offset = 0;
        std::streamsize size = 0;
        unique_ptr<char[]> buf = a.read(chunkSize, offset, &size);
        if (size == 0) {
            cout << "[WARN]文件读取内容为空" << endl;
            break;
        }
        stocks.deserialize(buf, size);
        offset += chunkSize;

    }
    a.close();

    string code = "600000";
    Snapshot sp = stocks.query(code);
    cout << code << "的五档结构" << endl;
    cout << "卖盘:" << endl;
    cout << "卖五： " << sp.askSize[4] << "\t" << sp.askPrice[4] << endl;
    cout << "卖四： " << sp.askSize[3] << "\t" << sp.askPrice[3] << endl;
    cout << "卖三： " << sp.askSize[2] << "\t" << sp.askPrice[2] << endl;
    cout << "卖二： " << sp.askSize[1] << "\t" << sp.askPrice[1] << endl;
    cout << "卖一： " << sp.askSize[0] << "\t" << sp.askPrice[0] << endl;
    cout << "*******************************" << endl;
    cout << "买一： " << sp.bidSize[0] << "\t" << sp.bidPrice[0] << endl;
    cout << "买二： " << sp.bidSize[1] << "\t" << sp.bidPrice[1] << endl;
    cout << "买三： " << sp.bidSize[2] << "\t" << sp.bidPrice[2] << endl;
    cout << "买四： " << sp.bidSize[3] << "\t" << sp.bidPrice[3] << endl;
    cout << "买五： " << sp.bidSize[4] << "\t" << sp.bidPrice[4] << endl;
}


