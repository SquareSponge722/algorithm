#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100010,inf = 5e8;
int n,m,head[maxn],to[maxn],nextt[maxn],w[maxn],tot = 1,sum[maxn];
bool flag1 = true,flag2 = true;

void add(int x,int y,int z)
{
    w[tot] = z;
    to[tot] = y;
    nextt[tot] = head[x];
    head[x] = tot++;
}

namespace task4
{
int d[maxn],fa[maxn],res,vis[maxn],Time,xianzhi;
vector<int> V[50010];

void dfs2(int u,int faa)
{
    for (int i = head[u]; i; i = nextt[i])
    {
        int v = to[i];
        if (v == faa)
            continue;
        dfs2(v,u);
    }
    int limit = (int)V[u].size();
    if (V[u].empty())
    {
        V[faa].push_back(d[u]);
        return;
    }
    sort(V[u].begin(),V[u].end());
    ++Time;
    int cur = 0;
    for (int i = limit - 1; i >= 0; i--)
    {
        if (vis[i] == Time)  //如果被访问过了
            continue;
        if (V[u][i] >= xianzhi)   //如果自己单独成一个
        {
            vis[i] = Time;
            res++;
            continue;
        }
        while (cur < i && V[u][cur] + V[u][i] < xianzhi)
            cur++;
        if (cur >= i)
            continue;
        vis[cur] = vis[i] = Time;
        res++;
        cur++;
    }
    int maxx = 0;
    for (int i = limit - 1; i >= 0; i--)
        if (vis[i] != Time)
            maxx = max(maxx,V[u][i]);
    V[faa].push_back(maxx + d[u]);
}

void dfs(int u,int faa)
{
    fa[u] = faa;
    for (int i = head[u]; i; i = nextt[i])
    {
        int v = to[i];
        if (v == faa)
            continue;
        d[v] = w[i];
        dfs(v,u);
    }
}

bool check(int x)
{
    for (int i = 0; i <= n; i++)
        V[i].clear();
    res = 0;
    xianzhi = x;
    dfs2(1,0);
    return res >= m;
}

void solve()
{
    dfs(1,0);
    int l = 1,r = inf,ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n",ans);
}
}

namespace task3
{
bool check(int x)
{
    int res = 0;
    int cur = 1;
    for (int i = 2; i <= n; i++)
    {
        if (sum[i] - sum[cur] >= x)
        {
            res++;
            cur = i;
        }
    }
    return res >= m;
}

void solve()
{
    for (int i = 2; i <= n; i++)
        sum[i] += sum[i - 1];
    int l = 1,r = inf,ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n",ans);
}
}

namespace task2
{
int S[maxn],top,ans,vis[maxn],Time;
set<pair<int,int> >s;

bool check(int x)
{
    ++Time;
    int cur = 1,res = 0;
    for (int i = top; i >= 1; i--)
    {
        if (vis[i] == Time) //如果被访问过了
            continue;
        if (S[i] >= x)  //如果自己一个人就可以
        {
            res++;
            vis[i] = Time;
            continue;
        }
        while (cur < i && S[cur] + S[i] < x)
            cur++;
        if (cur >= i)
            continue;
        vis[cur] = vis[i] = Time;
        cur++;
        res++;
    }
    return res >= m;
}

void solve()
{
    for (int i = head[1]; i; i = nextt[i])
        S[++top] = w[i];
    sort(S + 1,S + 1 + top);
    int l = 1,r = inf,ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d\n",ans);
}
}

namespace task1
{
int p,q,maxx;

void dfs1(int u,int fa,int len)
{
    if (len > maxx)
    {
        maxx = len;
        p = u;
    }
    for (int i = head[u]; i; i = nextt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        dfs1(v,u,len + w[i]);
    }
}

void dfs2(int u,int fa,int len)
{
    if (len > maxx)
    {
        maxx = len;
        q = u;
    }
    for (int i = head[u]; i; i = nextt[i])
    {
        int v = to[i];
        if (v == fa)
            continue;
        dfs2(v,u,len + w[i]);
    }
}

void solve()
{
    maxx = 0;
    dfs1(1,0,0);
    maxx = 0;
    dfs2(p,0,0);
    printf("%d\n",maxx);
}
}

int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i < n; i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (x != 1)
            flag1 = false;
        if (y != x + 1)
            flag2 = false;
        sum[y] = z;
        add(x,y,z);
        add(y,x,z);
    }
    if (m == 1)  //直径
        task1::solve();
    else if (flag1)  //二分+分组
        task2::solve();
    else if (flag2)  //一条链
        task3::solve();
    else  //正解
        task4::solve();

    return 0;
}

