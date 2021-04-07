#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;

int n,m;
ll a[5005][5005];
ll minn1,maxx;
ll dis[50005];
bool book[50005];

ll mymin(ll x,ll y)
{
    return x>y?y:x;
}

ll mymax(ll x,ll y)
{
    return x>y?x:y;
}

void dfs(int t,ll tmp)
{
    int flagg=1;
    for(int j=1;j<=n;j++)
    {
        if(book[j]==0)
        {
            if(a[t][j]!=0)
            {
                flagg=0;
                book[j]=1;
                dfs(j,tmp+a[t][j]);
                book[j]=0;
            }
        }
    }
    if(flagg)
        {
            maxx=mymax(maxx,tmp);
            return ;
        }
}

int check(int k)
{
    int now=1;
    int cnt=0;
    ll ha=999999999;
    for(int i=1;i<n;i++)
    {
        ll tmp=dis[i]-dis[now-1];
        if(tmp>k)
        {
            now=i;
            ha=min(ha,tmp);
            cnt++;
        }
    }
    if(cnt>=m)
    {
        minn1=max(minn1,ha);
        return 1;
    }
    return 0;
}

int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=99999999;
    int flag=1;
    int flag1=1;
    for(int i=1;i<n;i++)
    {
        int x,y;
        ll z;
        scanf("%d%d%lld",&x,&y,&z);
        if(n<=5004)
        {
            a[x][y]=z;
            a[y][x]=z;
        }
        if(x!=1&&y!=1)
            flag=0;
        if(y!=x+1)
            flag1=0;
        dis[i]=z;
    }
    if(m==1&&n<=5004)
    {
        maxx=-1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]==99999999)
                    a[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            memset(book,0,sizeof(book));
            book[i]=1;
            dfs(i,0);
            book[i]=0;
        }
        printf("%lld",maxx);
        return 0;
    }
    else if(flag)
    {
        sort(dis+1,dis+n);
        printf("%d",dis[n-m]);
        return 0;
    }
    else if(flag1)
    {
        dis[0]=0;
        for(int i=1;i<n;i++)
            dis[i]+=dis[i-1];
        ll ave=dis[n-1]/m;
        int l=1,r=ave;
        int mid;
        minn1=-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid))
                l=mid+1;
            else
                r=mid-1;
        }
        printf("%lld",minn1);
        return 0;
    }
}
