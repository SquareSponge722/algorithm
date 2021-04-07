#include <cstdio>
const int maxn = 100 + 10;
int T, n, ar[maxn];
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &ar[i]);
		if(n == 2)
		{
			int a = ar[1], b = ar[2];
			puts((a % b == 0 || b % a == 0) ? "1" : "2");
			return 0;
		}
		else
		{
			int ans = n;
			for(int i = 1; i <= n; i++)
				for(int j = i + 1; j <= n; j++)
				{
					if(ar[i] % ar[j] == 0 || ar[j] % ar[i] == 0)
						ans-=1;
				}
			printf("%d\n", ans);
		}
	}
	return 0;
}
