#pragma warning(disable:4996)
# include <stdio.h>
int cmp_int(const void *x, const void *y)//比较
{
	int * a = (int *)x;
	int * b = (int *)y;
	return *a > *b ? 1 : *a < *b ? -1 : 0;
}
void swap(void *x, void *y, int sz)//按字节交换
{
	char * a = (char *)x;
	char * b = (char *)y;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		char tmp = *(a + i);
		*(a + i) =*(b + i );
		*(b + i) = tmp;
	}
}
void myqsort(void * base,int num,int size,int (*cmp)(void *,void *y))
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char *)base + j*size , (char *)base + (j+1)*size ) >0)
			{
				swap((char *)base + j*size, (char *)base + (j + 1)*size,size);
			}
		}
	}

}
int main()
{
	int arr[] = { 4, 8, 54, 9, 4, 6, 48, 7, 4, 548, 84, 848, 848, 58, 484, 8, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr, sz, sizeof(int), cmp_int);
	myqsort(arr, sz, sizeof(int), cmp_int);
	return 0;
}
