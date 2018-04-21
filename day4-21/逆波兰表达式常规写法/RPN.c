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
	while ('\0' != *exp)//手误删了，重新写了一遍，我的妈呀。。。。。。。。。。。。。
	{
		while ('0' <= *exp && *exp <= '9')//那数字
		{
			num = num * 10 + (*exp - '0');
			exp++;
		}
		if (' ' == *exp && '0' <= *(exp - 1) && *(exp - 1) <= '9')//若上一步处理的是数字，入栈
		{
			StackPush(&s, num);
		}
		num = 0;//记得清零
		switch (*exp)//符号判断
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
						printf("除零\n");
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

