#pragma warning(disable:4996)
# include "stack.h"
//4、 如果多个路口构成环，如何求最短路径-- - 大家在底下自己先尝试去写
//5、自行去了解下A*寻路算法


//+++++++++++++++++++++++++++++++++++++++++



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
int IsPass(Maze* m, position cur ,position tmp)//	if (IsPass(m, cur, tmp))
{
	printf("+++++++++判断+++++++++++\n当前的:[%d][%d]		", cur.x, cur.y);
	printf("下一步:[%d][%d]  \n", tmp.x, tmp.y);
	return ((0 <= tmp.x && tmp.x <= R - 1) && (0 <= tmp.y &&  tmp.y <= L - 1) && ((1 == (m->m[tmp.x][tmp.y])) || (m->m[cur.x][cur.y]) < (m->m[tmp.x][tmp.y])));
	//不在边界，为1或比当前大
}
// 最短路径拷贝

void CopyPath(stack * shortPath, stack * s)
{
	DataType tmp = 0;
	DataType i = 0;
	DataType size = StackSize(s);
	//StackPop(s);//pop掉最后一个出口
	if (size < shortPath->top || StackEmpty(shortPath))
	{
		for (i = 0; i < size; i++)
		{
			shortPath->po[i] = s->po[i];
			printf("[%d][%d]  ", shortPath->po[i].x, shortPath->po[i].y);
		}
		shortPath->top = size;
	}
}

//
//// 检测pCur是否在出口 
int IsExit(Maze* m, position cur, position entry)
{
	if ((0 != (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y))
	{
		printf("+++++++++++++++++++++++++   检测出口中    +++++++++++++++++++++++++\n");
	}
	return (0 != (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y);
}

//打印路径
void PathPrint(stack * path)
{
	int tmp = StackSize(path);
	int i = 0;
	for (i = 0; i < tmp; i++)
	{
		printf("[%d][%d] ", path->po[i].x, path->po[i].y);
	}
	printf("\n");
}

//思路：1.进来为普通迷宫一样，一步一步走。
//		2.但是不再只用2标记，采用当前步数+1的做法。
//		3.采用普通走法行不行？不行，因为采用下一步加一的判定方法，如果是循环的话，下一步就会一直大于当前步数
//真 -> 走迷宫的递归函数
int _PassMaze(Maze* m, position entry, position cur, stack* s, stack *shortPath)//Maze* m,迷宫   Position entry,入口   Position cur,当前位置    Stack* s 栈
{
	if (!(cur.x == entry.x && cur.y == entry.y) || StackEmpty(shortPath))//不在入口，最短路劲为空，说明为进来过
	{
		//上
		PrintMaze(m, m->m);
		position tmp = cur;
		tmp.x = tmp.x - 1;//用临时节点作为下一步的位置
		if (IsPass(m, cur, tmp))
		{
			m->m[tmp.x][tmp.y] = m->m[cur.x][cur.y] +1;//将下一步置为当前步的+1；
			//cur.x = cur.x - 1;//将当前位置置为下一步
			StackPush(s, &tmp);//存好
			PathPrint(s);//看栈内容
			_PassMaze(m, entry, tmp, s, shortPath);//从此进入递归
		}
		tmp = cur;
		tmp.y = tmp.y - 1;//左
		if (IsPass(m, cur, tmp))
		{
			m->m[tmp.x][tmp.y] = m->m[cur.x][cur.y]+1;
			//cur.y = cur.y - 1;//递归里，这里不应该赋值了，因为如果赋值，下一次回来就当前位置就成了下一次的位置！！！！教训啊，不要偷懒，瞎鸡儿拷自己的代码，还是慢慢写。
			StackPush(s, &tmp);
			PathPrint(s);//看栈内容
			_PassMaze(m, entry, tmp, s, shortPath);

		}
		tmp = cur;
		tmp.y = tmp.y + 1;//右
		if (IsPass(m, cur, tmp))
		{
			m->m[tmp.x][tmp.y] = m->m[cur.x][cur.y] +1;
			//cur.y = cur.y + 1;
			StackPush(s, &tmp);
			PathPrint(s);//看栈内容

			_PassMaze(m, entry, tmp, s, shortPath);
		}
		tmp = cur;
		tmp.x = tmp.x + 1;//下
		if (IsPass(m, cur,tmp))
		{
			m->m[tmp.x][tmp.y] = m->m[cur.x][cur.y] +1;
			//cur.x = cur.x + 1;
			StackPush(s, &tmp);
			PathPrint(s);//看栈内容

			_PassMaze(m, entry, tmp, s, shortPath);
		}
		//到这是路不通
		//
		//cur = StackTop(s);//取栈顶为当前元素，因为有可能上面的不走都没走，可能是pop的，所以赋值一下。赋值个屁，这是递归，又不是迭代
		if (IsExit(m, cur, entry))//出口判断,是出口，这儿也许要放在开始才对吧，是出口，路径比=比较拷贝，递归出口放这儿行不行？行，IsPass有边界判断的，那肯定会来到这儿
		{
			CopyPath(shortPath, s);
		}
		StackPop(s);
		printf("pop\n");
		PathPrint(s);//看栈内容

	}

	return 1;

}




//// 伪 ->走迷宫 
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
	stack shortPath;//存放最短路径的栈
	StackInit(&shortPath);//一定记得初始化，血与泪的教训
	position cur;//放当前位置
	cur.x = entry.x;//第一次进来当前位置和初始位置相同
	cur.y = entry.y;
	m->m[entry.x][entry.y] = 2;//把初始位置置为2
	StackPush(s, &cur);//入栈
	_PassMaze(m, entry, cur, s,&shortPath);//真正的走迷宫函数
	printf("++++++++++++ 最短路径已经找到+++++++++++++++++\n");
	PathPrint(&shortPath);

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







