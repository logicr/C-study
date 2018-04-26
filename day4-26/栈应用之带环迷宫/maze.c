#pragma warning(disable:4996)
# include "stack.h"
//4�� ������·�ڹ��ɻ�����������·��-- - ����ڵ����Լ��ȳ���ȥд
//5������ȥ�˽���A*Ѱ·�㷨


//+++++++++++++++++++++++++++++++++++++++++



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
int IsPass(Maze* m, position cur ,position tmp)//	if (IsPass(m, cur, tmp))
{
	printf("+++++++++�ж�+++++++++++\n��ǰ��:[%d][%d]		", cur.x, cur.y);
	printf("��һ��:[%d][%d]  \n", tmp.x, tmp.y);
	return ((0 <= tmp.x && tmp.x <= R - 1) && (0 <= tmp.y &&  tmp.y <= L - 1) && ((1 == (m->m[tmp.x][tmp.y])) || (m->m[cur.x][cur.y]) < (m->m[tmp.x][tmp.y])));
	//���ڱ߽磬Ϊ1��ȵ�ǰ��
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
	if ((0 != (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y))
	{
		printf("+++++++++++++++++++++++++   ��������    +++++++++++++++++++++++++\n");
	}
	return (0 != (m->m[cur.x][cur.y])) && (cur.x != entry.x && cur.y != entry.y) && (0 == cur.x || L - 1 == cur.x) || (0 == cur.y || R - 1 == cur.y);
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
	printf("\n");
}

//˼·��1.����Ϊ��ͨ�Թ�һ����һ��һ���ߡ�
//		2.���ǲ���ֻ��2��ǣ����õ�ǰ����+1��������
//		3.������ͨ�߷��в��У����У���Ϊ������һ����һ���ж������������ѭ���Ļ�����һ���ͻ�һֱ���ڵ�ǰ����
//�� -> ���Թ��ĵݹ麯��
int _PassMaze(Maze* m, position entry, position cur, stack* s, stack *shortPath)//Maze* m,�Թ�   Position entry,���   Position cur,��ǰλ��    Stack* s ջ
{
	if (!(cur.x == entry.x && cur.y == entry.y) || StackEmpty(shortPath))//������ڣ����·��Ϊ�գ�˵��Ϊ������
	{
		//��
		PrintMaze(m, m->m);
		position tmp = cur;
		tmp.x = tmp.x - 1;//����ʱ�ڵ���Ϊ��һ����λ��
		if (IsPass(m, cur, tmp))
		{
			m->m[tmp.x][tmp.y] = m->m[cur.x][cur.y] +1;//����һ����Ϊ��ǰ����+1��
			//cur.x = cur.x - 1;//����ǰλ����Ϊ��һ��
			StackPush(s, &tmp);//���
			PathPrint(s);//��ջ����
			_PassMaze(m, entry, tmp, s, shortPath);//�Ӵ˽���ݹ�
		}
		tmp = cur;
		tmp.y = tmp.y - 1;//��
		if (IsPass(m, cur, tmp))
		{
			m->m[tmp.x][tmp.y] = m->m[cur.x][cur.y]+1;
			//cur.y = cur.y - 1;//�ݹ�����ﲻӦ�ø�ֵ�ˣ���Ϊ�����ֵ����һ�λ����͵�ǰλ�þͳ�����һ�ε�λ�ã���������ѵ������Ҫ͵����Ϲ�������Լ��Ĵ��룬��������д��
			StackPush(s, &tmp);
			PathPrint(s);//��ջ����
			_PassMaze(m, entry, tmp, s, shortPath);

		}
		tmp = cur;
		tmp.y = tmp.y + 1;//��
		if (IsPass(m, cur, tmp))
		{
			m->m[tmp.x][tmp.y] = m->m[cur.x][cur.y] +1;
			//cur.y = cur.y + 1;
			StackPush(s, &tmp);
			PathPrint(s);//��ջ����

			_PassMaze(m, entry, tmp, s, shortPath);
		}
		tmp = cur;
		tmp.x = tmp.x + 1;//��
		if (IsPass(m, cur,tmp))
		{
			m->m[tmp.x][tmp.y] = m->m[cur.x][cur.y] +1;
			//cur.x = cur.x + 1;
			StackPush(s, &tmp);
			PathPrint(s);//��ջ����

			_PassMaze(m, entry, tmp, s, shortPath);
		}
		//������·��ͨ
		//
		//cur = StackTop(s);//ȡջ��Ϊ��ǰԪ�أ���Ϊ�п�������Ĳ��߶�û�ߣ�������pop�ģ����Ը�ֵһ�¡���ֵ��ƨ�����ǵݹ飬�ֲ��ǵ���
		if (IsExit(m, cur, entry))//�����ж�,�ǳ��ڣ����Ҳ��Ҫ���ڿ�ʼ�Ŷ԰ɣ��ǳ��ڣ�·����=�ȽϿ������ݹ���ڷ�����в��У��У�IsPass�б߽��жϵģ��ǿ϶����������
		{
			CopyPath(shortPath, s);
		}
		StackPop(s);
		printf("pop\n");
		PathPrint(s);//��ջ����

	}

	return 1;

}




//// α ->���Թ� 
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
	stack shortPath;//������·����ջ
	StackInit(&shortPath);//һ���ǵó�ʼ����Ѫ����Ľ�ѵ
	position cur;//�ŵ�ǰλ��
	cur.x = entry.x;//��һ�ν�����ǰλ�úͳ�ʼλ����ͬ
	cur.y = entry.y;
	m->m[entry.x][entry.y] = 2;//�ѳ�ʼλ����Ϊ2
	StackPush(s, &cur);//��ջ
	_PassMaze(m, entry, cur, s,&shortPath);//���������Թ�����
	printf("++++++++++++ ���·���Ѿ��ҵ�+++++++++++++++++\n");
	PathPrint(&shortPath);

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







