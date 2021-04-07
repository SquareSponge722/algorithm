#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <stack>
#define N 51000
using namespace std;

struct E {int to, next, w;} e[N<<1];
int n, m, head[N], esum, rr[N];
int ans;

void add(int u, int v, int w)
{
	e[++esum] = (E){v, head[u], w}; head[u] = esum;
}

void read(int &x)
{
	int h = 1; x = 0; char s = getchar();
	while (s<'0' || s>'9') {if(s == '-') h = -1; s = getchar();}
	while (s>='0' && s<='9') {x = x*10 + s - '0'; s = getchar();}
	x *= h; return; 
}

void dfs(int fa, int x, int tot)
{
	for (int i=head[x]; i; i=e[i].next)
	{
		if(e[i].to != fa)
		{
			dfs(x, e[i].to, tot+e[i].w);
		}
	}
	ans = max(ans , tot);
}

int main()
{
	//ios::sync_with_stdio(0);
    freopen("track.in", "r", stdin);
    freopen("track.out", "w", stdout);
    read(n); read(m);
	bool flag = 0;
    for (int i=1; i<=n-1; i++)
    {
    	int u, v, w; 
    	read(u); read(v); read(w);
    	if(u != 1) flag = 1;
    	rr[u] ++; rr[v] ++;
		add(u, v, w); add(v, u, w);
	}
/*	if(flag == 0)
	{
		priority_queue <int> q;
		//int b[m + 10];
		for (int i=1; i<=m; i++) q.push(0); 
		for (int i=head[1]; i; i=e[i].next)
		{
			int k = q.top();
			q.pop();
			k += e[i].w;
			q.push(k); 
		}
		printf("%d", q.top());
	}*/
	if(m == 1)
	{
		for (int i=1; i<=n; i++)
		{
			if(rr[i] == 1)dfs(0, i, 0);
			//cout<<ans;
		}printf("%d", ans);
	}
    return 0;
}




































