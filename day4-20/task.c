#pragma warning(disable:4996)
# include "task.h"

void test()
{
	SListInit(&pHead);
	//��β�塢��ӡ
	/*SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 9);
	SListPrint(pHead);*/


	//++++++++++++++++++++
	//�����ӡ
	//PrintSListFromTail2Head(pHead);
	//ɾ����β�ͽڵ�

	//+++++++++++=+++++
	//PNode pos = pHead;// ->next->next;
	//DeleteListNotTailNode(pos);
	//SListPrint(pHead);

	//++++++++++++++++++++
	//z��pos����data�Ľڵ�
	//PNode pos = pHead->next->next;//3
	//pos = pHead;
	//InesrtPosFront(pos, 7);
	//SListPrint(pHead);

	//++++++++++++++++++++++++
	//���м�ڵ�
	//printf("%d\n", FindMiddleNode(pHead)->data);

	//++++++++++++++++++++++++++
	//�ҵ���K�ڵ�
	//printf("%d\n", FindLastKNode(pHead,1)->data);

	//+++++++++++++++++++++++++++++++
	//ɾ��������K���ڵ�
	//DeleteLastKNode(pHead, 3);
	////printf("%d\n", DeleteLastKNode(pHead,7)->data);
	//SListPrint(pHead);
	
	//+++++++++++++++++++
	//Լɪ��
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
	//ð��
	//SListPushBack(&pHead, 9);
	//SListPushBack(&pHead, 5);
	////SListPushBack(&pHead, 2);
	////SListPushBack(&pHead, 8);
	//SListPrint(pHead);
	//BubbleSort(pHead);
	//SListPrint(pHead);

	//++++++++++++++++++++++
	//�ϲ�������������
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
	//�����޻��ҽڵ�
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
	//�жϴ����񣬷��ؽ���
	//SListPushBack(&pHead, 1);
	//SListPushBack(&pHead, 2);
	//SListPushBack(&pHead, 3);
	//SListPushBack(&pHead, 4);
	//SListPushBack(&pHead, 8);
	//SListPushBack(&pHead, 9);
	//SListPushBack(&pHead, 9);
	//pHead->next->next->next->next->next->next = pHead ->next->next->next->next;
	//SListPrint(pHead);
	//SListPrint(IsListWithCircle(pHead));//���Ƿ����

	//+++++++++++++++++++++++++++++++++
	//�����������ཻ���ܴ���ʱ�����
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
	////�컷
	//pHead->next->next->next->next->next->next = pHead->next->next->next;// ->next;
	//pHead2->next->next->next = pHead->next;// ->next->next;// ->next;
	////SListPrint(pHead);
	////SListPrint(pHead2);
	////��
	//printf("%d\n", IsSListCrossWithCircle(pHead, pHead2));
}



//+++++++++++++++++++++++++++++++++++++
//��ӡ����
void SListPrint(PNode PHead)
{
	if (NULL == PHead)
	{
		printf("NULL\n");
		return;
	}
	while (NULL != PHead)//while (NULL != PHead->next)���ִ���д������������PHead��Ҳ�Ǹ��ڵ㰡������
	{
		printf("%d-->", PHead->data);
		PHead = PHead->next;
	}
	printf("NULL\n");
}
//+++++++++++++++++++++++++++++++++++++++
//�����ڵ�
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
// �������� 
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
// ����ĳ�ʼ�� 
void SListInit(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}




