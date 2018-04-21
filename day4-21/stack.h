# ifndef __STACK_H__
# define __STACK_H__



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//HEAD
# include <stdio.h>
# include <malloc.h>
# include <assert.h>






//#define MAX 400;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//定义一个栈的结构体
typedef char DataType;
//typedef int DataType;
typedef struct MyStruct
{
	DataType size;
	DataType* data;
	int top;
}stack;

stack s;



//+++++++++++++++++++++++++++++++++++++++++++++++++++
//FUNCTION



void test();
void StackPush(stack * s, DataType data);
void StackInit(stack * s);
DataType StackSize(stack * s);
DataType StackTop(stack * s);
void StackPop(stack * s);



# endif//__STACH_H__ 