//
// Created by hu on 2023/9/10.
//

#include "point_about.h"

using namespace std;

//void testConstPoint(){//此处可以被调用但是无法通过编译
//}

void point_about::testConstPoint() {
    int a = 10;
    const int *p = &a;
//    p = 30;//*p禁止直接修改值，
    int *q = &a;
    *q = 20;
    printf("a = %d\n", a);
    a = 30;
    printf("a = %d,  *p=%d\n", a, *p);
    //*p = 30;  //这么写就是错的
    //输出结果是：
    //a = 20
    //a = 30

    int b = 40;
    p = &b;//修改了p指向的值，不会修改a的值；
    printf("a = %d,  *p=%d\n", a, *p);
}

int a = 4;
int aa= 4;

int &f(int x) {
    a = a + x;
    return a;
}
int ff(int x) {
    aa = aa + x;
    return aa;
}


void point_about::testModifyArgument(){
    int t = 5;
    cout << f(t) << endl;  //a = 9
    f(t) = 20;           //a = 20
    cout << f(t) << endl;  //t = 5,a = 20  a = 25
    t = f(t);            //a = 30 t = 30
    cout << f(t) << endl;  //t = 60
    cout << "###############" << endl;

    int t1 = 5;
    cout << ff(t1) << endl;  //a = 9
//    ff(t) = 20;           //a = 20
//    cout << ff(t1) << endl;  //t = 5,a = 20  a = 25
    t1 = ff(t1);            //a = 30 t = 30
    cout << ff(t1) << endl;  //t = 60
    cout << "###############" << endl;
}

/**
 * a=10,  &a=-81790976  *p=10  p=-81790976
 * a=20,  &a=-81790976  *p=20  p=-81790976
 * &(*p)=729807160,  *(&p)=729807160
 * *p10=20
   *p11=20
 * (unsigned int 10) + (int -20) <= 5
 */
void point_about::initPoint() {
    //指针是一个变量;
    unsigned int a = 10;
    //&p是指针的地址，用来存放指针p，而指针p来存放变量a的地址，也就是&a，
    //*p在C语言中是解引，意思是告诉编译器取出该地址存放的内容
    unsigned int *p = NULL;//指针是一个变量  针对32位编译器而言，既然任何指针都只占用4个字节
    p = &a;
    printf("a=%d,  &a=%d  *p=%d  p=%d\n",a,&a,*p, p);
    *p = 20;
    printf("a=%d,  &a=%d  *p=%d  p=%d\n",a,&a,*p, p);
    printf("&(*p)=%d,  *(&p)=%d\n",&(*p), *(&p));

    int *pd = reinterpret_cast<int *>(a);
    unsigned int *p10 = &a;//必须使用 unsigned， 否则报错
    printf("*p10=%d\n",*p10);//此处不能直接调用 **p10;
    unsigned int **p11 = &p10;//指针的指针  必须使用 unsigned， 否则报错
    printf("*p11=%d， **p11=&d\n",*p11,**p11);

//    以下代码有可能出问题，所以运行时注掉了
//    unsigned int *p1=(unsigned int*)(6422216);//对内存6422216中填入一个数据125  todo 所有内存地址不能随便指定，必须是计算机已经分配的内存，否则计算机会认为指针越界而被操作系统杀死即程序提前终止。
//    *p1=125;//*p在C语言中是解引，意思是告诉编译器取出该地址存放的内容
//    *(unsigned int*)(6422216)=125;//与上一段代码结果一样，
//    int *p2 = (int *)(0xff96);//获取内存地址 0xff96 指针

    int b = -20;
    a + b > 0 ? printf("(unsigned int 10) + (int -20) > 5\n") : printf("(unsigned int 10) + (int -20) <= 5\n");
}

