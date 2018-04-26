#pragma warning(disable:4996)
# include "stack.h"
int  main()
{
	int arr[6][6] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0 },
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 0, 1, 0, 0, 0 } };
	//int arrstart = arr[5][2];
	entry.x = 5;
	entry.y = 2;
	//test();
	//PrintMaze(&m, arr);
	StackInit(&s);
	InitMaze(&m, arr);
	PassMaze(&m, entry, &s);
	PrintMaze(&m, m.m);
	free(s.po);

	return 0;
}
