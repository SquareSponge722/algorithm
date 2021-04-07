#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 100005;
typedef long long ll;
int n, m;
string s;
int w[N];
int col[N];
vector < int > r[N];
bool vis[N];
bool flag;
ll ans;
ll tot;
inline void dfs(int x, int t, int sum)
{
	if (flag)
		return;
	if (sum == n + 1)
	{
		flag = true;
		return;
	}
	if (vis[x])
		return;
	col[x] = t;
	vis[x] = true;
	int size = r[x].size();
	for (int i = 0; i < size; i ++)
	{
		int v = r[x][i];
		dfs(v, t *= (-1), sum + 1);
		if(t > 0)
			dfs(v, t, sum + 1);
		vis[x] = false;
		col[v] = 0;
	}
}
inline void ddfs(int x, int num)
{
	if (num > ans)
		return;
	if (x == n + 1)
	{
		ans = num;
		return;
	}
	if (col[x] == 1)
		ddfs(x + 1, num + w[x]);
	else if (col[x] == -1)
	{
		if (!col[x - 1])
			return;
		else
			ddfs(x + 1, num);
	}
	else
	{
		if (col[x - 1])
		{
			ddfs(x + 1, num);
			col[x] = 1;
			ddfs(x + 1, num + w[x]);
			col[x] = 0;
		}
		else
		{
			col[x] = 1;
			ddfs(x + 1, num + w[x]);
			col[x] = 0;
		}
	}
}
int main()
{
	freopen("defense.in", "r", stdin);
	freopen("defense.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++)
	{
		cin >> w[i];
		tot += w[i];
	}
	for (int i = 1; i < n; i ++)
	{
		 int x, y;
		 cin >> x >> y;
		 r[x].push_back(y);
		 r[y].push_back(x);
	}
	for (int i = 1; i <= m; i ++)
	{
		ans = -1;
		int x, t1, y, t2;
		scanf("%d%d%d%d", &x, &t1, &y, &t2);
		if (((x == y - 1) || (x == y + 1)) && !t1 && !t2)
			{
				cout << "-1" << endl;
				continue;
			}
		if (s[0] == 'A')
		{
			ans = tot;
			memset(col, 0, sizeof(col));
			if (! t1)
				t1 = -1;
			if (! t2)
				t2 = -1;
			col[x] = t1;
			col[y] = t2;
			if (col[1] == 0 || col[1] == -1)
			{	
				col[1] = 0;
				ddfs(2, 0);
			}
			memset(col, 0, sizeof(col));
			col[x] = t1;
			col[y] = t2;
			if(col[1] == 0 || col[1] == 1)
			{
				col[1] = 1;
				ddfs(2, w[1]);
			}
			cout << ans << endl;
			continue;
		}
		memset(col, 0, sizeof(col));
		memset(vis, 0, sizeof(vis));
		if (! t1)
			t1 = -1;
		if (! t2)
			t2 = -1;
		col[x] = t1;
		col[y] = t2;
		dfs(1, -1, 1);
		if (flag)
		{
			ans = 0;
			for (int i = 1; i <= n; i ++)
			if(col[i] == 1)
				ans += w[i];
		}
		if (! flag)
		{
			memset(col, 0, sizeof(col));
			memset(vis, 0, sizeof(vis));
			dfs(1, 1, 1);
			if (flag)
			{
				ans = 0;
				for (int i = 1; i <= n; i ++)
					if(col[i] == 1)
						ans += w[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
