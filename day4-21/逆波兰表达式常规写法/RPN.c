#pragma warning(disable:4996)
# include "stack.h"

enum SYS
{
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/'
};


DataType RPN(char * exp)
{
	DataType num = 0;
	DataType left = 0;
	DataType right = 0;
	StackInit(&s);
	assert(exp);
	while ('\0' != *exp)//����ɾ�ˣ�����д��һ�飬�ҵ���ѽ��������������������������
	{
		while ('0' <= *exp && *exp <= '9')//������
		{
			num = num * 10 + (*exp - '0');
			exp++;
		}
		if (' ' == *exp && '0' <= *(exp - 1) && *(exp - 1) <= '9')//����һ������������֣���ջ
		{
			StackPush(&s, num);
		}
		num = 0;//�ǵ�����
		switch (*exp)//�����ж�
		{
		case ADD:
		{
					right = StackTop(&s);
					StackPop(&s);
					left = StackTop(&s);
					StackPop(&s);
					StackPush(&s, left + right);
		}
			break;
		case SUB:
		{
					right = StackTop(&s);
					StackPop(&s);
					left = StackTop(&s);
					StackPop(&s);
					StackPush(&s, left - right);
		}
			break;
		case MUL:
		{
					right = StackTop(&s);
					StackPop(&s);
					left = StackTop(&s);
					StackPop(&s);
					StackPush(&s, left * right);
		}
			break;
		case DIV:
		{
					right = StackTop(&s);
					StackPop(&s);
					if (0 == (left = StackTop(&s)))
					{
						printf("����\n");
						return -1;
					}
					StackPop(&s);
					StackPush(&s, left / right);
		}
			break;
		default:
			break;
		}
		exp++;
	}
	return StackTop(&s);
}

