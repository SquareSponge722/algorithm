#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
int n, m;
const int N = 5005;
vector < int > r[N];
bool vis[N];
struct node
{
	int id;
	bool operator < (const node & a) const
	{
		return (id > a.id);
	}
};
inline void dfs(int x)
{
	vis[x] = true;
	printf("%d ", x);
	int size = r[x].size();
	if(! size)
		return;
	priority_queue < node > q;
	for (int i = 0; i < size; i ++)
	{
		node temp;
		temp.id = r[x][i];
		q.push(temp);
	}
	while(! q.empty())
	{
		int next = q.top().id;
		if (! vis[next])
			dfs(next);
		q.pop();
	}
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		r[x].push_back(y);
		r[y].push_back(x);
	}
	if (n > m)
	{
		dfs(1);
		printf("\n");
	}
	if (n == m)
	{
		dfs(1);
		printf("\n");
	}
	return 0;
}
