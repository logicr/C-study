#pragma warning(disable:4996)
//把一个数组的奇数放到前面，偶数放到后面
//我的思路：上次做了一个拿瓶子换汽水的题，思维能力有所提升。学会简化问题的能力，这种方式很重要
//当看到问题时，要把奇数放到前面部分，又要把偶数放到后面部分，感觉很复杂，要处理两部分
//实际上，简化一下问题，数组中除了奇数就是偶数，那么，把所有奇数放到前面，偶数自然就在后面了

# include <stdio.h>
int find_odd(int * arr,int len)
{
	int i = 0;
	int cou = 0;
	while (i < len)
	{
		if (1 == *(arr + i) % 2)
		{
			int tmp = *(arr + i);
			*(arr + i) = *(arr + cou);
			*(arr + cou) = tmp;
			cou++;
		}
		i++;
	}

}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 4, 9, 8, 2, 135, 66 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	find_odd(arr,sz);
	return 0;
}
