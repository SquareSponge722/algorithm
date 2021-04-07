#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 5010;
int n,m,du[maxn];
vector<int> V[maxn];

namespace task2
{
int S[maxn],top,vis[maxn],ans[maxn],tx,ty;
int print[maxn],cnt;

void dfs(int u)
{
    S[++top] = u;
    vis[u] = 1;
    for (int i = 0; i < V[u].size(); i++)
    {
        int v = V[u][i];
        if (vis[v] || du[v] != 2)
            continue;
        dfs(v);
    }
}

void dfs2(int u,int fa)
{
    print[++cnt] = u;
    for (int i = 0; i < V[u].size(); i++)
    {
        int v = V[u][i];
        if (v == fa)
            continue;
        if (u == tx && v == ty)
            continue;
        if (u == ty && v == tx)
            continue;
        dfs2(v,u);
    }
}

void solve2(int x,int y)
{
    tx = x;
    ty = y;
    cnt = 0;
    dfs2(1,0);
    if (ans[1] == 0)
        for (int i = 1; i <= n; i++)
            ans[i] = print[i];
    else
    {
        bool flag = false;
        for (int i = 1; i <= n; i++)
            if (ans[i] != print[i])
            {
                if (print[i] < ans[i])
                {
                    flag = true;
                    break;
                }
                else
                    break;
            }
        if (flag)
            for (int i = 1; i <= n; i++)
                ans[i] = print[i];
    }
}

void topo()
{
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (du[i] == 1)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < V[u].size(); i++)
        {
            int v = V[u][i];
            if (--du[v] == 1)
                q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (du[i] == 2)
        {
            dfs(i);
            break;
        }
}

void solve()
{
    topo();
    for (int i = 1; i <= top; i++)
    {
        int x,y;
        if (i == top)
        {
            x = S[top];
            y = S[1];
        }
        else
        {
            x = S[i];
            y = S[i + 1];
        }
        solve2(x,y);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ",ans[i]);
}
}

namespace task1
{
int ans[maxn],top;

void dfs(int u,int fa)
{
    ans[++top] = u;
    for (int i = 0; i < V[u].size(); i++)
    {
        int v = V[u][i];
        if (v == fa)
            continue;
        dfs(v,u);
    }
}

void solve()
{
    dfs(1,0);
    for (int i = 1; i <= top; i++)
        printf("%d ",ans[i]);
}
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        du[x]++;
        du[y]++;
        V[x].push_back(y);
        V[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        sort(V[i].begin(),V[i].end());
    if (m == n - 1)
        task1::solve();
    else
        task2::solve();

    return 0;
}
