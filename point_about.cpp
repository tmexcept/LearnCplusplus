//
// Created by hu on 2023/9/10.
//

#include "point_about.h"

using namespace std;

//void testConstPoint(){//此处可以被调用但是无法通过编译
//}

//todo 常量指针说的是不能通过这个指针改变变量的值，但是还是可以通过其他的引用来改变变量的值的
// 常量指针指向的值不能改变，但是这并不是意味着指针本身不能改变，常量指针可以指向其他的地址。

void point_about::testConstPoint() {
    int aa = 10;
    int *pp = &aa;
    *pp = 20;//修改指针指向的值
//    int ppp = &aa;//错误，返回的是一个指针

    int a = 10;
    const int *p = &a;
    printf("a = %d,  *p=%d\n", a, *p);
    int b = 40;
    //*p = 30;  //这么写就是错的
    p = &b;//修改了p指向的值，不会修改a的值；
    printf("a = %d,  *p=%d\n", a, *p);

//todo 指针常量是指指针本身是个常量，不能在指向其他的地址;
// 指针常量指向的地址不能改变，但是地址中保存的数值是可以改变的，可以通过其他指向改地址的指针来修改
    int * const q = &a;
    *q = 20;
    printf("a = %d\n", a);
    a = 30;
    printf("a = %d,  *p=%d\n", a, *p);
    //输出结果是：
    //a = 20
    //a = 30
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



// todo void 指针
//在很多时候指针在申明的时候可能并不知道是什么类型或者该指针指向的数据类型有多种再或者程序员仅仅是想通过一个指针来操作一段内存空间。
// 这个时候可以将指针申明为void类型
//由于void指针没有空间大小属性，因此void指针也没有++操作。  不具有解引时的空间大小
void void_reference_test(){
    int a=10;
    void *p;
    p=&a;
    printf("p=%d\n",*(int*)p/*  *p   */);//todo 此处必须做数据类型转换
}

//todo  结构体指针
typedef struct STUDENT
{
    int      name;
    int    gender;
    long  test;
    char char_a;
}stu;
//变量的定义最好添加前限定名，比如此处如果写 a ，会与其他 cpp 中的a冲突
int int_array_a[]={10,20,30,0xffffff,50};
void structCast()
{
    stu *student;
    student=(stu*)int_array_a;
    /**
     *  student->name=10
        student->gender=20
        student->test=30
        student->char_a=-1
     */
    printf("student->name=%d\n",student->name);
    printf("student->gender=%d\n",student->gender);
    printf("student->test=%d\n",student->test);
    printf("student->char_a=%d\n",student->char_a);
}

//todo 函数指针
//函数指针的解引操作与普通的指针有点不一样，对于普通的指针而言，解引只需要根据类型来取出数据即可;
// 但函数指针是要调用一个函数，其解引不可能是将数据取出，实际上函数指针的解引本质上是执行函数的过程，
// 只是这个执行函数是使用的call指令并不是之前的函数，而是函数指针的值，
// 即函数的地址。其实执行函数的过程本质上也是利用call指令来调用函数的地址，因此函数指针本质上就是保存函数执行过程的首地址
typedef struct TFT_DISPLAY
{
    int   pix_width;
    int   pix_height;
    int   color_width;
    void (*init)(void);
    void (*fill_screen)(int color);
    void (*tft_test)(void);

}tft_display;

static void init(void)
{
    printf("the display is initialed\n");
}

static void fill_screen(int color)
{
    printf("the display screen set 0x%x\n",color);
}

tft_display mydisplay=
        {
                .pix_width=320,
                .pix_height=240,
                .color_width=24,
                .init=init,
                .fill_screen=fill_screen,
        };

void point_test_function_reference()
{

    mydisplay.init();
    mydisplay.fill_screen(0xfff);
}