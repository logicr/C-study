#pragma warning(disable:4996)
# include "order.h"
void test()
{
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 6);
	SeqListPopBack(&s);//βɾ
	SeqListPushFront(&s, 100);//ͷ��
	SeqListPopFront(&s);//ͷɾ
	SeqListInsert(&s, 5, 20);//�������
	SeqListErase(&s, 5);//����ɾ
	//Remove(&s, 5);//ɾ����һ�����ֵ�
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 5);
	RemoveAll(&s, 5);//ɾ�����ֵ�5
	int a = SeqListFind(&s,1);
	SeqListPushBack(&s, 11);
	SeqListPushBack(&s, 13);
	SeqListPushBack(&s, 12);
	PrintSeqList(&s);//��ӡ����
	SelectSort(&s);//ѡ������
	//BubbleSort(&s);//ð������
	PrintSeqList(&s);

}
//˳����ʼ��
void SeqListInit(PSeqList ps)
{
	if (NULL == ps)
	{
		printf("��ָ��\n");
		return ;
	}
	ps->_size = 0;
}
// ˳����β�� 
void SeqListPushBack(PSeqList ps, DataType data)
{
	if (NULL == ps)
	{
		printf("��ָ��\n");
		assert(0);
	}
	if (MAX_SIZE == ps->_size)
	{
		printf("�ռ��������޷�д��\n");
		return;
	}
	ps->_array[ps->_size] = data;
	ps->_size++;
}

// ˳����βɾ 
void SeqListPopBack(PSeqList ps)
{
	if (NULL == ps)
	{
		printf("��ָ��\n");
		assert(0);
	}
	ps->_size--;
}

// ˳����ͷ�� 
void SeqListPushFront(PSeqList ps, DataType data)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("��ָ��\n");
		assert(0);
	}
	if (MAX_SIZE == ps->_size)
	{
		printf("�ռ��������޷�д��\n");
		return;
	}
	for (i = ps->_size; i > 0; --i)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}

// ˳����ͷɾ 
void SeqListPopFront(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("��ָ��\n");
		assert(0);
	}
	if (MAX_SIZE == ps->_size)
	{
		printf("�ռ��������޷�д��\n");
		return;
	}
	for (i = 0; i < ps->_size - 1; ++i)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

// ˳���posλ�ò���Ԫ��data 
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	int i = 0;
	if (NULL == ps || pos < 0 || pos > ps->_size)
	{
		printf("ָ������λ������\n");
		assert(0);
	}
	if (MAX_SIZE == ps->_size)
	{
		printf("�ռ��������޷�д��\n");
		return;
	}
	for (i =ps->_size ; i >pos ; i --)
	{
		ps->_array[i] = ps->_array[i-1];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

// ɾ��˳���posλ��Ԫ�� 
void SeqListErase(PSeqList ps, int pos)
{
	int i = 0;
	if (NULL == ps ||pos < 0 || pos > ps->_size)
	{
		printf("ָ������λ������\n");
		return ;
	}
	for (i = pos; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void Remove(PSeqList ps, DataType data)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("��ָ��\n");
		return ;
	}
	for (i = 0; i < ps->_size; i++)
	{
		if (data == ps->_array[i])
		{
			int j = 0;
			for (j = i; j < ps->_size ; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			ps->_size--;
			return;
		}
	}

}

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void RemoveAll(PSeqList ps, DataType data)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("��ָ��\n");
		return;
	}
	//++++++++++++++++++++++++++++++++++
	//1.0
	/*
	for (i = 0; i < ps->_size; i++)
	{
		if (data == ps->_array[i])
		{
			int j = 0;
			for (j = i; j < ps->_size; j++)
			{
				ps->_array[j] = ps->_array[j + 1];
			}
			ps->_size--;
			i--;//���������±���һ�Σ�i����һ�Σ��Ͳ���������ǰԪ����
		}
	}
	//++++++++++++++++++++++++++++++++++++
	*/
	//++++++++++++++++++++++++++++++++++++
	//2.0
	/*
	int temp[MAX_SIZE] = { 0 };
	int count = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (data == ps->_array[i])
		{
			count++;
		}
		else
		{
			temp[i - count] = ps->_array[i];
		}
	}
	memcpy(ps->_array,temp,sizeof(ps->_array));
	ps->_size -= count;
	//++++++++++++++++++++++++++++++++++++++++
	*/
	//++++++++++++++++++++++++++++++++++++++++
	//3.0
	int count = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (data == ps->_array[i])
		{
			count++;
		}
		else
		{
			ps->_array[i - count] = ps->_array[i];
		}
	}
	ps->_size -= count;
}

// ��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ����˳����е�λ�ã����򷵻�-1 
int SeqListFind(PSeqList ps, DataType data)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("��ָ��\n");
		return -1;
	}
	for (i = 0; i < ps->_size; i++)
	{
		if (data == ps->_array[i])
		{
			return i;
		}
	}
	return -1;
}

// ��ȡ˳�����Ԫ�صĸ��� 
int SeqListSize(PSeqList ps)
{
	if (NULL == ps)
	{
		printf("��ָ��\n");
		return -1;
	}
	return ps->_size;
}



////////////////////////////////////////////////// 
//�������� 
// ��ӡ˳��� 
void PrintSeqList(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("��ָ��\n");
		return;
	}
	printf("��ǰԪ�ظ���Ϊ��%d\n", ps->_size);
	for (i = 0; i < ps->_size; i++)
	{
		printf("%d  ", ps->_array[i]);
	}
	printf("\n");
}

void swap(int *po, int *pt)
{
	/*
	int tmp = po;//���֮���Բ��У���Ϊ������������ָ���ַ����������ݲ�û�н���
	po = pt;
	pt = tmp;
	*/
	int tmp = *po;
	*po = *pt;
	*pt = tmp;
}
// ʹ��ð�������˳����е�Ԫ�ؽ������� 
void BubbleSort(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("��ָ��\n");
		return;
	}
	for (i = 0; i < ps->_size; i++)
	{
		int flog = 0;
		int j = 0;
		for (j = 0; j < ps->_size - i - 1; j++)
		{
			
			if (ps->_array[j] > ps->_array[j + 1])
			{
				flog = 1;
				swap(&ps->_array[j], &ps->_array[j + 1]);
			}
		}
		if (0 == flog)
		{
			return;
		}
	}
}

// ʹ��ѡ�������˳����е�Ԫ�ؽ������� 
void SelectSort(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("��ָ��\n");
		return;
	}
	for (i = 0; i < ps->_size; i ++)
	{
		int flog = 0;
		int j = 0;
		for (j = 0; j < ps->_size -i -1; j++)
		{

			if (ps->_array[j] > ps->_array[j + 1])
			{
				flog = j;
			}
			else
			{
				flog = j + 1;
			}
		}
		swap(&ps->_array[ps->_size - i - 1], &ps->_array[flog]);
	}
}
