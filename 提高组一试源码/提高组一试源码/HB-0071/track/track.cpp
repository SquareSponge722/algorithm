#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#define NO 50005
#define INF 0x3f3f3f3f
#define p pair<int, int>
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
typedef long long ll;
typedef double db;
//by Oliver
using namespace std;
ll read()
{
	char ch = ' ', last;
	ll ans = 0;
	while(ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while(ch >= '0' && ch <= '9')
		ans *= 10, ans += ch - '0', ch = getchar();
	if(ch == '-')
		return -ans;
	return ans;
}
//head

int n, m, cnt, head[NO], ans, out[NO], sum, Cos[NO];
bool f1, f2;
struct node
{
	int next, to, cost;
}edge[2 * NO];
//variable

void add(int from, int to, int cost)
{
	edge[++cnt].next = head[from];
	edge[cnt].to = to;
	edge[cnt].cost = cost;
	head[from] = cnt;
}
void init()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	n = read(), m = read();
	f1 = true, f2 = true;
	for(int i = 1; i < n; i++)
	{
		int x = read(), y = read(), z = read();
		add(x, y, z);
		add(y, x, z);
		out[x]++, out[y]++;
		if(y != x + 1)
			f1 = false;
		if(x != 1)
			f2 = false;
		sum += z;
		Cos[i] = z;
	}
}
int dfs(int now, int father)
{
	if(out[now] == 1)
		return 0;
	else
	{
		int MAX = 0, seMAX = 0;
		for(int i = head[now]; i; i = edge[i].next)
		{
			int next = edge[i].to;
			if(next == father)
				continue;
			int M = dfs(next, now) + edge[i].cost;
			if(M > MAX)
				seMAX = MAX, MAX = M;
		}
		ans = max(ans, MAX + seMAX);
		return MAX;
	}
}
//functions

int main()
{
	init();
	if(m == 1)
	{
		dfs(1, 0);
		printf("%d\n", ans);
	}
	else if(f1)
	{
		db aver = db(sum) / m;
		int now = 0, anss = INF, cnt1 = 0;
		for(int i = 1; i < n && cnt1 <= m; i++)
		{
			if(now + Cos[i] > aver)
				anss = min(anss, now), now = 0, cnt1++;
			now += Cos[i];
		}
		if(cnt1 < m)
			ans = min(ans, now);
		anss = min(anss, now);
		printf("%d\n", anss);
	}
	else if(f2)
	{
		if(m > (n - 1) / 2)
		{
			sort(Cos + 1, Cos + n);
			printf("%d", Cos[n - m]);
		}
		else
		{
			sort(Cos + 1, Cos + n);
			printf("%d", Cos[n - m] + Cos[m]);
		}
	}
	else
	{
		for(int i = 1; i <= n / m; i++)
		{
			int now = rand() % (n - 1) + 1;
			ans += Cos[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
//main
