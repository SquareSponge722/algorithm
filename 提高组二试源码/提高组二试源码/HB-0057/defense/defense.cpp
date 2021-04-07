#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define ll long long

using namespace std;

int n,m,typee;
char aa;
int a,b,x,y;
ll ans;
ll cost[100005];
bool book[2005][2005];

ll mymin(ll x,ll y)
{
    return x>y?y:x;
}

void dfs(int step,int flag,ll now)
{
    //cout<<now<<endl;
    if(step==n)
    {
        ans=mymin(ans,now+flag*cost[step]);
        return ;
    }
    if(flag==0&&((step+1==a&&x==0)||(step+1==b&&y==0)))
        return ;
    else if((step+1==a&&x==1)||(step+1==b&&y==1))
        dfs(step+1,1,now+flag*cost[step]);
    else if((step+1==a&&x==0)||(step+1==b&&y==0))
        dfs(step+1,0,now+flag*cost[step]);
    else if(flag==1)
    {
        dfs(step+1,1,now+flag*cost[step]);
        dfs(step+1,0,now+flag*cost[step]);
    }
    else
        dfs(step+1,1,now+flag*cost[step]);
}

int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);

    memset(book,0,sizeof(book));
    scanf("%d%d",&n,&m);
    getchar();
    scanf("%c",&aa);
    //cout<<aa<<endl;
    scanf("%d",&typee);
    for(int i=1;i<=n;i++)
        scanf("%d",&cost[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        book[x][y]=1;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&a,&x,&b,&y);
        ans=9999999999;
        if(aa=='A')
        {
            if((a==b-1||b==a-1)&&x==0&&y==0)
            {
                printf("-1\n");
                continue;
            }
            else
            {
                if((a==1&&x==0)||(b==1&&y==0))
                    dfs(1,0,0);
                else if((a==1&&x==1)||(b==1&&y==1))
                    dfs(1,1,0);
                else
                {
                    dfs(1,0,0);
                    dfs(1,1,0);
                }
                printf("%lld\n",ans);
            }
        }
    }
}
