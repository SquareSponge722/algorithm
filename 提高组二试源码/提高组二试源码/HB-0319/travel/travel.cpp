#include <bits/stdc++.h>
using namespace std;
const int N = 5005;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int n, m, to[N][N];

bool f[N];
void dfs(int x)
{
	printf("%d ", x); f[x] = true;
	for(int i = 1; i <= to[x][0]; i++)
	{
		int t = to[x][i];
		if(!f[t]) dfs(t);
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	n = read(); m = read();
	for(int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		to[x][++to[x][0]] = y; to[y][++to[y][0]] = x;
	}
	for(int i = 1; i <= n; i++) sort(to[i] + 1, to[i] + 1 + to[i][0]);
	dfs(1);
	return 0;
}