//+++++++++++++++++++++++++++++++++++++
// β�� 
void SListPushBack(PNode* pHead, DataType data)
{
	assert(pHead);
	if (NULL == *pHead)//�����ΪʲôҪ����*pHead
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
// �����ӡ������ 
void PrintSListFromTail2Head(PNode pHead)//�ݹ�
{
	if (NULL == pHead->next)
	{
		pHead->data;
		printf("%d ", pHead->data);
		return;
	}
	//printf("%d ", pHead->data);//��һ��ſ����ǵݹ�Ĺ���
	PrintSListFromTail2Head(pHead->next);//ÿ���ߵ��������ʼ�ݹ飬ֱ��if�������㡣
	printf("%d ", pHead->data);

}

// ɾ������ķ�β��㣬Ҫ�󣺲��ܱ������� 
void DeleteListNotTailNode(PNode pos)//�����滻�����Ȳ��룬���滻
{
	if (NULL == pos)
	{
		return ;
	}
	PNode newNode = getNode(pos->next->data);//�����½ڵ�
	newNode->next = pos->next;//���½ڵ��з���һ���ڵ�
	pos->data = pos->next->data;//����ֵ
	pos->next = pos->next->next;//�ٴ��ַ����ǰһ��˳��ɲ��ܷ�
	free(newNode->next);//����pos����һ���ڵ�
	free(newNode);//������ʱ�ڵ�
}

// ������posλ��ǰ����ֵ��data�Ľ�� 
void InesrtPosFront(PNode pos, DataType data)
{
	if (NULL == pos)
	{
		return;
	}
	PNode newNode = getNode(pos->data);//�����½ڵ�
	newNode->next = pos->next;//���½ڵ��з���һ���ڵ�
	pos->next = newNode;
	pos->data = data;
}

// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindMiddleNode(PNode pHead)//�첽��룬��һ�Ҷ���
{
	if (NULL == pHead)
	{
		return NULL;
	}
	PNode pfa = pHead;//��
	PNode psl = pHead;//��
	PNode pre = pHead;//��ʱ��������ǰһ���м�ڵ�
	while (pfa && pfa->next)//�����ڵ��ż���ڵ����������ͬ��ż���������м�ڵ�//ѭ��������pfaż����ʱ��pfa->next������ʱ��
	{
		pfa = pfa->next->next;//������
		pre = psl;
		psl = psl->next;//һ��
	}
	//if (NULL == pfa)//��Ҫ�󷵻�ǰ�����м�ڵ�
	//{
	//	return pre;
	//}
	return psl;
}

// ��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
PNode FindLastKNode(PNode pHead, int K)//�������м�ڵ����ƣ�������K�������������ˣ��ҿ϶��ڵ���k��//
{
	if (NULL == pHead || K <=0)
	{
		return NULL;
	}
	PNode pfa = pHead;//��
	PNode psl = pHead;//��
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

// ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
PNode DeleteLastKNode(PNode pHead, int K)
{
	if (NULL == pHead || K <=0)
	{
		return NULL;
	}
	PNode pfa = pHead;//��
	PNode psl = pHead;//��
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
		tmp = psl;//����psl����һ���ڵ�
		psl = psl->next;
	}//ͷ��㡢β�ڵ�
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

// �õ�����ʵ��Լɪ�� 
void JosephCircle(PNode* pHead, const int M)
{
	//�����
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
	(*pHead) = find;//��û�꣬�ϻ���
	(*pHead)->next = NULL;
}

// ���������--����ָ�� 
void ReverseSList(PNode* pHead)
{
	assert(pHead);//������ָ�룬��������
	PNode Pnow = (*pHead);//�Ҿ�˵�����Ƿǵ�������ָ�룬��һ���������ÿ�����ѡ���ͷ��һ����˼
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

// ���������--ͷ�巨 
PNode ReverseSListOP(PNode pHead)//��tm������//����ǰһ�ַ������ܸı�ͷָ�룬����ֻ�ܷ���һ��
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

// ��ð������˼��Ե������������ 
void BubbleSort(PNode pHead)//�߷�ð��
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
				int t = Bub->data;//������int t
				// tmp->data = Bub->data;//���˷���
				Bub->data = Bub->next->data;
				Bub->next->data = t;
			}
			Bub = Bub->next;
			Bub->next = Bub->next;
		}
	}
}

