#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

int n;
ll a[100005];
ll ans;

void dfs(int x,int y)
{
    //cout<<x<<' '<<y<<endl;
    if(x>y||x==y)
    {
        ans+=a[x];
        return ;
    }
    int minn1=999999;
    int flag1;
    for(int i=x;i<=y;i++)
    {
        if(a[i]<minn1)
        {
            minn1=a[i];
            flag1=i;
        }
    }
    ans+=minn1;
    for(int i=x;i<=y;i++)
        a[i]-=minn1;
    dfs(x,flag1-1);
    dfs(flag1+1,y);
    return ;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ll minn=999999;
    ans=0;
    int flag;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]<minn)
        {
            minn=a[i];
            flag=i;
        }
    }
    //cout<<flag<<endl;
    ans+=minn;
    for(int i=1;i<=n;i++)
        a[i]-=minn;
    dfs(1,flag-1);
    dfs(flag+1,n);
    printf("%lld",ans);
    return 0;
}
