#include <stdio.h>
#include <stdlib.h>

typedef struct City
{
	int conn[105];
	int min;
	int last_index;
} city;

city map[105] = {0};
bool is_visit[105];
int n;

int comp(const void * c1, const void * c2)
{
	return (*(const int *)c1) - (*(const int *)c2);
}

int find_min_index(int index)
{
	int i = 0;
	
	while(is_visit[map[index].conn[i++]] != 0);
	
	return i - 1;
}

bool is_over(void)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (!is_visit[i])
		{
			return 0;
		}
	}
	
	return 1;
}

void work(int index, int min_index, int next_min_index)
{
	if (is_over())
	{
		return;
	}
	
	int i = find_min_index;
	
	while (is_visit[map[index].conn[i++]]);
	
	if (map[map[index].conn[i - 1]] > map[index].conn[min_index]);
	
}

int main(void)
{
	int m;
	int i, j, t1, t2;
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
		
	scanf("%d%d", &n, &m);
	
	if (n <= 1000)
	{
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &t1, &t2);
			map[t1].conn[map[t1].last_index++] = t2;			
			map[t2].conn[map[t2].last_index++] = t1;
		}
		
		for (i = 0; i < m; i++)
		{
			map[i].conn[map[i].last_index++] = 9999999;
		}
		
		for (i = 0; i < m; i++)
		{
			qsort(map[i].conn, map[i].last_index, sizeof(int), comp);
		}
		
		printf("1 ");
		is_visit[1] = 1;
	}
	
	return 0;
}
