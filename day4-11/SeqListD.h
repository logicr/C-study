# ifndef __SEQLIST_H__
# define __SEQLIST_H__


//+++++++++++++++++++++++++++++++
//head


//+++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++
//type declare
typedef int DataType;
typedef struct Seqlist {
	int *arr;
	int size;
	int capacity;
}SeqListD, *PSeqListD;
SeqListD s;
//+++++++++++++++++++++++++++++
# include <stdio.h>
# include <stdlib.h>

//++++++++++++++++++++++++++++++++++
//test function
//测试初始化函数
void testInit();
//测试任意位置插入删除
void testInsert();
//测试尾插扩容函数
//测试容量、个数、清空、empty
void testAll();
//++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++
//function declare
void tsetPushBack();
//扩容函数
int * expand(PSeqListD ps);
//打印函数
void SeqListDprint(PSeqListD ps);
//实现动态顺序表的以下接口：
void SeqListDInit(PSeqListD ps, int capacity);
void SeqListDPushBack(PSeqListD ps, DataType data);
void SeqListDPopBack(PSeqListD ps);
void SeqListDInsert(PSeqListD ps, int pos, DataType data);
void SeqListDErase(PSeqListD ps, int pos);

// 获取元素个数 
int SeqListDSize(PSeqListD ps);

// 获取顺序表的容量 
int SeqListDCapacity(PSeqListD ps);
int SeqListDEmpty(PSeqListD ps);

// 将顺序表中的元素清空 注意：不改变顺序表空间的大小 
void SeqListDClear(PSeqListD ps);
void SeqListDDestroy(PSeqListD ps);

// 对顺序表进行增容 
int CheckCapacity(PSeqListD ps);






# endif //__SEQLIST_H__