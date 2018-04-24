#pragma warning(disable:4996)
# include "stack.h"
//# include "maze.h"
//test
//void test()
//{
//	//++++++++++++++
//	//测试初始化，插入，删除
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

//括号

//初始化。
void StackInit(stack * s)
{
	assert(s);
	s->size = 64;
	s->po = (position *)malloc(sizeof(position)*s->size);//这儿申请64个大小为position
	s->top = 0;
}

//插入
void StackPush(stack * s, position* posi)
{
	assert(s);
	if (s->size == s->top)//判断栈是否满
	{
		s->size *= 2;
		s->po = (position *)realloc(s->po, sizeof(position)*s->size);
		printf("正在申请内存呢\n");
	}
	s->po[s->top] = *posi;
	printf("+++++  正在pus  h+++++\n%d  %d\n", posi->x, posi->y);
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
