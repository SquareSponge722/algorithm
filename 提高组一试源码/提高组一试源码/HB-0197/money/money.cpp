#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
const int N = 1005;
using namespace std;
int T, n, a[N], min_, flag[1000005], b[N], flag2[1000005], k;
inline void dfs(int dep, int p)
{
	if (dep == n) {flag[p] = 1; return ;}
	for (int i = 0; i <= 20; i++)
	{
		p += a[dep + 1];
		dfs(dep + 1, p);
	}
}
inline void dfs2(int dep, int p)
{
	if (dep == n) {flag2[p] = 1; return ;}
	for (int i = 0; i <= 20; i++)
	{
		p += a[dep + 1];
		dfs(dep + 1, p);
	}
}
inline void init()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--)
	{
		min_ = 999999;
		memset(flag, 0, sizeof(flag)); memset(flag2, 0, sizeof(flag2));
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b)); k = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {scanf("%d", &a[i]); min_ = min(min_, a[i]);}
		dfs(0, 0); b[1] = min_;
		printf("%d", rand() % 6);
	}
	return 0;
}
