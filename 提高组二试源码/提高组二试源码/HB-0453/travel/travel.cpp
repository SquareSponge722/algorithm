#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 5000 + 10, maxm = maxn * 2;
int n, m, dfs_f[maxn], cnt = 0;
priority_queue<int, vector<int>, greater<int> > q[maxn];
bool vis[maxn], onh[maxn];
void dfs(int nd)
{
    if(vis[nd]) return;
    vis[nd] = true;
    printf("%d ", nd);
    dfs_f[cnt++] = nd;
    while(!q[nd].empty()) { int v = q[nd].top(); q[nd].pop(); dfs(v); }
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        q[u].push(v);
        q[v].push(u);
    }
    dfs(1);
    return 0;
}
