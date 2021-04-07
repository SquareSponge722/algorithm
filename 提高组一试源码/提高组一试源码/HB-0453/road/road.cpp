#include <cstdio>
const int maxn = 100000 + 10;
int n, a[maxn], ans, tmp;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out","w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > a[i - 1])
			ans += a[i] - a[i - 1];
	}
	printf("%d", ans);
	return 0;
}
