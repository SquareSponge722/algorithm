#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int inf = 1e9;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

struct node
{
	int to, nt, w;
}E[N];
int num, p[N];

int n, m, l[N], d[N];

void add(int x, int y, int v)
{
	E[++num].to = y; E[num].w = v;
	E[num].nt = p[x]; p[x] = num;
}

int dis[N]; bool f[N];
int bfs(int s)
{
	queue<int> q; q.push(s);
	memset(dis, 0, sizeof(dis));
	memset(f, 0, sizeof(f)); f[s] = 1;
	while(!q.empty())
	{
		int k = q.front(); q.pop();
		for(int e = p[k]; e; e = E[e].nt)
		{
			int t = E[e].to;
			if(!f[t])
			{
				dis[t] = dis[k] + E[e].w;
				q.push(t); f[t] = true;
			}
		}
	}
	int end = 0;
	for(int i = 1; i <= n; i++) if(dis[i] > dis[end]) end = i;
	return end;
}

bool check(int mid)
{
	int cnt = 0, sum = 0;
	for(int i = 1; i < n; i++)
	{
		sum += d[i];
		if(sum >= mid){cnt++; sum = 0;}
	}
	return cnt >= m;
}

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	
	n = read(); m = read(); bool ai = true, loop = true;
	for(int i = 1; i < n; i++)
	{
		int x = read(), y = read(); l[i] = read();
		add(x, y, l[i]); add(y, x, l[i]);
		if(x != 1 && y != 1) ai = false;
		if(abs(x - y) != 1) loop = false;
	}
	if(m == 1)//树的直径 
	{
		int s = bfs(1);
		int t = bfs(s);
		cout << dis[t];
	}
	else if(ai)//道路长度不大于2 
	{
		sort(l + 1, l + n);
		int ans = inf;
		while(m * 2 > n - 1)
		{
			ans = min(ans, l[n - 1]);
			n--; m--;
		}
		for(int i = 1; i <= m; i++) ans = min(ans, l[n - i] + l[n - 2 * m + i - 1]);
		cout << ans;
	}
	else if(loop)
	{
		for(int i = 1; i < n; i++)
			for(int e = p[i]; e; e = E[e].nt)
				if(E[e].to == i + 1) d[i] = E[e].w;
		int L = inf, R = 0, ans = 0;
		for(int i = 1; i < n; i++)
		{
			L = min(L, l[i]);
			R += l[i];
		}
		while(L <= R)
		{
			int mid = (L + R) >> 1;
			if(check(mid)) {ans = mid; L = mid + 1;}
			else R = mid - 1;
		}
		cout << ans;
	}
	else
	{
		
	}
	return 0;
}
