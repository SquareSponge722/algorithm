#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 100005;
typedef long long ll;
int n;
ll w[N];
inline ll dfs(int fr, int to)
{
	if (fr == to)
		return w[fr];
	if (fr > to)
		return 0;
	ll minn = w[fr];
	int pos = fr;
	for (int i = fr + 1; i <= to; i ++)
	{
		if (w[i] < minn)
		{
			minn = w[i];
			pos = i;
		}
	}	 
	for (int i = fr; i <= to; i ++)
		w[i] -= minn;
	return minn + dfs(fr, pos - 1) + dfs(pos + 1, to);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", &w[i]);
	printf("%lld\n", dfs(1, n));
	return 0;
}
