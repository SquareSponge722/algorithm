#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=1e5+10;
int head[N],to[N<<1],Next[N<<1],cnt;
void add(int u,int v)
{
    to[++cnt]=v,Next[cnt]=head[u],head[u]=cnt;
}
int n,m,cost[N];
using std::min;
using std::swap;
namespace work1//这个可不开ll，注意1e5的要开
{
    int dp[2020][2],is[2020];
    const int inf=0x3f3f3f3f;
    void dfs(int now,int fa)
    {
        int s1=0,s2=0;
        for(int i=head[now];i;i=Next[i])
        {
            int v=to[i];
            if(v==fa) continue;
            dfs(v,now);
            s1+=min(dp[v][0],dp[v][1]);
            s2+=dp[v][1];
        }
        dp[now][0]=min(dp[now][0],s2);
        dp[now][1]=min(dp[now][1],s1+cost[now]);
        if(is[now]==1) dp[now][0]=inf;
        else if(is[now]==0) dp[now][1]=inf;
    }
    void solve()
    {
        memset(dp,0x3f,sizeof(dp));
        dfs(1,0);
        int ans=min(dp[1][0],dp[1][1]);
        if(ans>=inf) puts("-1");
        else printf("%d\n",ans);
    }
    void work()
    {
        memset(is,-1,sizeof(is));
        for(int a,x,b,y,i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&a,&x,&b,&y);
            is[a]=x;
            is[b]=y;
            solve();
            is[a]=-1;
            is[b]=-1;
        }
    }
}
namespace work2
{
    #define ll long long
    ll dp[N][2];
    const ll inf=0x3f3f3f3f3f3f3f3fll;
    void dfs(int now,int fa)
    {
        ll s1=0,s2=0;
        for(int i=head[now];i;i=Next[i])
        {
            int v=to[i];
            if(v==fa) continue;
            dfs(v,now);
            s1=s1+min(dp[v][0],dp[v][1]);
            s2=s2+dp[v][1];
        }
        dp[now][0]=min(dp[now][0],s2);
        dp[now][1]=min(dp[now][1],s1+cost[now]);
    }
    void work()
    {
        memset(dp,0x3f,sizeof(dp));
        dfs(1,0);
        for(int a,x,b,y,i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&a,&x,&b,&y);
            if(dp[1][1]>=inf) puts("-1");
            else printf("%lld\n",dp[1][1]);
        }
    }
}
namespace work3
{
    ll dp1[N][2],dp2[N][2];
    void init()
    {
        memset(dp1,0x3f,sizeof(dp1));
        memset(dp2,0x3f,sizeof(dp2));
        dp1[0][1]=0,dp2[n+1][1]=0;
        for(int i=1;i<=n;i++)
        {
            dp1[i][0]=dp1[i-1][1];
            dp1[i][1]=min(dp1[i-1][0],dp1[i-1][1])+cost[i];
        }
        for(int i=n;i;i--)
        {
            dp2[i][0]=dp2[i+1][1];
            dp2[i][1]=min(dp2[i+1][0],dp2[i+1][1])+cost[i];
        }
    }
    void work()
    {
        init();
        for(int a,x,b,y,i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&a,&x,&b,&y);
            if(a>b) swap(a,b),swap(x,y);
            if(x==1&&y==1)
                printf("%lld\n",dp1[a][1]+dp2[b][1]);
            else if(x==1&&y==0)
                printf("%lld\n",dp1[a][1]+min(dp2[b][1],dp2[b][0]));
            else if(x==0&&y==1)
                printf("%lld\n",min(dp1[a][0],dp1[a][1])+dp2[b][1]);
            else
                puts("-1");
        }
    }
}
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    char op[5];
    scanf("%d%d%s",&n,&m,op);
    for(int i=1;i<=n;i++) scanf("%d",cost+i);
    for(int u,v,i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    if(n<=2000&&m<=2000) work1::work();
    else if(op[1]=='1') work2::work();
    else if(op[0]=='A'&&op[1]=='2') work3::work();
    return 0;
}