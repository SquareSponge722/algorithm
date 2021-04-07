#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#define NO 3000005
#define P 1000000007
#define INF 0x3f3f3f3f
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

int n, m, cnt, head[NO], val[NO], a, b;
ll ans;
bool book[NO];
string type;
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
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	n = read(), m = read();
	cin>>type;
	for(int i = 1; i <= n; i++)
		val[i] = read();
	for(int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		add(x, y), add(y, x);
	}
}
void dfs(int step, ll tot)
{
	if(tot > ans)
		return;
	if(step == n + 1)
	{
		bool f = false;
		for(int i = 1; i <= n; i++)
		{
			bool f1 = true;
			for(int j = head[i]; j; j = edge[j].next)
				if(!book[edge[j].to])
				{
					f1 = false;
					break;
				}
			if(book[i])
				f1 = true;
			if(!f1)
			{
				f = true;
				break;
			}
		}
		if(f)
			return;
		if(tot < ans)
		{
			ans = tot;
		}
	}
	else
	{
		if(step != a && step != b)
			book[step] = false, dfs(step + 1, tot), book[step] = true, dfs(step + 1, tot + val[step]);
		else
			dfs(step + 1, tot);
	}
}
//functions

int main()
{
	init();
	if(type[0] == 'A' && n > 100)
	{
		while(m--)
		{
			int a = read(), x = read(), b = read(), y = read();
			if(x == 0 && y == 0)
				printf("-1\n");
			else
			{
				for(int i = a - 1; i >= 1; i--)
					if((a - i) % 2)
						ans += val[i] * !x;
					else
						ans += val[i] * x;
				for(int i = a + 1; i < b; i++)
					if((i - a) % 2)
						ans += val[i] * !x;
					else 
						ans += val[i] * x;
				for(int i = b + 1; i <= n; i++)
					if((i - b) % 2)
						ans += val[i] * !x;
					else
						ans += val[i] * x;
				ans += val[a] * x + val[b] * y;
			}
				
		}
	}
	while(m--)
	{
		bool x, y;
		a = read(), x = read(), b = read(), y = read();
		memset(book, false, sizeof(book));
		book[a] = x, book[b] = y;
		ans = (ll)INF * INF;
		dfs(1, val[a] * x + val[b] * y);
		if(ans == (ll)INF * INF)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
//main
