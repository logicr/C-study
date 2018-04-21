#pragma warning(disable:4996)
# include "stack.h"


extern int bracket(DataType * ch);
int main()
{
	//test();
	DataType ch[] = "{{}";
	bracket(ch);

	return 0;
}