#pragma warning(disable:4996)
# include "stack.h"

enum SYS
{
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/'
};

//�沨�����ʽ�ĵݹ�д��
//�ݹ�������ַ�������'\0'
 DataType  _recpolan(char* exp,stack s)
{

	DataType num = 0;
	DataType left = 0;
	DataType right = 0;
	if ('\0' != *exp)//
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
		_recpolan(exp, s);
		 return StackTop(&s);//�ݹ�һ�����ͷ��أ�ջ����ֵ��
	}
	return 0;//���ַ���������0
}





DataType recRPN(char * exp)
{
	StackInit(&s);
	assert(exp);
	int result = _recpolan(exp, s);
	return result;
}

