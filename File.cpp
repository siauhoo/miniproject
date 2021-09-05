//
// Created by charles.cxh on 2021/9/4.
//

#include "File.h"


static const size_t UPDATE_LEVEL_SIZE = sizeof(UpdateLevel);
static const size_t DELETE_LEVEL_SIZE = sizeof(DeleteLevel);
static const size_t SNAPSHOT_SIZE = sizeof(Snapshot);

/**
* 检查文件是否存在
*/
bool File::exists(const std::string &filePath) {
    return access(filePath.c_str(), F_OK) == 0;
}

/**
    * 打开文件，返回是否成功打开
    */
bool File::open(std::ios_base::openmode mode) {
    if (fileStream.is_open()) {
        close();
    }
    fileStream.open(fileName, mode);
    return fileStream.is_open();
}

/**
* 设置文件的开始读取偏移
*/
void File::seekInputPosition(std::size_t offsetPosition, std::ios_base::seekdir position) {
    fileStream.seekg(offsetPosition, position);
}

/**
 * 是否已经读到end，可用此方法判断文件是否已经读完
 */
bool File::endOfFile() {
    return fileStream.eof();
}


/**
 * 关闭文件流，如果从未打开，则无任何操作
 */
void File::close() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

/**
* 读取指定数量的字符串，如果内容不够，则读完
* offset参数表示开始读取的偏移
* 读取位置置于本次最后读取的内容的结尾
*/
std::unique_ptr<char[]> File::read(std::size_t offset, std::streamsize *size) {
    if (!fileStream.is_open()) {
        throw ("文件读取错误");
    }
    if (offset > 0) {
        seekInputPosition(offset);
    }
    uint8_t head = ReadUInt8(fileStream.peek());
    size_t maxSize = 0;
    if (head == 1) {
        maxSize = SNAPSHOT_SIZE;
    } else if (head == 2) {
        maxSize = UPDATE_LEVEL_SIZE;
    } else if (head == 3) {
        maxSize = DELETE_LEVEL_SIZE;
    } else {
        throw "坏的文件格式";
    }
    std::unique_ptr<char[]> buffer(new(std::nothrow) char[maxSize]);
    fileStream.read(buffer.get(), maxSize);
    *size = fileStream.gcount();
    return buffer;
}

File::File(const std::string &fileName) {
    this->fileName = fileName;
}