// �ϲ��������������ϲ�����Ȼ���� 
PNode MergeSList(PNode pHead1, PNode pHead2)
{
	if (NULL == pHead1 || NULL == pHead2)//һ��Ϊ�շ�����һ������Ϊ�շ���NULL
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
	if (pHead1->data > pHead2->data)//�����һ�νڵ���������Ϊ�ں���while�д��������Ƚ��鷳
	{
		tmp = pHead2;
		pHead2 = pHead2->next;
	}
	else
	{
		tmp = pHead1;
		pHead1 = pHead1->next;
	}
	PNode need = tmp;//����head
	while (pHead1->next || pHead2->next)//һ��Ϊ�վͽ���ѭ����β�ͽ�����һ����ʣ�²���
	{
		if (pHead1->data > pHead2->data)//�Ƚ�һ�£���С�ķŽ�tmp
		{
			tmp->next= pHead2;//�������ָ�����Ǹ����˰����Լ�����û����ĸ㶮ָ��//��Ҫ��㶯��������ݣ�һ�����ж����ˣ�ǣһ������ȫ��
			pHead2 = pHead2->next;
		}
		else
		{
			tmp->next = pHead1;
			pHead1 = pHead1->next;
		}
		tmp = tmp->next;//tmpŲһ��
	}
	if (NULL == pHead1->next)//����˵�Ľ�β��
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

// �ж������������Ƿ��ཻ---�������� 
int IsSListCross(PNode pHead1, PNode pHead2)
{
	//Y��L��V
	//�Ȱѿ������
	//�ཻ�ĳ�������������ͬ�ڵ�
	//��ô�����벽��
	//����֮���ҵ��̵ģ�ȥ������ͷint i ;int j
	//���ɣ�����
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
		while (i--)//ע��߽�����
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
	if (pHead1 == pHead2)//L��
	{
		return 1;
	}
	else
	{
		while (pHead1 != pHead2)//�벽�ߣ�Y��V�������ж�
		{
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		if (NULL == pHead2)//��һ��������ˣ���һû�нڵ�͵�gg���жϵ�β��û�У�û�������ҵ���
		{
			return 0;
		}
		return 1;
	}
}

// �������������ཻ�Ľ���---�������� 
PNode GetCorssNode(PNode pHead1, PNode pHead2)//�ⲻ������һ����һ�·���ֵ��
{
	//Y��L��V
	//�Ȱѿ������
	//�ཻ�ĳ�������������ͬ�ڵ�
	//��ô�����벽��
	//����֮���ҵ��̵ģ�ȥ������ͷint i ;int j
	//���ɣ�����
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
		while (i--)//ע��߽�����
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
	if (pHead1 == pHead2)//L��
	{
		return pHead2;
	}
	else
	{
		while (pHead1 != pHead2)//�벽�ߣ�Y��V�������ж�
		{
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		if (NULL == pHead2)//��һ��������ˣ���һû�нڵ�͵�gg���жϵ�β��û�У�û�������ҵ���
		{
			return NULL;
		}
		return pHead1;
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//����
//

// �ж������������������Ƿ��ཻ
//int IsSListCross(PNode pHead1, PNode pHead2);//����д��

// ��ȡ�����������������ཻ�Ľ���
PNode GetCorssNode(PNode pHead1, PNode pHead2);//��

// �ж������Ƿ����������������---ע���Ƶ���ʽ
PNode IsListWithCircle(PNode pHead)//2*(L+X) = L + X +nR  --> L = X+nR;//6�͵ģ�L�ǵ������λ�á�X�ǽ��㵽��ָ���������λ��
{//���������������ָ���첽�ߣ�һ��������һ��һ�������ǵ�����СΪ2�ڵ㣬�����첽����߶�����������ʱ����Ϊ2���Ǿ���Զ�����ཻ�������ԣ���
	//�������ؽڵ㣬����������NULL
	//�õ�����ָ�룬����������һ����������㣿//�����������ˣ��Ѿ�������fast��slow���������治ͬ��ֱ���ú���
	if (NULL == pHead)
	{
		return NULL;
	}
	PNode Pfast = pHead->next->next;
	PNode Pslow = pHead->next;
	//PNode Pmeet = NULL;
	//while (Pfast != Pslow && NULL != Pfast)//����ע��ĵط�1.����Ϊ��Ҫ��&&��Ҫ��ס��ֻΪ�˲���������һ���������˳�ѭ������ô��֮����������������Ž���ѭ��
	//2.�ж�Pfastֻ������ż�����ڵ�����
	while (Pfast != Pslow && NULL != Pfast && NULL != Pfast->next)
	{
		Pfast = Pfast->next->next;
		Pslow = Pslow->next;
	}
	//printf("%d\n", GetCircleLen(Pfast));//���ȡ����
	if (NULL == Pfast|| NULL == Pfast->next)
	{
		return NULL;
	}
	Pslow = pHead;
	//return GetCircleEnter(pHead, Pfast);//���Ի�ȡ������ڽڵ�
	while (Pfast != Pslow)
	{
		Pfast = Pfast->next;
		Pslow = Pslow->next;
	}
	return Pfast;
}

// ��ȡ������ڵ�
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

// ��ȡ���ĳ���
int GetCircleLen(PNode pMeetNode)
{//��һ���ڵ��Ǵ˴�������һ�����������ٴ���������һ��
	int  i = 1;
	PNode Pmove = pMeetNode->next;
	while (Pmove != pMeetNode)
	{
		Pmove = Pmove->next;
		i++;
	}
	return i;
}

// �ж����������Ƿ��ཻ��������ܴ���
int IsSListCrossWithCircle(PNode pHead1, PNode pHead2)
{
	//1.��������2.������3.һ����һ�������������ܣ���
	PNode Nphe1 = pHead1;
	PNode Nphe2 = pHead2;
	PNode Pmeet1 = IsListWithCircle(pHead1);
	PNode Pmeet2 = IsListWithCircle(pHead2);
	/*if (NULL == IsListWithCircle(pHead1) && NULL == IsListWithCircle(pHead2))
	{
		return IsSListCross(pHead1, pHead2);
	}
	if (NULL != IsListWithCircle(pHead1) && NULL != IsListWithCircle(pHead2))*///���������ǲ��õģ���ε��ú�����ÿ���γ�ջ�壡����
	if (NULL == Pmeet1 && NULL == Pmeet2)
	{
		return IsSListCross(pHead1, pHead2);
	}
	if (NULL != Pmeet1 && NULL != Pmeet2)
	{
		//�����ཻ�������ཻ
		//�����ཻ�벽��
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
			while (i--)//ע��߽�����
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

// ����������
//������������
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
	while (NULL != PHead)//while (NULL != PHead->next)���ִ���д������������PHead��Ҳ�Ǹ��ڵ㰡������
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
	if (NULL == *pHead)//�����ΪʲôҪ����*pHead
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
PCSLNode CopyComplexList(PCSLNode pcslHead);//���ɡ�����

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

//����һ������������ô�鷳������
PCSLNode CopyComplexList(PCSLNode pHead)//���ɡ�����
{
	PCSLNode back = pHead;
	PCSLNode tmp = pHead->next;
	while (tmp)//����
	{

		back->next = PCSLgetNode(back->data);
		back->next->next = tmp;
		back->next->rand = back->rand;
		back = tmp;
		tmp = tmp->next;
	}
	back->next = PCSLgetNode(back->data);
	back->next->rand = back->rand;
	//����������ԭpHead
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