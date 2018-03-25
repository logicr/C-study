#pragma warning(disable:4996)
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
void print_num(int x)
{
	/*if (x > 9)
	{
		return print_num(x / 10);//发现了我对递归的一种错误用法//发现结果一直为1
	}
	putchar(x % 10 + '0');*/
	if (x > 9)
	{
		 print_num(x / 10);
	}
	putchar(x % 10 + '0');
}
int nprint(const char * format, ...)
{
	va_list args;
	va_start(args, format);
	char * pr = format;//
	while (*pr)
	{
		switch (*pr)
		{
		case '%':
		{
					switch (*(++pr))
					{
					case 's':
					{
								char * str = va_arg(args, char*);//char*
								while (*str)
								{
									putchar(*str);
									str++;
								}
					}
							break;
					case'c':
					{
							   putchar(va_arg(args,char));
					}
						break;
					case'd':
					{
							   print_num(va_arg(args, int));
					}
						break;
					default:
					{
							   putchar(*(pr - 1));
							   putchar(*pr);
					}
						break;
					}
		}
			break;
		default:
		{
				   putchar(*pr);
		}
			break;
		}
		pr++;
	}

	va_end(args);
	return 0;
}
int main()
{
	nprint("%q%w%e%r%t测试一下会不会有其他%的\n%s %c%c%c %d\n","hello Jan",'J','a','n',1997);
	return 0;
}
