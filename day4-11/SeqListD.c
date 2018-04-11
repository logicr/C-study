#pragma warning(disable:4996)
# include "SeqListD.h"

//���Գ�ʼ������
void testInit()
{
	SeqListDInit(&s, 20);
}

//����β�����ݺ���
void tsetPushBack()
{
	SeqListDInit(&s, 4);
	SeqListDPushBack(&s, 1);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDprint(&s);
	SeqListDPushBack(&s, 5);
	SeqListDprint(&s);
	SeqListDPopBack(&s);
	SeqListDprint(&s);
	
}


//��������λ�ò���ɾ��
void testInsert()
{
	SeqListDInit(&s, 4);
	SeqListDPushBack(&s, 1);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDprint(&s);
	SeqListDInsert(&s, 3, 5);
	SeqListDprint(&s);
	SeqListDErase(&s, 2);
	SeqListDprint(&s);
}
//������������������ա�empty
void testAll()
{
	SeqListDInit(&s, 4);
	SeqListDPushBack(&s, 1);
	SeqListDPushBack(&s, 2);
	SeqListDPushBack(&s, 3);
	SeqListDPushBack(&s, 4);
	SeqListDInsert(&s, 3, 5);
	SeqListDprint(&s);
	printf("%d\n", SeqListDSize(&s));
	SeqListDprint(&s);
	printf("%d\n", SeqListDCapacity(&s));
	SeqListDprint(&s);
	printf("%d\n", SeqListDEmpty(&s));
	SeqListDprint(&s);
	SeqListDDestroy(&s);
	SeqListDprint(&s);
}
//��ӡ����
void SeqListDprint(PSeqListD ps)
{
	int i = 0;
	if (NULL == ps)
	{
		return ;
	}
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");

}
//���ݺ��� 
int * expand(PSeqListD ps)
{
	int * pp = NULL;
	if (NULL == ps)
	{
		return NULL;
	}
	pp = (int *)realloc(ps->arr, ps->capacity * 2 * sizeof(int));
	ps->capacity = ps->capacity * 2;
	return pp;
}

//ʵ�ֶ�̬˳�������½ӿڣ�
void SeqListDInit(PSeqListD ps, int capacity)//��ʼ��
{
	if (NULL == ps)
	{
		printf("��ָ��!\n");
		return;
	}
	ps->arr = (int *)malloc(capacity*sizeof(int));
	if (NULL != ps->arr)
	{
		ps->size = 0;
		ps->capacity = capacity;
	}

}
void SeqListDPushBack(PSeqListD ps, DataType data)//β��
{
	if (NULL == ps)
	{
		printf("��ָ��!\n");
		return;
	}
	if (ps->size == ps->capacity )
	{
		if (NULL == (ps->arr = expand(ps)))
		{
			return;
		}
	}
	ps->arr[ps->size] = data;
	ps->size++;

}
void SeqListDPopBack(PSeqListD ps)//βɾ
{
	if (NULL == ps && (0 !=ps->size))
	{
		printf("�������!\n");
		return;
	}
	ps->size--;
}
void SeqListDInsert(PSeqListD ps, int pos, DataType data)//�������
{
	int i = 0;
	if (NULL == ps || (pos < 0 || pos >ps->size))
	{
		printf("�������!\n");
		return;
	}
	if (ps->size == ps->capacity)
	{
		if (NULL == (ps->arr = expand(ps)))
		{
			return;
		}
	}
	for (i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = data;
	ps->size++;
}
void SeqListDErase(PSeqListD ps, int pos)//����ɾ��
{
	int i = 0;
	if (NULL == ps || (pos < 0 || pos >ps->size))
	{
		printf("�������!\n");
		return;
	}
	for (i = pos; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

// ��ȡԪ�ظ��� 
int SeqListDSize(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("��ָ��!\n");
		return;
	}
	return ps->size;
}

// ��ȡ˳�������� 
int SeqListDCapacity(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("��ָ��!\n");
		return;
	}
	return ps->capacity;
}

int SeqListDEmpty(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("��ָ��!\n");
		return;
	}
	ps->arr =NULL;
	ps->capacity = 0;
	ps->size = 0;
	return ps->capacity;
}

// ��˳����е�Ԫ����� ע�⣺���ı�˳���ռ�Ĵ�С 
void SeqListDClear(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("��ָ��!\n");
		return;
	}
	ps->size = 0;
}
//����
void SeqListDDestroy(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("��ָ��!\n");
		return;
	}
	free(ps->arr);
	SeqListDEmpty(ps);

}

// ��˳���������� 
int CheckCapacity(PSeqListD ps);
