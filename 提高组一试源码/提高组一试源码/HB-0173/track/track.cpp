#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
const int N = 50005;
struct node
{
	 int v;
	 int w;
};
vector < node > r[N];
int dis[N];
bool vis[N];
int temp[N];
bool flag1 = true;
bool flag2 = true;
int in[N];
int edge[N];
inline int spfa(int fr)
{
	queue < int > q;
	memset(temp, 0, sizeof(temp));
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	vis[fr] = true;
	q.push(fr);
	while(! q.empty())
	{
		int h = q.front();
		q.pop();
		vis[h] = false;
		int size = r[h].size();
		for (int i = 0; i < size; i ++)
		{
			int v = r[h][i].v;
			if(dis[v] < dis[h] + r[h][i].w && temp[h] != v)
			{
				dis[v] = dis[h] + r[h][i].w;
				temp[v] = h;
				if (! vis[v])
				{
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
	int sum = dis[fr];
	for (int i = 1; i <= n; i ++)
		sum = max(sum, dis[i]);
	return sum;
}
bool check(int x)
{
	int tot = 1;
	int now = 0;
	for (int i = 2; i <= n; i ++)
	{
		if(now >= x)
		{
			now = edge[i];
			tot ++;
		}
		else
			now += edge[i];
		if (tot == m)
			return true;
	}
	return false;
}
int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int tot = 0;
	for (int i = 1; i < n; i ++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		node temp;
		temp.v = y;
		temp.w = w;
		r[x].push_back(temp);
		temp.v = x;
		r[y].push_back(temp);
		in[x] ++;
		in[y] ++;
		edge[y] = w;
		tot += edge[y];
		if (x != 1)
			flag1 = false;
		if (y != x + 1)
			flag2 = false;	
	}
	if (m == 1)
	{
		int ans = 0;
		for (int i = 1; i <= n; i ++)
		ans = max(ans, spfa(i));
		printf("%d\n", ans);
	}
	else if (flag1)
	{
		sort(&edge[2], &edge[n + 1]);
		int ans = edge[n - m * 2 + 1] + edge[n];
		for (int i = n - m * 2 + 1; i <= n - m; i ++)
			ans = min(ans, edge[i] + edge[2 * n - m * 2 + 1 - i]);
		printf("%d\n", ans);
	}
	else if (flag2)
	{
		int tot = 0;
		int l = edge[2], r = tot / m;
		int mid;
		while (l < r)
		{
			mid = (l + r + 1) / 2;
			if (check(mid))
				l = mid;
			else
				r = mid - 1;
		}
		printf("%d\n", l);
	}
	else
		printf("%d\n", tot / m);
	return 0;
}
