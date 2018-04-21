#pragma warning(disable:4996)
# include "stack.h"

int bracket(DataType * ch)
{
	StackInit(&s);
	while ('\0' !=ch[0])
	{
		if ('(' == ch[0] || '[' == ch[0] || '{' == ch[0])
		{
			StackPush(&s, ch[0]);
		}
		else if (')' == ch[0] || ']' == ch[0] || '}' == ch[0])
		{
			//if (ch[0] == StackTop(&s))
			//if ((ch[0] == '(' && ')' == StackTop(&s)) || (ch[0] == '[' && ']' == StackTop(&s)) || (ch[0] == '{' && '}' == StackTop(&s)))
			if ((ch[0] == ')' && '(' == StackTop(&s)) || (ch[0] == ']' && '[' == StackTop(&s)) || (ch[0] == '}' && '{' == StackTop(&s)))
			{
				StackPop(&s);
			}
			else
			{
				printf("¿®∫≈≤ª∆•≈‰\n");
				return 0;
			}
		}
		ch++;
	}
	if((StackSize(&s)))
	{
		printf("◊Û¿®∫≈∂‡\n");
		return 0;
	}
	printf("∆•≈‰!\n");
	return 1;
}