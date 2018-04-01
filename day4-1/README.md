	#pragma warning(disable:4996)
	#include <stdio.h>
	struct Test
	{
		int age;
		char name[10];
	};
	int main()
	{
		struct Test one =
		{
			10,
			"hello"
		};
		struct Test two =
		{
			20,
			"Jan"
		};
		one = two;//相同结构的结构体可以整体赋值
		
		return 0;
	
	}
	* “常量”的广义概念是：‘不变化的量’
	*  常量有 整型常量 浮点常量 字符串常量 标识常量
	
