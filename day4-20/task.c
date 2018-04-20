#pragma warning(disable:4996)
# include "task.h"

void test()
{
	SListInit(&pHead);
	//测尾插、打印
	/*SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 9);
	SListPrint(pHead);*/


	//++++++++++++++++++++
	//逆序打印
	//PrintSListFromTail2Head(pHead);
	//删除非尾巴节点

	//+++++++++++=+++++
	//PNode pos = pHead;// ->next->next;
	//DeleteListNotTailNode(pos);
	//SListPrint(pHead);

	//++++++++++++++++++++
	//z在pos插入data的节点
	//PNode pos = pHead->next->next;//3
	//pos = pHead;
	//InesrtPosFront(pos, 7);
	//SListPrint(pHead);

	//++++++++++++++++++++++++
	//找中间节点
	//printf("%d\n", FindMiddleNode(pHead)->data);

	//++++++++++++++++++++++++++
	//找倒数K节点
	//printf("%d\n", FindLastKNode(pHead,1)->data);

	//+++++++++++++++++++++++++++++++
	//删除倒数第K个节点
	//DeleteLastKNode(pHead, 3);
	////printf("%d\n", DeleteLastKNode(pHead,7)->data);
	//SListPrint(pHead);
	
	//+++++++++++++++++++
	//约瑟夫环
	//JosephCircle(&pHead, 8);
	//SListPrint(pHead);

	//+++++++++++++++++++
	//
	//ReverseSListOP(pHead);
	//SListPrint(pHead);
	//SListPrint(ReverseSListOP(pHead));
	//ReverseSList(&pHead);
	//SListPrint(pHead);

	//=+++++++++++++++++++++++
	//冒泡
	//SListPushBack(&pHead, 9);
	//SListPushBack(&pHead, 5);
	////SListPushBack(&pHead, 2);
	////SListPushBack(&pHead, 8);
	//SListPrint(pHead);
	//BubbleSort(pHead);
	//SListPrint(pHead);

	//++++++++++++++++++++++
	//合并两个有序链表
	//SListPushBack(&pHead, 1);
	//SListPushBack(&pHead, 2);
	//SListPushBack(&pHead, 3);
	//SListPushBack(&pHead, 4);
	//SListPushBack(&pHead, 8);
	//SListPushBack(&pHead, 9);
	////SListPushBack(&pHead2, 1);
	//SListPushBack(&pHead2, 2);
	//SListPushBack(&pHead2, 3);
	//SListPushBack(&pHead2, 4);
	//SListPushBack(&pHead2, 8);
	//SListPushBack(&pHead2, 9);
	//SListPrint(pHead);
	//SListPrint(pHead2);
	//PNode pos = MergeSList(pHead,pHead2);
	//+++++++++++++++++++++++++++++++++
	//SListPrint(pos);
	

	//++++++++++++++++++++++++++++++++
	//测试无环找节点
	//SListPushBack(&pHead, 1);
	//SListPushBack(&pHead, 2);
	//SListPushBack(&pHead, 3);
	//SListPushBack(&pHead, 4);
	//SListPushBack(&pHead, 8);
	//SListPushBack(&pHead, 9);
	////SListPushBack(&pHead2, 1);
	//SListPushBack(&pHead2, 5);
	//SListPushBack(&pHead2, 3);
	//SListPushBack(&pHead2, 4);
	//SListPushBack(&pHead2, 8);
	//SListPushBack(&pHead2, 1);

	//pHead->next->next->next->next->next->next = pHead2->next->next->next->next;
	//SListPrint(pHead);
	//SListPrint(pHead2);
	//printf("%d\n", IsSListCross(pHead, pHead2));

	//+++++++++++++++++++++++++++++++++++++++++++++
	//判断带环否，返回交点
	//SListPushBack(&pHead, 1);
	//SListPushBack(&pHead, 2);
	//SListPushBack(&pHead, 3);
	//SListPushBack(&pHead, 4);
	//SListPushBack(&pHead, 8);
	//SListPushBack(&pHead, 9);
	//SListPushBack(&pHead, 9);
	//pHead->next->next->next->next->next->next = pHead ->next->next->next->next;
	//SListPrint(pHead);
	//SListPrint(IsListWithCircle(pHead));//测是否带环

	//+++++++++++++++++++++++++++++++++
	//测两个链表相交可能带环时的情况
	//SListPushBack(&pHead, 1);
	//SListPushBack(&pHead, 2);
	//SListPushBack(&pHead, 3);
	//SListPushBack(&pHead, 4);
	//SListPushBack(&pHead, 8);
	//SListPushBack(&pHead, 9);
	////SListPushBack(&pHead2, 1);
	//SListPushBack(&pHead2, 5);
	//SListPushBack(&pHead2, 3);
	//SListPushBack(&pHead2, 4);
	//SListPushBack(&pHead2, 8);
	//SListPushBack(&pHead2, 1);
	////造环
	//pHead->next->next->next->next->next->next = pHead->next->next->next;// ->next;
	//pHead2->next->next->next = pHead->next;// ->next->next;// ->next;
	////SListPrint(pHead);
	////SListPrint(pHead2);
	////测
	//printf("%d\n", IsSListCrossWithCircle(pHead, pHead2));
}



