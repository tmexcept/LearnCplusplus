//
// Created by hu on 2023/9/10.
//

#ifndef LEARNCPLUSPLUS_POINT_ABOUT_H
#define LEARNCPLUSPLUS_POINT_ABOUT_H

#include <iostream>

class point_about {
public:
    void testConstPoint();
    void testModifyArgument();
    void initPoint();
};

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

#endif //LEARNCPLUSPLUS_POINT_ABOUT_H
