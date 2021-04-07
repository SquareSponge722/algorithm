#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll maxn = 200010,inf = 1e13;
ll n,m,head[maxn],to[maxn],nextt[maxn],tot = 1,A[maxn];
char ch[10];

void add(ll x,ll y)
{
    to[tot] = y;
    nextt[tot] = head[x];
    head[x] = tot++;
}

namespace task1
{
    ll f[2010][2];

    void dfs(ll u,ll fa)
    {
        ll sum = 0,minn = inf,pos = 0;
        for (ll i = head[u];i;i = nextt[i])
        {
            ll v = to[i];
            if (v == fa)
                continue;
            dfs(v,u);
            f[u][0] += f[v][1];
            f[u][1] += min(f[v][0],f[v][1]);
        }
    }

    void solve()
    {
        while (m--)
        {
            ll a,x,b,y;
            scanf("%lld%lld%lld%lld",&a,&x,&b,&y);
            bool flag = true;
            if (x == 0 && y == 0)
                for (ll i = head[a];i;i = nextt[i])
                    if (to[i] == b)
                    {
                        flag = false;
                        break;
                    }
            if (!flag)
            {
                puts("-1");
                continue;
            }
            for (ll i = 1; i <= n; i++)
                f[i][1] = A[i],f[i][0] = 0;
            f[a][x ^ 1] = f[b][y ^ 1] = inf;
            dfs(1,0);
            printf("%lld\n",min(f[1][0],f[1][1]));
        }
    }
}

int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    scanf("%s",ch);
    for (ll i = 1; i <= n; i++)
        scanf("%lld",&A[i]);
    for (ll i = 1; i < n; i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        add(x,y);
        add(y,x);
    }
    task1::solve();

    return 0;
}
