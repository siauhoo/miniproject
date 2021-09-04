//
// Created by charles.cxh on 2021/9/4.
//

#ifndef MINIPROJECT_FILE_H
#define MINIPROJECT_FILE_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>
#include <sstream>
#include <unistd.h>

#include<sys/stat.h>

class File {

protected:
    std::fstream fileStream;
    std::string fileName;

public:
    /**
     * 检查文件是否存在
     */
    static bool exists(const std::string &filePath);

    /**
    * 打开文件，返回是否成功打开
    */
    bool open(std::ios_base::openmode mode);

    /**
    * 设置文件的开始读取偏移
    */
    void seekInputPosition(std::size_t offsetPosition, std::ios_base::seekdir position = std::ios::beg);

    /**
     * 是否已经读到end，可用此方法判断文件是否已经读完
     */
    bool endOfFile();


    /**
     * 关闭文件流，如果从未打开，则无任何操作
     */
    void close();

    /**
    * 读取指定数量的字符串，如果内容不够，则读完
    * offset参数表示开始读取的偏移
    * 读取位置置于本次最后读取的内容的结尾
    */
    std::unique_ptr<char[]> read(std::size_t maxSize, std::size_t offset = 0, std::streamsize *size = 0);


    explicit File(const std::string &fileName);
};


#endif //MINIPROJECT_FILE_H
