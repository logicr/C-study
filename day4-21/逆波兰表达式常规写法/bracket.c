#pragma warning(disable:4996)
# include "stack.h"

int bracket(DataType * ch)
{
	assert(ch);
	StackInit(&s);
	while ('\0' !=ch[0])//�ɱ�д�� ch,//д*ch��ch[0]������
	{
		if ('(' == ch[0] || '[' == ch[0] || '{' == ch[0])//����������ţ���ջ
		{
			StackPush(&s, ch[0]);
		}
		else if (')' == ch[0] || ']' == ch[0] || '}' == ch[0])//
		{
			//if (ch[0] == StackTop(&s))//emm.....û�ж���������
			//if ((ch[0] == '(' && ')' == StackTop(&s)) || (ch[0] == '[' && ']' == StackTop(&s)) || (ch[0] == '{' && '}' == StackTop(&s)))//���Ű����� =.=
			if ((ch[0] == ')' && '(' == StackTop(&s)) || (ch[0] == ']' && '[' == StackTop(&s)) || (ch[0] == '}' && '{' == StackTop(&s)))
			{
				StackPop(&s);
			}
			else
			{
				if (0 == StackSize(&s))//ջ�գ����������ţ�˵�������Ŷ�
				{
					printf("�����Ŷ�\n");
					return 0;
				}
				printf("���Ų�ƥ��\n");
				return 0;
			}
		}
		ch++;
	}
	if((StackSize(&s)))//ѭ��������ջ���գ�������϶�������������
	{
		printf("�����Ŷ�\n");
		return 0;
	}
	printf("ƥ��!\n");
	return 1;
}