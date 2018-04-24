#pragma warning(disable:4996)
# include "stack.h"


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
//
//// ���pCur�Ƿ��ڳ��� 
int IsExit(Maze* m, position cur, position entry)
{
	if ((1 == (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y))
	{
		printf("+++++++++++++++++++++++++   1    +++++++++++++++++++++++++\n");
	}
	return (1 == (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y);
}
//
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
	position cur;
	cur.x = entry.x;
	cur.y = entry.y;
	m->m[entry.x][entry.y] = 2;
	StackPush(s, &cur);
	while (!IsExit(m, StackTop(s), entry))
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
