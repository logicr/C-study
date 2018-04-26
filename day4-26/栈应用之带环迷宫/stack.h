//# ifndef __STACK_H__
//# define __STACK_H__
#pragma once


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//HEAD
# include <stdio.h>
# include <malloc.h>
# include <assert.h>

# define R 6
# define L 6
//# define R 4
//# define L 4



//#define MAX 400;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//定义一个栈的结构体
//typedef char DataType;
typedef int DataType;
typedef struct posi
{
	DataType x;
	DataType y;
}position;
position entry;
typedef struct maze
{
	int m[R][L];
}Maze;
Maze m;

typedef struct MyStruct
{
	int size;
	position *po;
	int top;
}stack;



void test();
void StackPush(stack * s, position* data);
void StackInit(stack * s);
DataType StackSize(stack * s);
position StackTop(stack * s);
void StackPop(stack * s);
int StackEmpty(stack * s);



//maze.h
void PrintMaze(Maze* m, int map[][L]);
void InitMaze(Maze* m, int map[][L]);//2
int IsValidEntry(Maze* m, position entry);//3
int IsPass(Maze* m, position cur, position tmp);
int IsExit(Maze* m, position cur, position entry);
void PassMaze(Maze* m, position entry, stack* s);//1




//# endif//__STACH_H__ 