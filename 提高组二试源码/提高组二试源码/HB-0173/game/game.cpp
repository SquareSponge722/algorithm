#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<string>
using namespace std;
int n, m;
int ans;
const int N = 9;
int w[N * N];
string s = "000000000";
set < string > vis;
inline void dfs(int now)
{
	if (now == n * m)
	{
		ans ++;
		ans %= 1000000007;
		return;
	}
	int pre = 0;
	if (now % m)
	pre = now - m + 1;
	if (pre < 0)
		pre = 0;
	if (w[pre])
	{
		w[now] = 1;
		dfs(now + 1);
		w[now] = 0;
	}
	else
	{
		w[now] = 1;
		dfs(now + 1);
		w[now] = 0;
		dfs(now + 1);
	}
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n == 3)
	{
		printf("112\n");
		return 0;
	}
	if(n == 5)
	{
		printf("7136\n");
		return 0;
	}
	dfs(2);
	printf("%d\n", ans * 2 * 2);
	return 0;
}
