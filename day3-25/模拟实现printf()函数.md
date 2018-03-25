<font face = "幼圆" color = "#2f4f4f" size = "4" > 在构建`printf()`函数之前，需要简单分析`printf()`，在帮助文档中可以看到，`printf()`的格式为`printf (char * format,...)` </font>
![printf_format](//img-blog.csdn.net/20180319081829134?watermark/2/text/Ly9ibG9nLmNzZG4ubmV0L0xvZ2ljcg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

>也就是说`printf()`是一个可变参数的函数

---
<font color ="red"></font>
<font face="幼圆" color="black" size="4"> 此外，还需要了解这些参数是如何在内存中存储的。从这个栈桢结构图中可以看到print()函数的参数的存放方式，<font color ="red">print()中的参数在形成临时变量时是从右往左的</font>，这也就可以解释为什么只传入 char * format 就可以定位后面的不可变参数部分，char* format 作为左后一个传入的参数，可以方便的取出它的地址，那么下一个类型的地址就是第二个参数的地址</font>
![栈桢](//img-blog.csdn.net/20180319092753159?watermark/2/text/Ly9ibG9nLmNzZG4ubmV0L0xvZ2ljcg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

<font face="幼圆" color="gray" size="4">那么现在就可以开始写这个print()</font>

```
#pragma warning(disable:4996)
# include <stdio.h>
# include <stdarg.h>
//模拟实现printf函数，可完成下面的功能

//print("s ccc d\n", "hello", 'J', 'a', 'n', 100);
//print("你好 Jan\n");//对引号内容的直接输出
//能完成下面函数的调用。 
//函数原型： 
//print(char *format, ...) 
//
int print(char *s,...)
{
	int i = 0;
	va_list str; //声明一个va_list 类型 str//头文件 # include <stdarg.h>
	va_start(str, s);//初始化
		char* ch = s;//将第一个参数保存，也就是"s ccc d \n"，因为不能直接将其存到*ch里
		int a = va_arg(str, char);//这里是为了让va_arg(str,char)指向下一个参数，使用一次va_arg(str,char)，因为va_arg(str,char)每使用一次就会自动指向下一个参数。
		while (*ch)//构建一个循环来打印参数
		{
			if (*ch == 's')//当遇到's'时，说明需要打印字符串
			{
				char *put = *(&s + 1);//取"hello",用指针的原因是直接用va_arg(str,char)存放时放不下。(不是这样的...因该是用(str,char*))
				while (*put)//循环打印"hello"的每个字符
				{
					putchar(*(put));
					put++;
				}
			}
			else if (*ch == 'c')//打印单个字符
			{
				putchar(va_arg(str, char));
			}
			else if (*ch == 'd')//打印整数
			{
				//因为声明是char*类型，这里的数字也会被认为是char类型的，需要转化一下
				int a = va_arg(str, char);//存整数
				int arr[20] = { 0 };//定义一个数组存放整数的每一位
				int cou = 0;
				int tmp = a;
				while (a > 9)//取每一位
				{
					tmp = a % 10;
					a = a / 10;
					cou++;
					arr[cou] = tmp;
					arr[cou] = tmp;
				} 
				arr[cou] = a;//补上最后一次循环的内容
				while (cou)//循环打印每一位
				{
					putchar(arr[cou]+48);
					cou--;
				}
				putchar(arr[cou] + 48);//补上左后一次循环的打印结果
			}
			else//无特殊条件直接输出
			{
				putchar(*ch);
			}
			ch++;
		}
	}
int main()
{
	print("s ccc d\n", "hello", 'J', 'a', 'n', 100);
	print("s \n你好1997\n","你好");
	return 0;
}
```
![print_result](//img-blog.csdn.net/20180319103334232?watermark/2/text/Ly9ibG9nLmNzZG4ubmV0L0xvZ2ljcg==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

----

> <font face="幼圆" color=red size="7">更新

<font face = "仿宋" color = "2F4F4F" size ="4"> 看了几遍第一次写的printf，越看越觉得不舒服，所以重新写了一遍
	* 优化打印格式，对齐库函数printf格式，使用'%'打印；
	* 优化多个if()判断为switch()；
	* 优化数字打印，使用递归打印
	* 优化代码，修改几处不规范的用法
	* 优化注释，简洁
	* 优化代码风格，整齐划一
	* 发现自己递归的一处用法错误
	* ...

```
#pragma warning(disable:4996)
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
void print_num(int x)//递归打印%d的数字打印函数
{
	/*if (x > 9)
	{
		return print_num(x / 10);//发现了我对递归的一种错误用法//发现结果一直为1，不能随便加return
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
	char * pr = format;//获取第一个元素"%...."
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
								char * str = va_arg(args, char*);//因为是字符串，所以要用char*解引用，上次用(ards,char)怎么都不对。
								while (*str)
								{
									putchar(*str);
									str++;
								}
					}
						break;
					case'c':
					{
							   putchar(va_arg(args,char));//单个字符打印
					}
						break;
					case'd':
					{
							   print_num(va_arg(args, int));//递归打印，注意这里的(args,int)是int，整形，不是全都charcharchar
					}
						break;
					default:
					{
							   putchar(*(pr - 1));//是'%'但后面跟的字符不是要打印的格式化字符，直接输出'%'，以及当前字符。
							   putchar(*pr);
					}
						break;
					}
		}
			break;
		default://第一个不是'%'的,直接输出
		{
				   putchar(*pr);
		}
			break;
		}
		pr++;//
	}

	va_end(args);
	return 0;
}
int main()
{
	nprint("%q%w%e%r%t测试一下会不会有其他%的\n%s %c%c%c %d\n","hello Jan",'J','a','n',1997);
	return 0;
}
```
![print](http://img.blog.csdn.net/20180325105447058?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvTG9naWNy/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)