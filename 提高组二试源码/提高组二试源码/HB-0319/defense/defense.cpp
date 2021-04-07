#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int n, m, cnt;
int cost[N], ans[2];
char type[5];

struct node
{
	int to, nt;
}E[N * 2];
int num, p[N];

void add(int x, int y)
{
	E[++num].to = y; E[num].nt = p[x]; p[x] = num;
}

bool f[N]; int flag[N];
void dfs(int x, int mark)
{
	if(mark) cnt += cost[x];
	f[x] = true; flag[x] = mark;
	for(int e = p[x]; e; e = E[e].nt)
	{
		int t = E[e].to;
		if(!f[t]) dfs(t, 1 - mark);
	}
}

int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	
	n = read(); m = read(); scanf("%s", type);
	for(int i = 1; i <= n; i++) {cost[i] = read(); ans[1] += cost[i];}
	for(int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs(1, 0);
	ans[0] = cnt; ans[1] -= cnt;
	for(int i = 1; i <= m; i++)
	{
		int a = read(), x = read(), b = read(), y = read();
		if(x == y && flag[a] == flag[b])
		{
			if(flag[a] == x) cout << ans[0] << endl;
			else cout << ans[1] << endl;
		}
		else if(x != y && flag[a] != flag[b])
		{
			if(flag[a] == x) cout << ans[0] << endl;
			else cout << ans[1] << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}
