#pragma warning(disable:4996)
# include "stack.h"




//2. �õݹ鷽ʽʵ�ּ��Թ�����ֻ��һ�������Թ�
//void InitMaze(Maze* m, int map[][MAX_COL]);
//int IsValidEntry(Maze* m, Position entry);
//int IsPass(Maze* m, Position cur);
//int IsExit(Maze* m, Position cur, Position entry);
//
//// �������Թ����� 
//int _PassMaze(Maze* m, Position entry, Position cur, Stack* s);//Maze* m,�Թ�   Position entry,���   Position cur,��ǰλ��    Stack* s ջ
//
//// �ṩ���û�ʹ�õ����Թ������������ϸ����Թ������������ǣ��û�����ȥ����ǰ����ֻ��Ҫ����ھ��� 
//void PassMaze(Maze* m, Position entry, Stack* s);
//void PrintMaze(Maze* m, int map[][MAX_COL]);
//
//3. ����Թ��ж���·�ڣ�����·��û�й��ɻ�����ô�����·��
//4�� ������·�ڹ��ɻ�����������·��-- - ����ڵ����Լ��ȳ���ȥд
//5������ȥ�˽���A*Ѱ·�㷨


//+++++++++++++++++++++++++++++++++++++++++


//3. ����Թ��ж���·�ڣ�����·��û�й��ɻ�����ô�����·��
//˼·��1.��ͨ���߷�һ�����ҵ�һ��·��
//		2.�ߵ�����ʱ���ж��ǳ����ˣ�����
//		3.����һ��·�����浽���·��
//		4.���ˣ���������һ��·��
//		5.�ҵ���һ��·����������ʱ���ٴλ���
//		6.�ظ�
//		7.һֱ���ˣ�ֱ�����˵�����ʱ
//		8.���ػ��ߴ�ӡ���·����

//+++++++++++++++++++++++++++++++++++++

//1. ��ջ�Ѽ��Թ�������⣬�Թ�ֻ��һ������
//����ѭ����ʽʵ��
//// ջ�ĳ�ʼ�� 
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
//// �������Ƿ�Ϊ��Ч��� 
int IsValidEntry(Maze* m, position entry)//3
{
	return (1 == (m->m[entry.x][entry.y])) && ((0 == entry.x || L - 1 == entry.x) || (0 == entry.y || R - 1 == entry.y) && 0 <= entry.x && entry.x <= R) && (0 <= entry.y &&  entry.y <= L);

}
//
//// ���curλ���Ƿ���ͨ· 
int IsPass(Maze* m, position cur)
{
	return ((0 <= cur.x && cur.x <= R - 1) && (0 <= cur.y &&  cur.y <= L - 1) && (1 == (m->m[cur.x][cur.y])));
}
// ���·������

