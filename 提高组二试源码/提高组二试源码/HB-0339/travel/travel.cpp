#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#define N 5400
using namespace std;

int n, m, esum, tot, ans[N], head[N], son[5004][5001], cd[N];
struct E {int to, next;} e[N<<1];

void Add(int u, int v) {e[++esum] = (E){v, head[u]}; head[u] = esum;}

void read(int &a)
{
	int f = 1; a = 0; char s = getchar();
	while (s<'0' || s>'9') {if(s == '-') f = -1; s = getchar();}
	while (s>='0' && s<='9') {a = a*10 + s - '0'; s = getchar();}
	a *= f;
}

void dfs1(int x, int dad)
{
	//int j = 0;
	//for (int i=head[x]; i; i=e[i].next)
	//{
	//	so[++j] = e[i].to;
	//}
	//sort(so+1, so+j+1, cmp);
	ans[++tot] = x;
	for (int i=1; i<=cd[x]; i++)
	{
		if(son[x][i] != dad) dfs1(son[x][i], x);
	}
}

bool cmp(int a, int b) {return a < b;}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	read(n); read(m);
	for (int i=1; i<=m; i++)
	{
		int u, v; read(u); read(v);
		Add(u, v); Add(v, u);
		cd[u] ++; cd[v] ++;
		son[u][cd[u]] = v; son[v][cd[v]] = u;
	}
	for (int i=1; i<=n; i++)
	{
		sort(son[i]+1, son[i] + cd[i] + 1, cmp);
	}
	if(m == n - 1) 
	{
		dfs1(1, 0);
		for (int i=1; i<=tot; i++) printf("%d ", ans[i]);
	}
	//else {
		
	//}
	
	
	
	return 0;
}

