//+++++++++++++++++++++++++++++++++++++
//打印函数
void SListPrint(PNode PHead)
{
	if (NULL == PHead)
	{
		printf("NULL\n");
		return;
	}
	while (NULL != PHead)//while (NULL != PHead->next)这种错误写法，总是忘记PHead它也是个节点啊！！！
	{
		printf("%d-->", PHead->data);
		PHead = PHead->next;
	}
	printf("NULL\n");
}
//+++++++++++++++++++++++++++++++++++++++
//创建节点
PNode getNode(int data)
{
	PNode newNode = NULL;
	newNode = (PNode)malloc(sizeof(Node));
	if (NULL == newNode)
	{
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


//++++++++++++++++++++++++++++++++
// 销毁链表 
void SListDestroy(PNode* pHead)
{
	PNode tmp = (*pHead);
	PNode nex = NULL;
	assert(pHead);
	while (NULL != tmp)
	{
		nex = tmp->next;
		free(tmp);
		tmp = nex;
	}

}


//+++++++++++++++++++++++++++++++++++=
// 链表的初始化 
void SListInit(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}




//+++++++++++++++++++++++++++++++++++++
// 尾插 
void SListPushBack(PNode* pHead, DataType data)
{
	assert(pHead);
	if (NULL == *pHead)//这就是为什么要传用*pHead
	{
		(*pHead) = getNode(data);
		/*(*pHead)->data = data;
		(*pHead)->next = NULL;*/
		return;
	}
	PNode tmp = *pHead;
	while (NULL != tmp->next)
	{
		tmp = tmp->next;
	}
	PNode newNode = getNode(data);
	tmp->next = newNode;
}
//+++++++++++++++++++++++++++++++++++++
// 逆序打印单链表 
void PrintSListFromTail2Head(PNode pHead)//递归
{
	if (NULL == pHead->next)
	{
		pHead->data;
		printf("%d ", pHead->data);
		return;
	}
	//printf("%d ", pHead->data);//这一句放开就是递归的过程
	PrintSListFromTail2Head(pHead->next);//每次走到这儿，开始递归，直到if条件满足。
	printf("%d ", pHead->data);

}

// 删除链表的非尾结点，要求：不能遍历链表 
void DeleteListNotTailNode(PNode pos)//插入替换法，先插入，后替换
{
	if (NULL == pos)
	{
		return ;
	}
	PNode newNode = getNode(pos->next->data);//产生新节点
	newNode->next = pos->next;//在新节点中放下一个节点
	pos->data = pos->next->data;//保存值
	pos->next = pos->next->next;//再存地址，和前一步顺序可不能反
	free(newNode->next);//销毁pos的下一个节点
	free(newNode);//销毁临时节点
}

// 在链表pos位置前插入值到data的结点 
void InesrtPosFront(PNode pos, DataType data)
{
	if (NULL == pos)
	{
		return;
	}
	PNode newNode = getNode(pos->data);//产生新节点
	newNode->next = pos->next;//在新节点中放下一个节点
	pos->next = newNode;
	pos->data = data;
}

// 查找链表的中间结点，要求只能遍历一次链表 
PNode FindMiddleNode(PNode pHead)//异步差半，你一我二。
{
	if (NULL == pHead)
	{
		return NULL;
	}
	PNode pfa = pHead;//快
	PNode psl = pHead;//慢
	PNode pre = pHead;//到时候用来存前一个中间节点
	while (pfa && pfa->next)//奇数节点和偶数节点情况有所不同，偶数有两个中间节点//循环条件，pfa偶数的时候，pfa->next技术的时候
	{
		pfa = pfa->next->next;//走两步
		pre = psl;
		psl = psl->next;//一步
	}
	//if (NULL == pfa)//若要求返回前几个中间节点
	//{
	//	return pre;
	//}
	return psl;
}

// 查找链表的倒数第K个结点，要求只能遍历一次链表 
PNode FindLastKNode(PNode pHead, int K)//与赵找中间节点类似，你先走K步，如果到最后了，我肯定在倒数k步//
{
	if (NULL == pHead || K <=0)
	{
		return NULL;
	}
	PNode pfa = pHead;//快
	PNode psl = pHead;//慢
	while (K--)
	{
		if (NULL == pfa)
		{
			return NULL;
		}
		pfa = pfa->next;
	}
	while (pfa)
	{
		pfa = pfa->next;
		psl = psl->next;
	}
	return psl;
}

// 删除链表的倒数第K个结点，要求只能遍历一次链表 
PNode DeleteLastKNode(PNode pHead, int K)
{
	if (NULL == pHead || K <=0)
	{
		return NULL;
	}
	PNode pfa = pHead;//快
	PNode psl = pHead;//慢
	PNode tmp = pHead;
	while (K--)
	{
		if (NULL == pfa)
		{
			return NULL;
		}
		pfa = pfa->next;
	}
	while (pfa)
	{
		pfa = pfa->next;
		tmp = psl;//保存psl的上一个节点
		psl = psl->next;
	}//头结点、尾节点
	if (tmp == psl)
	{
		tmp = tmp->next;
		pHead->data = tmp->data;
		pHead->next = tmp->next;
		free(tmp);
		return pHead;
	}
	tmp->next = psl->next;
	free(psl);
	return pHead;
}

// 用单链表实现约瑟夫环 
void JosephCircle(PNode* pHead, const int M)
{
	//造个环
	int i = 0;
	assert(pHead);
	PNode tmp = (*pHead);
	PNode find = (*pHead);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = (*pHead);

	while (find !=find->next)
	{
		i = M;
		while (i--)
		{
			find = find->next;
		}
		tmp = find->next;
		find->next = tmp->next;
		find->data = tmp->data;
		free(tmp);
	}
	(*pHead) = find;//还没完，断环啊
	(*pHead)->next = NULL;
}

// 链表的逆置--三个指针 
void ReverseSList(PNode* pHead)
{
	assert(pHead);//用三个指针，贼鸡儿烦
	PNode Pnow = (*pHead);//我就说，不是非得用三个指针，多一个看起来好看点而已。跟头插一个意思
	PNode Phe = Pnow;
	PNode Pnex = NULL;
	while (Pnow)
	{
		Phe = Pnow->next;
		Pnow->next = Pnex;
		Pnex = Pnow;
		Pnow = Phe;
	}
	(*pHead) = Pnex;

	/*PNode Pnow = (*pHead);
	PNode Phe = (*pHead);
	PNode Pnex = NULL;
	while ((*pHead))
	{
		Phe = (*pHead)->next;
		(*pHead)->next = Pnex;
		Pnex = (*pHead);
		(*pHead) = Phe;
	}
	(*pHead) = Pnex;*/

}

// 链表的逆置--头插法 
PNode ReverseSListOP(PNode pHead)//真tm的难想//区别前一种方法不能改变头指针，所以只能返回一个
{
	if (NULL == pHead)
	{
		return NULL;
	}
	PNode Pnext = NULL;
	PNode Pnew = pHead;
	pHead = pHead->next;
	Pnew->next = NULL;
	while (pHead )
	{
		Pnext = pHead->next;
		pHead->next = Pnew;
		Pnew = pHead;
		pHead = Pnext;
	}
	return Pnew;
}

// 用冒泡排序思想对单链表进行排序 
void BubbleSort(PNode pHead)//高仿冒泡
{
	int i = 0;
	if (NULL == pHead)
	{
		return;
	}
	PNode tmp = getNode(0);
	tmp = pHead;
	PNode Bub = pHead;
	while (Bub)
	{
		Bub = Bub->next;
		i++;
	}
	while (i--)
	{
		int j = i;
		Bub = pHead;
		while (j--)
		{
			if (Bub->data > Bub->next->data)
			{
				int t = Bub->data;//这儿这个int t
				// tmp->data = Bub->data;//让人发疯
				Bub->data = Bub->next->data;
				Bub->next->data = t;
			}
			Bub = Bub->next;
			Bub->next = Bub->next;
		}
	}
}

// 合并两个有序单链表，合并后依然有序 
PNode MergeSList(PNode pHead1, PNode pHead2)
{
	if (NULL == pHead1 || NULL == pHead2)//一个为空返回另一个，都为空返回NULL
	{
		if (NULL == pHead1)
		{
			return pHead2;
		}
		else if (NULL == pHead2)
		{
			return pHead1;
		}
		return NULL;
	}
	PNode tmp = NULL;
	if (pHead1->data > pHead2->data)//处理第一次节点的情况，因为在后面while中处理起来比较麻烦
	{
		tmp = pHead2;
		pHead2 = pHead2->next;
	}
	else
	{
		tmp = pHead1;
		pHead1 = pHead1->next;
	}
	PNode need = tmp;//保存head
	while (pHead1->next || pHead2->next)//一个为空就结束循环，尾巴接上另一个的剩下部分
	{
		if (pHead1->data > pHead2->data)//比较一下，把小的放进tmp
		{
			tmp->next= pHead2;//这里这个指针真是搞死人啊，自己还是没有真的搞懂指针//不要随便动里面的数据，一动所有都变了，牵一发而动全身啊
			pHead2 = pHead2->next;
		}
		else
		{
			tmp->next = pHead1;
			pHead1 = pHead1->next;
		}
		tmp = tmp->next;//tmp挪一下
	}
	if (NULL == pHead1->next)//上面说的接尾巴
	{
		//tmp->next->data = pHead2->data;
		tmp->next = pHead2;
		return need;
	}
	else
	{
		//tmp->next->data = pHead1->data;
		tmp->next= pHead1;
		return need;
	}
}

// 判断两个单链表是否相交---链表不带环 
int IsSListCross(PNode pHead1, PNode pHead2)
{
	//Y、L、V
	//先把框架整起
	//相交的成立条件：有相同节点
	//怎么整？齐步走
	//遍历之后找到短的，去掉长的头int i ;int j
	//开干！！！
	int i = 0;
	int j = 0;
	PNode Nphe1 = pHead1;
	PNode Nphe2 = pHead2;
	if (NULL == pHead1 || NULL == pHead2)
	{
		return 0;
	}
	while (Nphe1)
	{
		Nphe1 = Nphe1->next;
		i++;
	}
	while (Nphe2)
	{
		Nphe2 = Nphe2->next;
		j++;
	}
	i = i - j;
	if (0 < i)
	{
		while (i--)//注意边界条件
		{
			pHead1 = pHead1->next;
		}
	}
	else
	{
		while (i--)
		{
			pHead2 = pHead2->next;
		}
	}
	if (pHead1 == pHead2)//L型
	{
		return 1;
	}
	else
	{
		while (pHead1 != pHead2)//齐步走，Y和V都可以判断
		{
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		if (NULL == pHead2)//这一步差点忘了，万一没有节点就得gg，判断到尾巴没有，没到就是找到了
		{
			return 0;
		}
		return 1;
	}
}

// 求两个单链表相交的交点---链表不带环 
PNode GetCorssNode(PNode pHead1, PNode pHead2)//这不就是上一个改一下返回值吗？
{
	//Y、L、V
	//先把框架整起
	//相交的成立条件：有相同节点
	//怎么整？齐步走
	//遍历之后找到短的，去掉长的头int i ;int j
	//开干！！！
	int i = 0;
	int j = 0;
	PNode Nphe1 = pHead1;
	PNode Nphe2 = pHead2;
	if (NULL == pHead1 || NULL == pHead2)
	{
		return NULL;
	}
	while (Nphe1)
	{
		Nphe1 = Nphe1->next;
		i++;
	}
	while (Nphe2)
	{
		Nphe2 = Nphe2->next;
		j++;
	}
	i = i - j;
	if (0 < i)
	{
		while (i--)//注意边界条件
		{
			pHead1 = pHead1->next;
		}
	}
	else
	{
		while (i++)
		{
			pHead2 = pHead2->next;
		}
	}
	if (pHead1 == pHead2)//L型
	{
		return pHead2;
	}
	else
	{
		while (pHead1 != pHead2)//齐步走，Y和V都可以判断
		{
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		if (NULL == pHead2)//这一步差点忘了，万一没有节点就得gg，判断到尾巴没有，没到就是找到了
		{
			return NULL;
		}
		return pHead1;
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//附加
//

// 判断两个不带环单链表是否相交
//int IsSListCross(PNode pHead1, PNode pHead2);//上面写了

// 获取两个不带环单链表相交的交点
PNode GetCorssNode(PNode pHead1, PNode pHead2);//过

// 判断链表是否带环，返回相遇点---注意推导公式
PNode IsListWithCircle(PNode pHead)//2*(L+X) = L + X +nR  --> L = X+nR;//6型的，L是到交点的位置。X是交点到两指针相遇点的位置
{//如果带环，让两个指针异步走（一个两步，一个一步，考虑到环最小为2节点，所以异步最多走二，比如三步时，环为2，那就永远不会相交（周期性））
	//带环返回节点，不带环返回NULL
	//用到三个指针，快慢两个，一个标记相遇点？//不用再声明了，已经有两个fast和slow，反正后面不同，直接用好了
	if (NULL == pHead)
	{
		return NULL;
	}
	PNode Pfast = pHead->next->next;
	PNode Pslow = pHead->next;
	//PNode Pmeet = NULL;
	//while (Pfast != Pslow && NULL != Pfast)//两个注意的地方1.这里为何要用&&，要记住，只为了不满足其中一个条件就退出循环，那么反之，就是两个都满足才进入循环
	//2.判断Pfast只考虑了偶数个节点的情况
	while (Pfast != Pslow && NULL != Pfast && NULL != Pfast->next)
	{
		Pfast = Pfast->next->next;
		Pslow = Pslow->next;
	}
	//printf("%d\n", GetCircleLen(Pfast));//测获取环长
	if (NULL == Pfast|| NULL == Pfast->next)
	{
		return NULL;
	}
	Pslow = pHead;
	//return GetCircleEnter(pHead, Pfast);//测试获取环的入口节点
	while (Pfast != Pslow)
	{
		Pfast = Pfast->next;
		Pslow = Pslow->next;
	}
	return Pfast;
}

// 获取环的入口点
PNode GetCircleEnter(PNode pHead1, PNode pMeetNode)
{
	if (NULL == pHead1 || NULL == pMeetNode)
	{
		return NULL;
	}
	if (pHead1 == pMeetNode)
	{
		return pMeetNode;
	}
	while (pHead1 != pMeetNode)
	{
		pHead1 = pHead1->next;
		pMeetNode = pMeetNode->next;
	}
	return pMeetNode;
}

// 获取环的长度
int GetCircleLen(PNode pMeetNode)
{//用一个节点标记此处，让另一个动起来，再次相遇即是一周
	int  i = 1;
	PNode Pmove = pMeetNode->next;
	while (Pmove != pMeetNode)
	{
		Pmove = Pmove->next;
		i++;
	}
	return i;
}

// 判断两个链表是否相交，链表可能带环
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2)
{
	//1.都不带环2.都带环3.一个带一个不带（不可能！）
	PNode Nphe1 = pHead1;
	PNode Nphe2 = pHead2;
	PNode Pmeet1 = IsListWithCircle(pHead1);
	PNode Pmeet2 = IsListWithCircle(pHead2);
	/*if (NULL == IsListWithCircle(pHead1) && NULL == IsListWithCircle(pHead2))
	{
		return IsSListCross(pHead1, pHead2);
	}
	if (NULL != IsListWithCircle(pHead1) && NULL != IsListWithCircle(pHead2))*///这种做法是不好的，多次调用函数，每次形成栈桢！！！
	if (NULL == Pmeet1 && NULL == Pmeet2)
	{
		return IsSListCross(pHead1, pHead2);
	}
	if (NULL != Pmeet1 && NULL != Pmeet2)
	{
		//环外相交，环内相交
		//环外相交齐步走
		int i = 0;
		int j = 0;
		 Nphe1 = pHead1;
		 Nphe2 = pHead2;
		while (Nphe1 !=Pmeet1)
		{
			Nphe1 = Nphe1->next;
			i++;
		}
		while (Nphe2 !=Pmeet1)
		{
			Nphe2 = Nphe2->next;
			j++;
		}
		Nphe1 = pHead1;
		Nphe2 = pHead2;
		i = i - j;
		if (0 < i)
		{
			while (i--)//注意边界条件
			{
				Nphe1 = Nphe1->next;
			}
		}
		else
		{
			while (i++)
			{
				Nphe2 = Nphe2->next;
			}
		}

		if (Nphe1 == Nphe2)
		{
			return 1;
		}
		else
		{
			while (Nphe1 != Nphe2)
			{
				Nphe1 = Nphe1->next;
				Nphe2 = Nphe2->next;
			}
			return 1;
		}
	}
	return 0;
}

// 复杂链表复制
//创建复杂链表
typedef struct str
{
	int data;
	struct str* rand;
	struct str* next;
}CSLNode, *PCSLNode;
PCSLNode pcslHead;

void PCSLSListPrint(PCSLNode PHead)
{
	if (NULL == PHead)
	{
		printf("NULL\n");
		return;
	}
	while (NULL != PHead)//while (NULL != PHead->next)这种错误写法，总是忘记PHead它也是个节点啊！！！
	{
		printf("%d-->", PHead->data);
		PHead = PHead->next;
	}
	printf("NULL\n");
}
PCSLNode PCSLgetNode(int data)
{
	PCSLNode newNode = NULL;
	newNode = (PCSLNode)malloc(sizeof(CSLNode));
	if (NULL == newNode)
	{
		return NULL;
	}
	newNode->data = data;
	newNode->rand = NULL;
	newNode->next = NULL;
	return newNode;
}
void PCSListPushBack(PCSLNode* pHead, DataType data)
{
	assert(pHead);
	if (NULL == *pHead)//这就是为什么要传用*pHead
	{
		(*pHead) = PCSLgetNode(data);
		/*(*pHead)->data = data;
		(*pHead)->next = NULL;*/
		return;
	}
	PCSLNode tmp = *pHead;
	while (NULL != tmp->next)
	{
		tmp = tmp->next;
	}
	PCSLNode newNode = PCSLgetNode(data);
	tmp->next = newNode;
}
PCSLNode CopyComplexList(PCSLNode pcslHead);//开干。。。

void testPCSLNode()
{
	PCSListPushBack(&pcslHead, 1);
	PCSListPushBack(&pcslHead, 2);
	PCSListPushBack(&pcslHead, 3);
	PCSListPushBack(&pcslHead, 4);
	PCSListPushBack(&pcslHead, 5);
	pcslHead->rand = pcslHead->next->next;
	pcslHead->next->rand = pcslHead;
	pcslHead->next->next->rand = pcslHead->next->next;
	pcslHead->next->next->rand = NULL;
	PCSLSListPrint(pcslHead);

	//++++++++++++++++++++++++++++
	PCSLSListPrint(CopyComplexList(pcslHead));
}

//建立一个复杂链表这么麻烦。。。
PCSLNode CopyComplexList(PCSLNode pHead)//开干。。。
{
	PCSLNode back = pHead;
	PCSLNode tmp = pHead->next;
	while (tmp)//复制
	{

		back->next = PCSLgetNode(back->data);
		back->next->next = tmp;
		back->next->rand = back->rand;
		back = tmp;
		tmp = tmp->next;
	}
	back->next = PCSLgetNode(back->data);
	back->next->rand = back->rand;
	//拆下来，还原pHead
	PCSLNode now = pHead->next;
	tmp = pHead;
	back = now;
	while (back->next)
	{
		tmp ->next= tmp->next->next;
		back->next = back->next->next;
		tmp = tmp->next;
		back = back->next;
	}
	tmp->next = NULL;
	return pHead;
}