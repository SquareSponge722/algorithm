#include <stdio.h>

int main(void)
{
	int n, m, i;
	int a, b, c, ans = 0;
	
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		ans += c;
	}
	
	printf("%d", ans);
	
	return 0;
}
