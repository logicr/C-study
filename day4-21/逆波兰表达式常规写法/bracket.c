#pragma warning(disable:4996)
# include "stack.h"

int bracket(DataType * ch)
{
	assert(ch);
	StackInit(&s);
	while ('\0' !=ch[0])//可别写成 ch,//写*ch、ch[0]都可以
	{
		if ('(' == ch[0] || '[' == ch[0] || '{' == ch[0])//如果是左括号，入栈
		{
			StackPush(&s, ch[0]);
		}
		else if (')' == ch[0] || ']' == ch[0] || '}' == ch[0])//
		{
			//if (ch[0] == StackTop(&s))//emm.....没判断括号类型
			//if ((ch[0] == '(' && ')' == StackTop(&s)) || (ch[0] == '[' && ']' == StackTop(&s)) || (ch[0] == '{' && '}' == StackTop(&s)))//括号安反了 =.=
			if ((ch[0] == ')' && '(' == StackTop(&s)) || (ch[0] == ']' && '[' == StackTop(&s)) || (ch[0] == '}' && '{' == StackTop(&s)))
			{
				StackPop(&s);
			}
			else
			{
				if (0 == StackSize(&s))//栈空，还有右括号，说明右括号多
				{
					printf("右括号多\n");
					return 0;
				}
				printf("括号不匹配\n");
				return 0;
			}
		}
		ch++;
	}
	if((StackSize(&s)))//循环结束，栈不空，那里面肯定还存了左括号
	{
		printf("左括号多\n");
		return 0;
	}
	printf("匹配!\n");
	return 1;
}