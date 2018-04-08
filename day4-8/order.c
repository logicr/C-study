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
	SeqListPopBack(&s);//尾删
	SeqListPushFront(&s, 100);//头插
	SeqListPopFront(&s);//头删
	SeqListInsert(&s, 5, 20);//任意插入
	SeqListErase(&s, 5);//任意删
	//Remove(&s, 5);//删除第一个出现的
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 5);
	RemoveAll(&s, 5);//删除出现的5
	int a = SeqListFind(&s,1);
	SeqListPushBack(&s, 11);
	SeqListPushBack(&s, 13);
	SeqListPushBack(&s, 12);
	PrintSeqList(&s);//打印函数
	SelectSort(&s);//选择排序
	//BubbleSort(&s);//冒泡排序
	PrintSeqList(&s);

}
//顺序表初始化
void SeqListInit(PSeqList ps)
{
	if (NULL == ps)
	{
		printf("空指针\n");
		return ;
	}
	ps->_size = 0;
}
// 顺序表的尾插 
void SeqListPushBack(PSeqList ps, DataType data)
{
	if (NULL == ps)
	{
		printf("空指针\n");
		assert(0);
	}
	if (MAX_SIZE == ps->_size)
	{
		printf("空间已满，无法写入\n");
		return;
	}
	ps->_array[ps->_size] = data;
	ps->_size++;
}

// 顺序表的尾删 
void SeqListPopBack(PSeqList ps)
{
	if (NULL == ps)
	{
		printf("空指针\n");
		assert(0);
	}
	ps->_size--;
}

// 顺序表的头插 
void SeqListPushFront(PSeqList ps, DataType data)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("空指针\n");
		assert(0);
	}
	if (MAX_SIZE == ps->_size)
	{
		printf("空间已满，无法写入\n");
		return;
	}
	for (i = ps->_size; i > 0; --i)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = data;
	ps->_size++;
}

// 顺序表的头删 
void SeqListPopFront(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("空指针\n");
		assert(0);
	}
	if (MAX_SIZE == ps->_size)
	{
		printf("空间已满，无法写入\n");
		return;
	}
	for (i = 0; i < ps->_size - 1; ++i)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

// 顺序表pos位置插入元素data 
void SeqListInsert(PSeqList ps, int pos, DataType data)
{
	int i = 0;
	if (NULL == ps || pos < 0 || pos > ps->_size)
	{
		printf("指针或插入位置有误\n");
		assert(0);
	}
	if (MAX_SIZE == ps->_size)
	{
		printf("空间已满，无法写入\n");
		return;
	}
	for (i =ps->_size ; i >pos ; i --)
	{
		ps->_array[i] = ps->_array[i-1];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

// 删除顺序表pos位置元素 
void SeqListErase(PSeqList ps, int pos)
{
	int i = 0;
	if (NULL == ps ||pos < 0 || pos > ps->_size)
	{
		printf("指针或插入位置有误\n");
		return ;
	}
	for (i = pos; i < ps->_size; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

// 移除顺序表中第一个值为data的元素 
void Remove(PSeqList ps, DataType data)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("空指针\n");
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

// 移除顺序表中所有值为data的元素 
void RemoveAll(PSeqList ps, DataType data)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("空指针\n");
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
			i--;//不用再重新遍历一次，i回退一次，就不会跳过当前元素了
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

// 在顺序表中查找值为data的元素，找到返回该元素在顺序表中的位置，否则返回-1 
int SeqListFind(PSeqList ps, DataType data)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("空指针\n");
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

// 获取顺序表中元素的个数 
int SeqListSize(PSeqList ps)
{
	if (NULL == ps)
	{
		printf("空指针\n");
		return -1;
	}
	return ps->_size;
}



////////////////////////////////////////////////// 
//辅助操作 
// 打印顺序表 
void PrintSeqList(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("空指针\n");
		return;
	}
	printf("当前元素个数为：%d\n", ps->_size);
	for (i = 0; i < ps->_size; i++)
	{
		printf("%d  ", ps->_array[i]);
	}
	printf("\n");
}

void swap(int *po, int *pt)
{
	/*
	int tmp = po;//这个之所以不行，因为这样交换的是指针地址，里面的内容并没有交换
	po = pt;
	pt = tmp;
	*/
	int tmp = *po;
	*po = *pt;
	*pt = tmp;
}
// 使用冒泡排序对顺序表中的元素进行排序 
void BubbleSort(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("空指针\n");
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

// 使用选择排序堆顺序表中的元素进行排序 
void SelectSort(PSeqList ps)
{
	int i = 0;
	if (NULL == ps)
	{
		printf("空指针\n");
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
