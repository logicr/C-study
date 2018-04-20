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
//测试复杂链表的函数
void testPCSLNode();
//PCSLNode PCSLgetNode(int data);
//void PCSListPushBack(PCSLNode* pcslHead, DataType data);


//测试函数
void test();

//++++++++++++++++++++++++++
//打印函数
void SListPrint(PNode PHead);


//+++++++++++++++++++++++++++++++++++++++
//创建节点
PNode getNode(int data);

//++++++++++++++++++++++++++++++++
// 销毁链表 
void SListDestroy(PNode* pHead);



//+++++++++++++++++++++++++++++++++++=
// 链表的初始化 
void SListInit(PNode* pHead);


//+++++++++++++++++++++++++++++++++++++
// 尾插 
void SListPushBack(PNode* pHead, DataType data);
// 逆序打印单链表 
void PrintSListFromTail2Head(PNode pHead);

// 删除链表的非尾结点，要求：不能遍历链表 
void DeleteListNotTailNode(PNode pos);

// 在链表pos位置前插入值到data的结点 
void InesrtPosFront(PNode pos, DataType data);

// 查找链表的中间结点，要求只能遍历一次链表 
PNode FindMiddleNode(PNode pHead);

// 查找链表的倒数第K个结点，要求只能遍历一次链表 
PNode FindLastKNode(PNode pHead, int K);

// 删除链表的倒数第K个结点，要求只能遍历一次链表 
PNode DeleteLastKNode(PNode pHead, int K);

// 用单链表实现约瑟夫环 
void JosephCircle(PNode* pHead, const int M);

// 链表的逆置--三个指针 
void ReverseSList(PNode* pHead);

// 链表的逆置--头插法 
PNode ReverseSListOP(PNode pHead);

// 用冒泡排序思想对单链表进行排序 
void BubbleSort(PNode pHead);

// 合并两个有序单链表，合并后依然有序 
PNode MergeSList(PNode pHead1, PNode pHead2);

// 判断两个单链表是否相交---链表不带环 
int IsSListCross(PNode pHead1, PNode pHead2);

// 求两个单链表相交的交点---链表不带环 
PNode GetCorssNode(PNode pHead1, PNode pHead2);






//+++++++++++++++++++++++++++++++++++++++++++++++++++++
//附加
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

// 判断两个不带环单链表是否相交
int IsSListCross(PNode pHead1, PNode pHead2);

// 获取两个不带环单链表相交的交点
PNode GetCorssNode(PNode pHead1, PNode pHead2);

// 判断链表是否带环，返回相遇点---注意推导公式
PNode IsListWithCircle(PNode pHead1);

// 获取环的入口点
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode);

// 获取环的长度
int GetCircleLen(PNode pMeetNode);

// 判断两个链表是否相交，链表可能带环
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2);

// 复杂链表复制
//PCSLNode CopyComplexList(PCSLNode pHead);





# endif //__TASK_H__