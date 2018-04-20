# ifndef __TASK_H__
# define __TASK_H__

//+++++++++++++++++++++++
// Head
# include <stdio.h>
# include <malloc.h>
# include <assert.h>


//++++++++++++++++++++++++++
//declare
typedef int DataType;
typedef struct MyStruct
{
	int data;
	struct MyStruct * next;
}Node,*PNode;
PNode pHead;
PNode pHead2;


//+++++++++++++++++++++++++
//function
//���Ը�������ĺ���
void testPCSLNode();
//PCSLNode PCSLgetNode(int data);
//void PCSListPushBack(PCSLNode* pcslHead, DataType data);


//���Ժ���
void test();

//++++++++++++++++++++++++++
//��ӡ����
void SListPrint(PNode PHead);


//+++++++++++++++++++++++++++++++++++++++
//�����ڵ�
PNode getNode(int data);

//++++++++++++++++++++++++++++++++
// �������� 
void SListDestroy(PNode* pHead);



//+++++++++++++++++++++++++++++++++++=
// ����ĳ�ʼ�� 
void SListInit(PNode* pHead);


//+++++++++++++++++++++++++++++++++++++
// β�� 
void SListPushBack(PNode* pHead, DataType data);
// �����ӡ������ 
void PrintSListFromTail2Head(PNode pHead);

// ɾ������ķ�β��㣬Ҫ�󣺲��ܱ������� 
void DeleteListNotTailNode(PNode pos);

// ������posλ��ǰ����ֵ��data�Ľ�� 
void InesrtPosFront(PNode pos, DataType data);

// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindMiddleNode(PNode pHead);

// ��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindLastKNode(PNode pHead, int K);

// ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
PNode DeleteLastKNode(PNode pHead, int K);

// �õ�����ʵ��Լɪ�� 
void JosephCircle(PNode* pHead, const int M);

// ���������--����ָ�� 
void ReverseSList(PNode* pHead);

// ���������--ͷ�巨 
PNode ReverseSListOP(PNode pHead);

// ��ð������˼��Ե������������ 
void BubbleSort(PNode pHead);

// �ϲ��������������ϲ�����Ȼ���� 
PNode MergeSList(PNode pHead1, PNode pHead2);

// �ж������������Ƿ��ཻ---�������� 
int IsSListCross(PNode pHead1, PNode pHead2);

// �������������ཻ�Ľ���---�������� 
PNode GetCorssNode(PNode pHead1, PNode pHead2);






//+++++++++++++++++++++++++++++++++++++++++++++++++++++
//����
void SListInit(PNode* pHead);
void SListPushBack(PNode* pHead, DataType data);
void SListPopBack(PNode* pHead);
void SListPushFront(PNode* pHead, DataType data);
void SListPopFront(PNode* pHead);
PNode SListFind(PNode pHead, DataType data);
void SListInsert(PNode* pHead, PNode pos, DataType data);
void SListErase(PNode* pHead, PNode pos);
int SListSize(PNode pHead);
int SListEmpty(PNode pHead);
void SListDestroy(PNode* pHead);


/////////////////////////////////////////////////////
//
void PrintSListFromTail2Head(PNode pHead);
void DeleteListNotTailNode(PNode pos);
void InesrtPosFront(PNode pos, DataType data);
PNode FindMiddleNode(PNode pHead);
PNode FindLastKNode(PNode pHead, int K);
void JosephCircle(PNode* pHead, const int M);
void ReverseSList(PNode* pHead);
PNode ReverseSListOP(PNode pHead);
void BubbleSort(PNode pHead);
PNode MergeSList(PNode pHead1, PNode pHead2);

// �ж������������������Ƿ��ཻ
int IsSListCross(PNode pHead1, PNode pHead2);

// ��ȡ�����������������ཻ�Ľ���
PNode GetCorssNode(PNode pHead1, PNode pHead2);

// �ж������Ƿ����������������---ע���Ƶ���ʽ
PNode IsListWithCircle(PNode pHead1);

// ��ȡ������ڵ�
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode);

// ��ȡ���ĳ���
int GetCircleLen(PNode pMeetNode);

// �ж����������Ƿ��ཻ��������ܴ���
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2);

// ����������
//PCSLNode CopyComplexList(PCSLNode pHead);





# endif //__TASK_H__