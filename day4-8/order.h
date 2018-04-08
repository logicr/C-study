# ifndef __ORDER_H__
# define __ORDER_H__




typedef int DataType;
#define MAX_SIZE 10 


//++++++++++++++++++++++++++++++++++++++++++++++++++++++=
//head
# include <stdio.h>
# include <assert.h>
# include <memory.h>


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
//�ṹ
typedef struct SeqList
{
	DataType _array[MAX_SIZE];
	int _size; // ��ʾ˳�������ЧԪ�صĸ��� 
}SeqList, *PSeqList;

typedef struct SeqList* PSeqList;
typedef struct SeqList SeqList;
SeqList s;

///////////////////////////////////////////////////////////////////// 
// ��������

//���Ժ���
void test();
// ˳���ĳ�ʼ�� 
void SeqListInit(PSeqList ps);

// ˳����β�� 
void SeqListPushBack(PSeqList ps, DataType data);

// ˳����βɾ 
void SeqListPopBack(PSeqList ps);

// ˳����ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data);

// ˳����ͷɾ 
void SeqListPopFront(PSeqList ps);

// ˳���posλ�ò���Ԫ��data 
void SeqListInsert(PSeqList ps, int pos, DataType data);

// ɾ��˳���posλ��Ԫ�� 
void SeqListErase(PSeqList ps, int pos);

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void Remove(PSeqList ps, DataType data);

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void RemoveAll(PSeqList ps, DataType data);

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е�λ�ã����򷵻�-1 
int SeqListFind(PSeqList ps, DataType data);

// ��ȡ˳�����Ԫ�صĸ��� 
int SeqListSize(PSeqList ps);



////////////////////////////////////////////////// 
//�������� 
// ��ӡ˳��� 
void PrintSeqList(PSeqList ps);

// ʹ��ð�������˳����е�Ԫ�ؽ������� 
void BubbleSort(PSeqList ps);
void swap(int *po, int *pt);

// ʹ��ѡ�������˳����е�Ԫ�ؽ������� 
void SelectSort(PSeqList ps);





# endif //__ORDER_H__