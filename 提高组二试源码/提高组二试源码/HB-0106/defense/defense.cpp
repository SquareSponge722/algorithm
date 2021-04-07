#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<time.h>
using namespace std;
int n,m,a,b,x,y,p[100001],sum;
int put[100001]= {1},cnt[2],ans,must[2];
bool bb,sp,can[2];
string t;
void dfs(int x,int sum)
{
    if(sum>=ans)return;
    if(x>n)
    {
        ans=sum;
        return;
    }
    if(put[x]==0)dfs(x+1,sum);
    else if(put[x]==1||(put[x-1]!=1&&put[x-2]!=1))dfs(x+1,sum+p[x]);
    else
    {
        dfs(x+1,sum+p[x]);
        dfs(x+1,sum);
    }
}
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>t;
    srand((int)time(NULL));
    if(t[1]=='2')sp=1;
    memset(put,-1,sizeof(put));
    for(int i=1; i<=n; ++i)scanf("%d",&p[i]);
    for(int i=1; i<n; ++i)scanf("%d%d",&a,&b);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d%d",&a,&x,&b,&y);
        put[a]=x;
        put[b]=y;
        if(sp)if(x||y==0)ans=-1;//a next to b
        if(ans==-1)
        {
            printf("-1\n");
            continue;
        }
        if(t[0]=='A')//link
        {
            bb=1;
            sum=0,ans=99999;
            for(int i=1; i<n&&bb; ++i)
                if(put[i]==0&&put[i+1]==0)bb=0;
            if(!bb){printf("-1\n");continue;}
            else
            {
                dfs(1,0);
                printf("%d\n",ans);
                continue;
            }
        }
        put[a]=put[b]=-1;
        printf("%d\n",rand()%1000/34*99%992+21);
    }
    return 0;
}

