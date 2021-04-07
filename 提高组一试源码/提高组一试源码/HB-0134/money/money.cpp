#include <stdio.h>

int a[20][105], n;

bool is_find(int crt, int num)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		if ((num % a[crt][i]) == 0)
		{
			return 1;
		}
	}
	
	return 0;
}

int judge(int crt, int num)
{
	int rst = 0;
	int i;
	
	for (i = 1; i <= num / 2; i++)
	{
		if (is_find(crt, i) && is_find(crt, num - i))
		{
			rst = 1;
			break;
		}
	}
	
	return rst;
}

int work(int crt)
{
	int i, j;
	int rst = n;
	
	if (n > 1)
	{
		for (i = 0; i < n; i++)
		{
			rst -= judge(crt, a[crt][i]);
		}
	}
	
	return rst;
}

int main(void)
{
	int t, i, j;
	
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	
	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
	{		
		scanf("%d", &n);
		
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
		
		printf("%d\n", work(i));
		n = 0;
	}
	
	return 0;
}
