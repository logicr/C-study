#pragma warning(disable:4996)
# include "stack.h"




//初始化。
void StackInit(stack * s)
{
	assert(s);
	s->size = 64;
	s->po = (position *)malloc(sizeof(position)*s->size);//这儿申请64个大小为position
	s->top = 0;
}

//插入
void StackPush(stack * s, position* posi)//入栈
{
	assert(s);
	if (s->size == s->top)//判断栈是否满
	{
		s->size *= 2;
		s->po = (position *)realloc(s->po, sizeof(position)*s->size);
		//printf("正在申请内存呢\n");
	}
	s->po[s->top] = *posi;
	//printf("+++++  正在push+++++\n%d  %d\n", posi->x, posi->y);
	s->top++;
}

void StackPop(stack * s)//出栈
{
	assert(s);
	if (s->top)
	{
		s->top--;
	}
}
int StackEmpty(stack * s)//检测是否为空战
{
	assert(s);
	if (s->top)
		return 0;
	return 1;//为空，返回1
}
position StackTop(stack * s)//返回栈顶元素
{
	assert(s);
	return s->po[s->top - 1];
}
DataType StackSize(stack * s) //返回栈中元素的数量
{
	assert(s);
	return s->top;
}
