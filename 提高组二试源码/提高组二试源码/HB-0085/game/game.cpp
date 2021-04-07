#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll n,m;

namespace task1
{
    string zou[1010],num[1010];
    ll tot,ans,a[20][20];

    void dfs(ll x,ll y,string s)
    {
        if (x == n && y == m)
        {
            zou[++tot] = s;
            return;
        }
        if (x == n)
            dfs(x,y + 1,s + 'R');
        else if (y == m)
            dfs(x + 1,y,s + 'D');
        else
        {
            dfs(x,y + 1,s + 'R');
            dfs(x + 1,y,s + 'D');
        }
    }

    void solve2()
    {
        for (ll i = 1; i <= tot; i++)
        {
            num[i] = "";
            ll tx = 1,ty = 1;
            for (ll j = 0; j < zou[i].size(); j++)
            {
                if (zou[i][j] == 'R')
                    ty++;
                else
                    tx++;
                if (a[tx][ty] == 0)
                    num[i] += '0';
                else
                    num[i] += '1';
            }
        }
        for (ll i = 1; i <= tot; i++)
            for (ll j = 1; j <= tot; j++)
                if (i != j)
                    if (zou[i] > zou[j])
                        if (num[i] > num[j])
                            return;
        ans++;
    }

    void dfs2(ll x,ll y)
    {
        if (x == n + 1)
        {
            solve2();
            return;
        }
        a[x][y] = 1;
        if (y == m)
            dfs2(x + 1,1);
        else
            dfs2(x,y + 1);
        a[x][y] = 0;
        if (y == m)
            dfs2(x + 1,1);
        else
            dfs2(x,y + 1);
    }

    void solve()
    {
        dfs(1,1,"");
        dfs2(1,1);
        printf("%lld\n",ans);
    }
}

namespace task2
{

    ll qpow(ll a,ll b)
    {
        ll res = 1;
        while (b)
        {
            if (b & 1)
                res = 1LL * res * a % mod;
            a = 1LL * a * a % mod;
            b >>= 1;
        }
        return res;
    }

    void solve()
    {
        printf("%lld\n",1LL * 4 * qpow(3,m - 1) % mod);
    }
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if (n <= 3 && m <= 3)
        task1::solve();
    else if (n == 2)
        task2::solve();
    else
        task1::solve();

    return 0;
}
