#pragma warning(disable:4996)
# include <stdio.h>
# include <string.h>
# include <memory.h>
# include <stdlib.h>
//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：
//姓名、性别、年龄、电话、住址
//
//提供方法：
//1.	添加联系人信息
//2.	删除指定联系人信息
//3.	查找指定联系人信息
//4.	修改指定联系人信息
//5.	显示所有联系人信息
//6.	清空所有联系人
//7.	以名字排序所有联系人
# define N 1001
//# define N 10 //调试
struct Contact
{
	char name[20];
	int age;
	char sex[10];
	double num;
	char addr[100];
	int flag;

}con[N], *tem;

void init(struct Contact pc[], int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		(pc + i)->flag = 0;
	}
}
void add_contact(struct Contact pc[], int number){//添加
	int i = 0;
	while (1)
	{
		int  ju = 0;
		if (0 == pc[i].flag && number>i)
		{
			pc[i].flag = 1;
			printf("             please input name:\n");
			scanf("%s", pc[i].name);
			printf("             please input age:\n");
			scanf("%d", &pc[i].age);
			printf("             please input sex:\n");
			scanf("%s", pc[i].sex);
			printf("             please input phonenumber:\n");
			scanf("%lf", &pc[i].num);
			printf("             please input address:\n");
			scanf("%s", pc[i].addr);
			printf("             The contact has been saved!\n");
			printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[i].name, \
				pc[i].sex, pc[i].age, pc[i].num, pc[i].addr);
			i++;

			{
				printf("             Do you want to coutine? 1.continue 0.finish:\n");
				scanf("%d", &ju);

				if (0 == ju)
				{
					return;
				}
			}
		}
		else
		{
			i++;
			if (number < i)
			{
				printf("The contact is fill\n");
				return;
			}
			continue;
		}

	}
}

void de_contact(struct Contact pc[], int number)//删除
{
	int key = 1;
	int se = 0;
	printf("             Do you want to delete contacts by whitch means?\n             1.name 2.number  other:quit\n");
	scanf("%d", &se);
	switch (se)
	{
	case 1:
	{
			  char na[20] = { 0 };
			  printf("Please input name :\n");
			  scanf("%s", na);
			  int j = 0;
			  for (j = 0; j <number; j++)
			  {
				  if ((0 != pc[j].flag) && (0 == strcmp(pc[j].name, na)))
				  {
					  printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[j].name, \
						  pc[j].sex, pc[j].age, pc[j].num, pc[j].addr);
					  printf("find this ,0.cancel other delete\n");
					  scanf("%d", &key);
					  if (0 == key){
						  continue;
					  }
					  pc[j].flag = 0;
					  printf("             delete successfully! \n");
					  return;
				  }

			  }
			  printf("             tnis man \"%s\"not exist, please chekc it!\n", na);
	}
		break;
	case 2:
	{
			  double num = 0;
			  printf("Please input number :\n");
			  scanf("%lf", &num);
			  int j = 0;
			  for (j = 0; j < number; j++)
			  {
				  if ((0 != pc[j].flag) && (pc[j].num == num))
				  {
					  printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[j].name, \
						  pc[j].sex, pc[j].age, pc[j].num, pc[j].addr);
					  printf("find this ,0.cancel other delete\n");
					  scanf("%d", &key);
					  if (0 == key){
						  continue;
					  }
					  pc[j].flag = 0;
					  printf("             delete successfully! \n");
					  return;
				  }
			  }
			  printf("             tnis man \"%s\"not exist, please chekc it!\n", num);
	}
		break;
	default:
		break;

	}

}
void find_contact(struct Contact pc[], int number)//查找
{
	int flag = 0;
	int se = 0;
	printf("             Do you want to find contacts by whitch means?\n             1.name 2.number other:quit\n");
	scanf("%d", &se);
	switch (se)
	{
	case 1:
	{
			  char na[20] = { 0 };
			  printf("Please input name :\n");
			  scanf("%s", na);
			  int j = 0;
			  for (j = 0; j <number; j++)
			  {
				  if ((0 != pc[j].flag) && (0 == strcmp(pc[j].name, na)))
				  {
					  flag = 1;
					  //pc[j].flag = 0;
					  printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[j].name, \
						  pc[j].sex, pc[j].age, pc[j].num, pc[j].addr);

				  }

			  }
			  if (number <= j && 0 == flag)
			  {
				  printf("             tnis man \"%s\"not exist, please chekc it!\n", na);
			  }
	}
		break;
	case 2:
	{
			  double num = 0;
			  printf("Please input number :\n");
			  scanf("%lf", &num);
			  int j = 0;
			  for (j = 0; j <number; j++)
			  {
				  if ((0 != pc[j].flag) && (pc[j].num == num))
				  {
					  flag = 1;
					  //pc[j].flag = 0;
					  printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[j].name, \
						  pc[j].sex, pc[j].age, pc[j].num, pc[j].addr);

				  }
			  }
			  if (number <= j && 0 == flag)
			  {
				  printf("             This number \"%s\"not exist, please chekc it!\n", num);
			  }
	}
		break;
	default:
		break;

	}
}

