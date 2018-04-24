#pragma warning(disable:4996)
# include "stack.h"


//1. 用栈堆简单迷宫进行求解，迷宫只有一个出口
//采用循环方式实现
//// 栈的初始化 
void InitMaze(Maze* m, int map[][L])//2
{
	assert(m);
	//m->m = map;

	int i = 0;
	int j = 0;
	for (i = 0; i < R; i++)
	{

		for (j = 0; j < L; j++)
		{
			//printf("%d  ", m->m[i][j]);
			m->m[i][j] = map[i][j];
			printf("%d  ", m->m[i][j]);
		}
		printf("\n");
	}
}
//
//// 检测入口是否为有效入口 
int IsValidEntry(Maze* m, position entry)//3
{
	return (1 == (m->m[entry.x][entry.y])) && ((0 == entry.x || L - 1 == entry.x) || (0 == entry.y || R - 1 == entry.y) && 0 <= entry.x && entry.x <= R) && (0 <= entry.y &&  entry.y <= L);

}
//
//// 检测cur位置是否是通路 
int IsPass(Maze* m, position cur)
{
	return ((0 <= cur.x && cur.x <= R - 1) && (0 <= cur.y &&  cur.y <= L - 1) && (1 == (m->m[cur.x][cur.y])));
}
//
//// 检测pCur是否在出口 
int IsExit(Maze* m, position cur, position entry)
{
	if ((1 == (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y))
	{
		printf("+++++++++++++++++++++++++   1    +++++++++++++++++++++++++\n");
	}
	return (1 == (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y);
}
//
//// 走迷宫 
void PassMaze(Maze* m, position entry, stack* s)//1
{
	//1.入口检合法性测
	//上左右下走，检测下一步是否通路
	//标记走过的点标记为2，入栈
	//3.路不通，回退
	if (!IsValidEntry(m, entry))
	{
		return;
	}
	position cur;
	cur.x = entry.x;
	cur.y = entry.y;
	m->m[entry.x][entry.y] = 2;
	StackPush(s, &cur);
	while (!IsExit(m, StackTop(s), entry))
	{
		//上
		//PrintMaze(m, m->m);
		position tmp = cur;
		tmp.x = tmp.x - 1;
		if (IsPass(m, tmp))
		{
			cur.x = cur.x - 1;
			m->m[cur.x][cur.y] = 2;
			StackPush(s, &cur);
			continue;
		}
		tmp = cur;
		tmp.y = tmp.y - 1;
		if (IsPass(m, tmp))
		{
			cur.y = cur.y - 1;
			m->m[cur.x][cur.y] = 2;
			StackPush(s, &cur);
			continue;
		}
		tmp = cur;
		tmp.y = tmp.y + 1;
		if (IsPass(m, tmp))
		{
			cur.y = cur.y + 1;
			m->m[cur.x][cur.y] = 2;
			StackPush(s, &cur);
			continue;
		}
		tmp = cur;
		tmp.x = tmp.x + 1;
		if (IsPass(m, tmp))
		{
			cur.x = cur.x + 1;
			m->m[cur.x][cur.y] = 2;
			StackPush(s, &cur);
			continue;
		}
		cur = StackTop(s);
		m->m[cur.x][cur.y] = 3;
		StackPop(s);
	}
	return;

}
//
//// 打印迷宫 
void PrintMaze(Maze* m, int map[][L])
{
	/*m->m = map;*/
	int i = 0;
	int j = 0;
	for (i = 0; i < R; i++)
	{

		for (j = 0; j < L; j++)
		{
			//printf("%d  ", m->m[i][j]);
			printf("%d  ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
//






//2. 用递归方式实现简单迷宫：即只有一个出口迷宫
//void InitMaze(Maze* m, int map[][MAX_COL]);
//int IsValidEntry(Maze* m, Position entry);
//int IsPass(Maze* m, Position cur);
//int IsExit(Maze* m, Position cur, Position entry);
//
//// 真正走迷宫函数 
//int _PassMaze(Maze* m, Position entry, Position cur, Stack* s);//Maze* m,迷宫   Position entry,入口   Position cur,当前位置    Stack* s 栈
//
//// 提供给用户使用的走迷宫函数，与上上个走迷宫函数的区别是：用户不用去传当前步，只需要给入口就行 
//void PassMaze(Maze* m, Position entry, Stack* s);
//void PrintMaze(Maze* m, int map[][MAX_COL]);
//
//3. 如果迷宫有多条路口，但是路口没有构成环，怎么求最短路径
//4、 如果多个路口构成环，如何求最短路径-- - 大家在底下自己先尝试去写
//5、自行去了解下A*寻路算法
