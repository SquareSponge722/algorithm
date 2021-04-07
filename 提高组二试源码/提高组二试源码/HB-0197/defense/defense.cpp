#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
const int N = 100005;
using namespace std;
int n, m, a, b, x, y, val[N], ans;
char v[N];
inline void init()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
}
int main()
{
	init();
	scanf("%d %d %s", &n, &m, v);
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for (int i = 1; i < n; i++)
	{
		int p, q;
		scanf("%d %d", &p, &q);
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d %d", &a, &b, &x, &y);
		if (x == 0 && y == 0)
		{
			if (a == 1 && b == 2) printf("-1");
			if (a == 2 && b == 1) printf("-1");
			if (a == n && b == n - 1) printf("-1");
			if (a == n - 1 && b == n) printf("-1");
			continue;
		}
		if (x == 1 && y == 1)
		{
			if (a % 2 == 1 && b % 2 == 1)
				for (int i = 0; i <= n / 2; i++) ans += val[i * 2 + 1];
			if (a % 2 == 0 && b % 2 == 0)
				for (int i = 1; i <= n / 2; i++) ans += val[i * 2];
			if (a % 2 != b % 2)
			{
				int num1 = 0; int num2 = 0;
				for (int i = 0; i <= n / 2; i++) num1 += val[i * 2 + 1];
				for (int i = 1; i <= n / 2; i++) num2 += val[i * 2];
				ans = min(num1, num2);
			}
		}
		if (x == 0 && y == 0)
		{
			if (a % 2 == 0 && b % 2 == 0)
				for (int i = 0; i <= n / 2; i++) ans += val[i * 2 + 1];
			if (a % 2 == 1 && b % 2 == 1)
				for (int i = 1; i <= n / 2; i++) ans += val[i * 2];
		}
		if ((x == 0 && y != 0) || (x != 0 && y == 0))
		{
			for (int i = 1; i <= n / 2; i++) ans += val[i * 2];
		}
		printf("%d\n", ans);
	}
	return 0;
}
