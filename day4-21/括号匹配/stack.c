#pragma warning(disable:4996)
# include "stack.h"

//test
void test()
{
	//++++++++++++++
	//²âÊÔ³õÊ¼»¯£¬²åÈë£¬É¾³ý
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));

}

//À¨ºÅ

//³õÊ¼»¯¡£
void StackInit(stack * s)
{
	assert(s);
	s->size = 1;
	s->data = (DataType*)malloc(s->size);
	s->top = 0;
}

//²åÈë
void StackPush(stack * s, DataType data)
{
	assert(s);
	if (s->top == s->size-1)
	{
		s->size *= 2;
		if (NULL == (s->data = (DataType*)realloc(s->data,(s->size))))
			return;
		//¼ì²â
		//printf("successful!\n");
	}
	
	s->data[s->top] = data;
	//printf("s->data[%d]:%d	", s->top, s->data[s->top]);
	s->top++;
	//printf("s->top:%d\n", s->top);
}

void StackPop(stack * s)
{
	assert(s);
	if (s->top)
	{
		s->top--;
	}
}
DataType StackTop(stack * s)
{
	assert(s);
	return s->data[s->top - 1];
}
DataType StackSize(stack * s)
{
	assert(s);
	return s->top;
}
