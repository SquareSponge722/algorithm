#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#define NO 11005
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
	if(last == '-')
		return -ans;
	return ans;
}
//head

int n, m, cnt, head[NO], in[NO], ans[NO], cnt1, st;
bool book[NO], f1;
struct node
{
	int next, to;
}edge[NO];
//variable

void add(int from, int to)
{
	edge[++cnt].next = head[from];
	edge[cnt].to = to;
	head[from] = cnt;
}
void init()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read(), m = read();
	f1 = true, st = INF;
	for(int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		add(x, y), add(y, x);
		in[x]++, in[y]++;
		if(in[x] >= 3 || in[y] >= 3)
			f1 = false;
		if(x > y)
			swap(x, y);
		if(x == 1)
			st = min(st, y);
	}
}
void dfs(int now)
{
	if(book[now])
		return;
	book[now] = true;
	ans[++cnt1] = now;
	int tot;
	int Max = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = head[now]; i; i = edge[i].next)
		if(!book[edge[i].to])
			q.push(edge[i].to);
	while(!q.empty())
		dfs(q.top()), q.pop();
}
void dfs2(int now, int last)
{
	if(now == 1)
		return;
	ans[++cnt1] = now;
	for(int i = head[now]; i; i = edge[i].next)
		if(edge[i].to != last)
			dfs2(edge[i].to, now);
}
//functions

int main()
{
	init();
	if(f1)
	{
		ans[++cnt1] = 1;
		dfs2(st, 1);
		for(int i = 1; i <= cnt1; i++)
			printf("%d ", ans[i]);
		putchar('\n');
		return 0;
	}
	dfs(1);
	for(int i = 1; i <= cnt1; i++)
		printf("%d ", ans[i]);
	putchar('\n');
	return 0;
}
//main                 