void CopyPath(stack * shortPath, stack * s)
{
	DataType tmp = 0;
	DataType i = 0;
	DataType size = StackSize(s);
	//StackPop(s);//pop�����һ������
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
//// ���pCur�Ƿ��ڳ��� 
int IsExit(Maze* m, position cur, position entry)
{
	if ((1 == (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y))
	{
		printf("+++++++++++++++++++++++++   ��������    +++++++++++++++++++++++++\n");
	}
	return (1 == (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y);
}

//��ӡ·��
void PathPrint(stack * path)
{
	int tmp = StackSize(path);
	int i = 0;
	for (i = 0; i < tmp; i++)
	{
		printf("[%d][%d] ", path->po[i].x, path->po[i].y);
	}
}

int _PassMaze(Maze* m, position entry, position cur, stack* s, stack *shortPath)//Maze* m,�Թ�   Position entry,���   Position cur,��ǰλ��    Stack* s ջ
{
	/*if (!StackEmpty(shortPath))
	{
		CopyPath(shortPath, s);
	}*/

	//while (!IsExit(m, StackTop(s), entry))
	while( !(cur.x == entry.x && cur.y == entry.y) || StackEmpty (shortPath))
	{
		//��
		//PrintMaze(m, m->m);
		position tmp = cur;
		tmp.x = tmp.x - 1;
		if (IsPass(m, tmp))
		{
			cur.x = cur.x - 1;
			m->m[cur.x][cur.y] = 2;
			StackPush(s, &cur);
			//_PassMaze(m, entry, cur, s, shortPath);//�Ӵ˽���ݹ�

			continue;
		}
		tmp = cur;
		tmp.y = tmp.y - 1;//��
		if (IsPass(m, tmp))
		{
			cur.y = cur.y - 1;
			m->m[cur.x][cur.y] = 2;
			StackPush(s, &cur);
			//_PassMaze(m, entry, cur, s, shortPath);

			continue;
		}
		tmp = cur;
		tmp.y = tmp.y + 1;//��
		if (IsPass(m, tmp))
		{
			cur.y = cur.y + 1;
			m->m[cur.x][cur.y] = 2;
			StackPush(s, &cur);
			//_PassMaze(m, entry, cur, s, shortPath);
			continue;
		}
		tmp = cur;
		tmp.x = tmp.x + 1;//��
		if (IsPass(m, tmp))
		{
			cur.x = cur.x + 1;
			m->m[cur.x][cur.y] = 2;
			StackPush(s, &cur);
			//_PassMaze(m, entry, cur, s, shortPath);
			continue;
		}
		//������·��ͨ
		//
		cur = StackTop(s);
		if (IsExit(m, cur, entry))
		{
			CopyPath(shortPath, s);
		}
		m->m[cur.x][cur.y] = 3;
		StackPop(s);
		/*if ((cur.x == entry.x && cur.y == entry.y))
		{
			return 1;
		}*/
	}

	return 1;

}




//// ���Թ� 
void PassMaze(Maze* m, position entry, stack* s)//1
{
	//1.��ڼ�Ϸ��Բ�
	//���������ߣ������һ���Ƿ�ͨ·
	//����߹��ĵ���Ϊ2����ջ
	//3.·��ͨ������
	if (!IsValidEntry(m, entry))
	{
		return;
	}
	stack shortPath;
	StackInit(&shortPath);
	position cur;
	cur.x = entry.x;
	cur.y = entry.y;
	m->m[entry.x][entry.y] = 2;
	StackPush(s, &cur);
	_PassMaze(m, entry, cur, s,&shortPath);
	PathPrint(&shortPath);
	//	while (!IsExit(m, StackTop(s), entry))
	//	{
	//		//��
	//		//PrintMaze(m, m->m);
	//		position tmp = cur;
	//		tmp.x = tmp.x - 1;
	//		if (IsPass(m, tmp))
	//		{
	//			cur.x = cur.x - 1;
	//			m->m[cur.x][cur.y] = 2;
	//			StackPush(s, &cur);
	//			continue;
	//		}
	//		tmp = cur;
	//		tmp.y = tmp.y - 1;
	//		if (IsPass(m, tmp))
	//		{
	//			cur.y = cur.y - 1;
	//			m->m[cur.x][cur.y] = 2;
	//			StackPush(s, &cur);
	//			continue;
	//		}
	//		tmp = cur;
	//		tmp.y = tmp.y + 1;
	//		if (IsPass(m, tmp))
	//		{
	//			cur.y = cur.y + 1;
	//			m->m[cur.x][cur.y] = 2;
	//			StackPush(s, &cur);
	//			continue;
	//		}
	//		tmp = cur;
	//		tmp.x = tmp.x + 1;
	//		if (IsPass(m, tmp))
	//		{
	//			cur.x = cur.x + 1;
	//			m->m[cur.x][cur.y] = 2;
	//			StackPush(s, &cur);
	//			continue;
	//		}
	//		cur = StackTop(s);
	//		m->m[cur.x][cur.y] = 3;
	//		StackPop(s);
	//	}
	//	return;
	//
	//}
}
	//
	//// ��ӡ�Թ� 
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







