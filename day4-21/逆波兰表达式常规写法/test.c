#pragma warning(disable:4996)
# include "stack.h"


extern int bracket(DataType * ch);

extern DataType RPN(char * exp);//表达式
int main()
{
	//test();
	//DataType ch[] = "{{}}}";//测试括号匹配
	//bracket(ch);


	//测RPN
	char ch[] = "12 3 4 + * 6 - 8 2 / +";
	printf ("%d\n",RPN(ch));

	return 0;
}