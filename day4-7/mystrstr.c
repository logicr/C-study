#pragma warning(disable:4996)
# include "order.h"

char * mystrstr(const char * des, const char * src)
{
	assert(des);
	assert(src);
	while ('\0' != *des)
	{
		const char * subdes = des;//母串指针浮动
		const char * subsrc = src;//始终指向子串的头
		while ((*subdes == *subsrc) && ('\0' != *subdes) && ('\0' != *subsrc))//必须加空的判断，如果两个都\0也会进入循环
		{
			++subdes;
			++subsrc;
		}
		if ('\0' == *subsrc)//如果subsrc为\0，则说明子串都和母串匹配上了。
		{
			return des;
		}
		++des;
	}//循环结束说明一直没有匹配，返回空
	return NULL;
}
int main()
{
	char *str1 = "helloJan";
	char *str2 = "Jan";
	printf("%s\n", mystrstr(str1, str2));
	return 0;
}
