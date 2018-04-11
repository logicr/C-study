#pragma warning(disable:4996)
# include "SeqListD.h"

//测试初始化函数
void testInit()
{
	SeqListDInit(&s, 20);
}

//测试尾插扩容函数
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


//测试任意位置插入删除
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
//测试容量、个数、清空、empty
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
//打印函数
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
//增容函数 
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

//实现动态顺序表的以下接口：
void SeqListDInit(PSeqListD ps, int capacity)//初始化
{
	if (NULL == ps)
	{
		printf("空指针!\n");
		return;
	}
	ps->arr = (int *)malloc(capacity*sizeof(int));
	if (NULL != ps->arr)
	{
		ps->size = 0;
		ps->capacity = capacity;
	}

}
void SeqListDPushBack(PSeqListD ps, DataType data)//尾插
{
	if (NULL == ps)
	{
		printf("空指针!\n");
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
void SeqListDPopBack(PSeqListD ps)//尾删
{
	if (NULL == ps && (0 !=ps->size))
	{
		printf("请检查参数!\n");
		return;
	}
	ps->size--;
}
void SeqListDInsert(PSeqListD ps, int pos, DataType data)//任意插入
{
	int i = 0;
	if (NULL == ps || (pos < 0 || pos >ps->size))
	{
		printf("请检查参数!\n");
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
void SeqListDErase(PSeqListD ps, int pos)//任意删除
{
	int i = 0;
	if (NULL == ps || (pos < 0 || pos >ps->size))
	{
		printf("请检查参数!\n");
		return;
	}
	for (i = pos; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

// 获取元素个数 
int SeqListDSize(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("空指针!\n");
		return;
	}
	return ps->size;
}

// 获取顺序表的容量 
int SeqListDCapacity(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("空指针!\n");
		return;
	}
	return ps->capacity;
}

int SeqListDEmpty(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("空指针!\n");
		return;
	}
	ps->arr =NULL;
	ps->capacity = 0;
	ps->size = 0;
	return ps->capacity;
}

// 将顺序表中的元素清空 注意：不改变顺序表空间的大小 
void SeqListDClear(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("空指针!\n");
		return;
	}
	ps->size = 0;
}
//销毁
void SeqListDDestroy(PSeqListD ps)
{
	if (NULL == ps)
	{
		printf("空指针!\n");
		return;
	}
	free(ps->arr);
	SeqListDEmpty(ps);

}

// 对顺序表进行增容 
int CheckCapacity(PSeqListD ps);