void change_contact(struct Contact pc[], int number)//修改
{
	int se = 0;
	printf("             Do you want to change contacts by whitch means?\n             1.name 2.number other:quit\n");
	scanf("%d", &se);
	switch (se)
	{
	case 1:
	{
			  char na[20] = { 0 };
			  printf("Please input name :\n");
			  scanf("%s", na);
			  int j = 0;
			  for (j = 1; j <number; j++)
			  {
				  if ((0 != pc[j].flag) && (0 == strcmp(pc[j].name, na)))
				  {
					  //pc[j].flag = 0;
					  printf("             The contact \"%s\" has been find \n", na);
					  printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[j].name, \
						  pc[j].sex, pc[j].age, pc[j].num, pc[j].addr);
					  printf("             please input name:\n");
					  scanf("%s", pc[j].name);
					  printf("             please input age:\n");
					  scanf("%d", &pc[j].age);
					  printf("             please input sex:\n");
					  scanf("%s", pc[j].sex);
					  printf("             please input phonenumber:\n");
					  scanf("%lf", &pc[j].num);
					  printf("             please input address:\n");
					  scanf("%s", pc[j].addr);
					  printf("             The contact has been saved!\n");
					  printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[j].name, \
						  pc[j].sex, pc[j].age, pc[j].num, pc[j].addr);
				  }

			  }
			  if (number <= j)
			  {
				  printf("             tnis man \"%s\"not exist, please chekc it!\n", na);
			  }
	}
		break;
	case 2:
	{
			  double num = 0;
			  printf("Please input number :\n");
			  scanf("%lf", &num);
			  int j = 0;
			  for (j = 1; j <number; j++)
			  {
				  if ((0 != pc[j].flag) && (pc[j].num == num))
				  {
					  //pc[j].flag = 0;
					  printf("             the number \"%d\" has been  find\n", num);
					  printf("              :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[j].name, \
						  pc[j].sex, pc[j].age, pc[j].num, pc[j].addr);
					  printf("             please input name:\n");
					  scanf("%s", pc[j].name);
					  printf("             please input age:\n");
					  scanf("%d", &pc[j].age);
					  printf("             please input sex:\n");
					  scanf("%s", pc[j].sex);
					  printf("             please input phonenumber:\n");
					  scanf("%lf", &pc[j].num);
					  printf("             please input address:\n");
					  scanf("%s", pc[j].addr);
					  printf("             The contact has been saved!\n");
					  printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[j].name, \
						  pc[j].sex, pc[j].age, pc[j].num, pc[j].addr);
				  }
			  }
			  if (num <= j)
			  {
				  printf("             tnis man \"%s\"not exist, please chekc it!\n", num);
			  }
	}
		break;
	default:
		break;

	}


}
void des_contact(struct Contact pc[], int num)//显示
{
	int i = 0;
	printf("             -------------------------------Contacts---------------------------------\n");
	for (i = 0; i < num; i++)
	{
		if (1 == pc[i].flag)
		{
			printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s\n", pc[i].name, \
				pc[i].sex, pc[i].age, pc[i].num, pc[i].addr);
			//i++;
		}
	}

	printf("             ------------------------------------------------------------------------\n");

}
void emp_contact(struct Contact pc[], int num)//清空
{
	int i = 0;
	printf("             ----------------------delete all contacts now----------------------------\n");
	while (1)
	{
		if (1 == pc[i].flag)
		{
			pc[i].flag = 0;
			printf("             name :%s sex :%s age :%d phonenumber :%.0lf address :%s bas been deleted\n", pc[i].name, \
				pc[i].sex, pc[i].age, pc[i].num, pc[i].addr);
			pc[i].flag = 0;

		}

		if (num <= i)
		{
			break;
		}
		i++;
	}

	printf("             ------------------------------------------------------------------------\n");

}
void sort_contact(struct Contact pc[], int num)//排序
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		if (0 == pc[i].flag)
		{
			continue;
		}
		int j = 0;
		for (j = 0; j < num - i; j++)
		{
			if (1 == strcmp(pc[j].name, pc[j + 1].name))
			{
				//这里传进去的是一个结构体，所以用 pc 来作为临时变量，
				//而且0刚好是[0~1000]多出来的一个元素，正好免去了存放时类型转换的问题，sizeof(con[0])也恰好证明了拷贝了整个结构体
				memcpy(tem, pc + j, sizeof(con[0]));
				memcpy(pc + j, pc + j + 1, sizeof(con[0]));
				memcpy(pc + j + 1, tem, sizeof(con[0]));
			}
		}
	}
}
int main()
{
	int input = 1;
	int num = 1000;
	struct Contact temp = {
		"",
		0,
		"",
		0,
		0
	};
	tem = &temp;
	printf("input contacr numner:\n");
	scanf("%d", &num);
	struct Contact * conp = (struct Contact *) malloc(num * sizeof (struct Contact));
	init(conp, num);//初始化comp 的flag
	while (input)
	{
		printf("\n\n\n\n");
		printf("             **************************************************************************\n");
		printf("             *   1.add contact         2.delete contact        3.find contact         *\n");
		printf("             *   4.modify contact      5.disply contact        6.empty all contact    *\n");
		printf("             *   7.sort contact        0.qiut                                         *\n");
		printf("             **************************************************************************\n");
		printf("\n\n\n\n");
		scanf("%d", &input);
		switch (input)
		{
			//1.	添加联系人信息
		case 1:
		{
				  add_contact(conp, num);
		}
			break;
			//2.	删除指定联系人信息
		case 2:
		{
				  de_contact(conp, num);
		}
			break;
			//3.	查找指定联系人信息
		case 3:
		{
				  find_contact(conp, num);
		}
			break;
			//4.	修改指定联系人信息
		case 4:
		{
				  change_contact(conp, num);
		}
			break;
			//5.	显示所有联系人信息
		case 5:
		{
				  des_contact(conp, num);
		}
			break;
			//6.	清空所有联系人
		case 6:
		{
				  emp_contact(conp, num);
		}
			break;
			//7.	以名字排序所有联系人
		case 7:
		{
				  sort_contact(conp, num);
		}
			break;
		default:
			break;
		}
	}
	return 0;
}
