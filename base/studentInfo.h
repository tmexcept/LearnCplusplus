//
// Created by hu on 2023/9/14.
//
#include <string>

#ifndef LEARNCPLUSPLUS_STUDENTINFO_H
#define LEARNCPLUSPLUS_STUDENTINFO_H

using namespace std;


class Student {
private:
    string  info = "AAA"; // 旧变量
public:
    string getInfo();
    string & getInfo_front();

    void testInfoSetMethod();
};

#endif //LEARNCPLUSPLUS_STUDENTINFO_H
