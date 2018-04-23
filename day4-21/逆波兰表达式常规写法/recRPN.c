#pragma warning(disable:4996)
# include "stack.h"

enum SYS
{
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/'
};

//逆波兰表达式的递归写法
//递归出口是字符串到达'\0'
 DataType  _recpolan(char* exp,stack s)
{

	DataType num = 0;
	DataType left = 0;
	DataType right = 0;
	if ('\0' != *exp)//
	{
		while ('0' <= *exp && *exp <= '9')//拿数字
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
		_recpolan(exp, s);
		 return StackTop(&s);//递归一结束就返回，栈顶的值。
	}
	return 0;//空字符串，返回0
}





DataType recRPN(char * exp)
{
	StackInit(&s);
	assert(exp);
	int result = _recpolan(exp, s);
	return result;
}

