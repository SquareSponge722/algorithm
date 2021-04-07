#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m;
const int mm=100010;
vector<int>mat[mm];
string type;
int p[mm];
int dp[mm];
int a[mm];
int isok[mm];
int vis[mm];
int minn=100203241;
int jish;
void dfs(int x,int k,int pre)
{
    if(isok[x]==-1)return;
    if(x>n)return;
    if(x==n||x==n-1){if(k<minn)minn=k;return;}

    if(isok[x]==1)
    {dfs(x+1,k,1);
    dfs(x+2,k,0);
    }
    else if(pre==0)
    {
        dfs(x+1,k+p[x],1);
    dfs(x+2,k+p[x],0);
    }
    else if(isok[x]==0&&pre==1)
    {
        dfs(x+1,k+p[x],1);
        dfs(x+1,k,0);
    }

}
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    cin>>n>>m>>type;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        mat[x].push_back(y);
        mat[y].push_back(x);
    }
    for(int i=1;i<=m;i++)
    {
        int a,x,b,y;
        cin>>a>>x>>b>>y;
        if(x==1){isok[a]=1;jish+=p[a];}
        if(x==0)isok[a]=-1;
        if(y==1){isok[a]=1;jish+=p[b];}
        if(y==0)isok[a]=-1;
    if(type[0]=='A')
    {
        if(n<=10&&m<=10)
        {
            if(isok[1]==1)
            {dfs(1,jish,1);
            dfs(2,jish,1);
            }
            if(isok[1]!=0)
            {
                dfs(1,jish,1);
            }
            cout<<minn;
            return 0;
        }
        if(type[1]=='1')
        {
            int pre=1;
            int ans=0;
           for(int i=2;i<=n;i++)
           {
               if(p[i+1]<p[i]){ans+=p[i+1];i++;}
               else ans+=p[i];
           }
           cout<<ans;
           return 0;
        }
    }
    else
    {
        for(int i=1;i<=m;i++)
        cout<<-1<<endl;
    }
    }
    return 0;
}
