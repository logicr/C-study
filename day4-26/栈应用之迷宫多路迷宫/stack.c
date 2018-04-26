#pragma warning(disable:4996)
# include "stack.h"




//��ʼ����
void StackInit(stack * s)
{
	assert(s);
	s->size = 64;
	s->po = (position *)malloc(sizeof(position)*s->size);//�������64����СΪposition
	s->top = 0;
}

//����
void StackPush(stack * s, position* posi)//��ջ
{
	assert(s);
	if (s->size == s->top)//�ж�ջ�Ƿ���
	{
		s->size *= 2;
		s->po = (position *)realloc(s->po, sizeof(position)*s->size);
		//printf("���������ڴ���\n");
	}
	s->po[s->top] = *posi;
	//printf("+++++  ����push+++++\n%d  %d\n", posi->x, posi->y);
	s->top++;
}

void StackPop(stack * s)//��ջ
{
	assert(s);
	if (s->top)
	{
		s->top--;
	}
}
int StackEmpty(stack * s)//����Ƿ�Ϊ��ս
{
	assert(s);
	if (s->top)
		return 0;
	return 1;//Ϊ�գ�����1
}
position StackTop(stack * s)//����ջ��Ԫ��
{
	assert(s);
	return s->po[s->top - 1];
}
DataType StackSize(stack * s) //����ջ��Ԫ�ص�����
{
	assert(s);
	return s->top;
}
