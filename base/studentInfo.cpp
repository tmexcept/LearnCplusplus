//
// Created by hu on 2023/9/14.
//
#include "studentInfo.h"
#include <iostream>

using namespace std;


// TODO 第一种情况【getInfo函数的info 与 main函数的result 是旧与新的两个变量而已，
//  他们是值传递，所以右值修改时，影响不了里面的旧变量】
string Student::getInfo() {
    return this->info;
}

// TODO 第二种情况【getInfo_front函数的info 与 main函数的result 是引用关系，一块内存空间
//  有多个别名而已，所以右值修改时，直接影响旧变量】
string & Student::getInfo_front() {
    return this->info;
}

void Student::testInfoSetMethod() {

    // TODO 第一种情况
    getInfo() = "九阳神功";
    string result = getInfo();
    cout << "第一种情况:" << result << endl;

    // TODO 第二种情况
    getInfo_front() = "三分归元气"; // 右值 修改内容
    result = getInfo_front(); // 左值 获取内容
    cout << "第二种情况:" << result << endl;

    result = getInfo();
    cout << "第一种情况:" << result << endl;
}
