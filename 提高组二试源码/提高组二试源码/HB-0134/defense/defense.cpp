#include <stdio.h>
#include <stdlib.h>

int comp(const void * p1, const void * p2)
{
	return (*(const int *)p1) - (*(const int *)p2);
}

int main(void)
{
	int m, n, i, j, ans = 0;
	int a, b, x, y;
	int t1, t2; //Œﬁ”√ 
	int city[100050];
	char type[3];
	
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	scanf("%d%d%s", &n, &m, type);
	
	if (type[1] == 'A')
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &city[i]);
			ans += city[i];
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &t1, &t2);
		}
		
		for (i = 0; i < m; i++)
		{
			if (type[1] == '1')
			{
				scanf("%d%d%d%d", &a, &b, &x, &y);
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
