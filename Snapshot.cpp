//
// Created by charles.cxh on 2021/9/4.
//

#include "Snapshot.h"
#include <iostream>

using namespace std;

void Snapshot::show() {
    char *str = new char[7];
    memcpy(str, symbol, 6);
    str[6] = '\0';
    cout << str << "的五档结构" << endl;
    cout << "卖盘:" << endl;
    cout << "卖五： " << askSize[4] << "\t" << askPrice[4] << endl;
    cout << "卖四： " << askSize[3] << "\t" << askPrice[3] << endl;
    cout << "卖三： " << askSize[2] << "\t" << askPrice[2] << endl;
    cout << "卖二： " << askSize[1] << "\t" << askPrice[1] << endl;
    cout << "卖一： " << askSize[0] << "\t" << askPrice[0] << endl;
    cout << "*******************************" << endl;
    cout << "买一： " << bidSize[0] << "\t" << bidPrice[0] << endl;
    cout << "买二： " << bidSize[1] << "\t" << bidPrice[1] << endl;
    cout << "买三： " << bidSize[2] << "\t" << bidPrice[2] << endl;
    cout << "买四： " << bidSize[3] << "\t" << bidPrice[3] << endl;
    cout << "买五： " << bidSize[4] << "\t" << bidPrice[4] << endl;
    delete [] str;
}