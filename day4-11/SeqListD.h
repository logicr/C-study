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
//���Գ�ʼ������
void testInit();
//��������λ�ò���ɾ��
void testInsert();
//����β�����ݺ���
//������������������ա�empty
void testAll();
//++++++++++++++++++++++++++++++++


//+++++++++++++++++++++++++++++++++++
//function declare
void tsetPushBack();
//���ݺ���
int * expand(PSeqListD ps);
//��ӡ����
void SeqListDprint(PSeqListD ps);
//ʵ�ֶ�̬˳�������½ӿڣ�
void SeqListDInit(PSeqListD ps, int capacity);
void SeqListDPushBack(PSeqListD ps, DataType data);
void SeqListDPopBack(PSeqListD ps);
void SeqListDInsert(PSeqListD ps, int pos, DataType data);
void SeqListDErase(PSeqListD ps, int pos);

// ��ȡԪ�ظ��� 
int SeqListDSize(PSeqListD ps);

// ��ȡ˳�������� 
int SeqListDCapacity(PSeqListD ps);
int SeqListDEmpty(PSeqListD ps);

// ��˳����е�Ԫ����� ע�⣺���ı�˳���ռ�Ĵ�С 
void SeqListDClear(PSeqListD ps);
void SeqListDDestroy(PSeqListD ps);

// ��˳���������� 
int CheckCapacity(PSeqListD ps);






# endif //__SEQLIST_H__