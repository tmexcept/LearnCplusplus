
#include "point_about.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "base/studentInfo.h"

using namespace std;

int main() {
    point_about pointAbout;
    pointAbout.testPointAdd();
//    pointAbout.testConstPoint();//必须把 point_about.cpp 链接进 cMakeLists.txt 文件，否则编译不通过
//    pointAbout.testModifyArgument();
//    pointAbout.initPoint();
//    structCast();

    Student student;
    student.testInfoSetMethod();

    vector<int> a ={1,3,3,4,5,6,6,7};
    auto it_1 = a.begin();
    vector<int>::iterator it_2 = a.end();
    vector<int>::iterator new_end;

    //去重过程实际上就是不停的把后面不重复的元素移到前面来，也可以说是用不重复的元素占领重复元素的位置
    new_end = unique(it_1,it_2); //注意unique的返回值，返回不重复元素的下一个元素的index
    cout<< "new_end=" << new_end[0] << endl;
    cout<<"删除相邻重复元素 a : ";
    for(int i = 0 ; i < a.size(); i++)
        cout<<a[i];
    cout<<endl;

    a.erase(new_end,it_2);
    cout<<"删除重复元素后的 a : ";
    for(int i = 0 ; i < a.size(); i++)
        cout<<a[i];
    cout<<endl;

    return 0;
}
