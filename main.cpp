
#include "point_about.h"

int main() {
    point_about pointAbout;
//    pointAbout.testConstPoint();//必须把 point_about.cpp 链接进 cMakeLists.txt 文件，否则编译不通过
//    pointAbout.testModifyArgument();
    pointAbout.initPoint();

    structCast();

    return 0;
}
