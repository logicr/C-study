#pragma warning(disable:4996)
# include "stack.h"
//# include "maze.h"
//test
//void test()
//{
//	//++++++++++++++
//	//���Գ�ʼ�������룬ɾ��
//	entry.x = 1;
//	entry.y = 2;
//	StackInit(&s);
//	StackPush(&s, &entry);
//	StackPush(&s, &entry);
//	StackPush(&s, &entry);
//	StackPush(&s, &entry);
//	StackPush(&s, &entry);
//	for (int i = 0; i < 130; i++)
//	{
//		StackPush(&s, &entry);
//
//	}
//	printf("%d\n", StackTop(&s).x);
//	printf("%d\n", StackSize(&s));
//	StackPop(&s);
//	printf("%d\n", StackTop(&s));
//	printf("%d\n", StackSize(&s));
//
//}

//����

//��ʼ����
void StackInit(stack * s)
{
	assert(s);
	s->size = 64;
	s->po = (position *)malloc(sizeof(position)*s->size);//�������64����СΪposition
	s->top = 0;
}

//����
void StackPush(stack * s, position* posi)
{
	assert(s);
	if (s->size == s->top)//�ж�ջ�Ƿ���
	{
		s->size *= 2;
		s->po = (position *)realloc(s->po, sizeof(position)*s->size);
		printf("���������ڴ���\n");
	}
	s->po[s->top] = *posi;
	printf("+++++  ����pus  h+++++\n%d  %d\n", posi->x, posi->y);
	s->top++;
}

void StackPop(stack * s)
{
	assert(s);
	if (s->top)
	{
		s->top--;
	}
}
position StackTop(stack * s)
{
	assert(s);
	return s->po[s->top - 1];
}
DataType StackSize(stack * s)
{
	assert(s);
	return s->top;
}
