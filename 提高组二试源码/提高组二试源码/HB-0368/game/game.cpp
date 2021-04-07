#include <cstdio>
int n,m;
namespace work1
{
    int s[300],a[4][4],tot;
    void dfs(int x,int y,int d)
    {
        d+=a[x][y];
        if(x==n&&y==m)
        {
            s[++tot]=d;
            return;
        }
        if(y!=m) dfs(x,y+1,d<<1);
        if(x!=n) dfs(x+1,y,d<<1);
    }
    bool check()
    {
        tot=0;
        dfs(1,1,0);
        for(int i=1;i<tot;i++)
            if(s[i]>s[i+1]) return 0;
        return 1;
    }
    void work()
    {
        int ans=0;
        for(int s=0;s<1<<m*n;s++)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    a[i][j]=s>>((i-1)*m+j-1)&1;
            ans+=check();
        }
        printf("%d\n",ans);
    }
}
#define ll long long
namespace work2
{
    const ll mod=1e9+7;
    ll quickpow(ll d,ll k)
    {
        ll f=1;
        while(k)
        {
            if(k&1) f=f*d%mod;
            d=d*d%mod;
            k>>=1;
        }
        return f;
    }
    void work()
    {
        ll ans=2ll*2*quickpow(3ll,m-1)%mod;
        printf("%lld\n",ans);
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n<=3&&m<=3) work1::work();
    else if(n==2) work2::work();
    return 0;
}