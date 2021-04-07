#include <stdio.h>

int road[100050];
int ans;

int find_min(int start, int end)
{
	int tmp_min = 999999, i, rst = 0;
	
	for (i = start; i <= end; i++)
	{
		if (road[i] < tmp_min)
		{
			tmp_min = road[i];
			rst = i;
		}
	}
	
	return rst;
}

void update(int start, int end, int k)
{
	int i;
	
	for (i = start; i <= end; i++)
	{
		road[i] -= k;
	}
}

void work(int start, int end, int min_index)
{
	if (start > end)
	{
		return;
	}
	
	ans += road[min_index];
	update(start, end, road[min_index]);
	
	work(start, min_index - 1, find_min(start, min_index - 1));
	work(min_index + 1, end, find_min(min_index + 1, end));
}

int main(void)
{
	int n, i, min_index = 999999, min = 999999;
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &road[i]);
		
		if (road[i] < min)
		{
			min = road[i];
			min_index = i;
		}
	}
	
	work(0, n - 1, min_index);
	
	printf("%d", ans);
	
	return 0;
}
