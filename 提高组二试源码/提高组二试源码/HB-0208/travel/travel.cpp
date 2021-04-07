#include<iostream>
#include<cstdio>
using namespace std;
int city[10000][10000];
bool bb[10000][10000];
int n,m;
int a[100000],b[100000];
int sum=0;
int f[100000];
void full(int x,int y)
{
    city[x][y]=1;
    city[y][x]=1;
}
void dfs(int xx,int yy,int index,int father)
{
    bool flag=false;
    for(int j=1; j=n; j++)
        if(city[xx][j]!=0 && bb[xx][yy]==true) flag=true;
    if(index==1 && city[xx][yy]==1)
    {
        bb[xx][yy]=false;
        bb[yy][xx]=false;
        f[index]=xx;
        f[index+1]=yy;
        index+=2;
        father+=2;
        dfs(yy,1,index,father);
    }
    else if(index==1 && city[xx][yy]!=1)
    {
        dfs(xx,yy++,index,father);
    }
    if(flag==true)
    {
        if(index>1 && bb[xx][yy]==true && city[xx][yy]==1)
        {
            f[index]=yy;
            bb[xx][yy]=false;
            bb[yy][xx]=false;
            index++;
            father++;
            dfs(yy,1,index,father);
        }
        else if(index>1 && city[xx][yy]!=1)
        {
            dfs(xx,yy++,index,father);
        }
        else if(index>1 && bb[xx][yy]==false)
        {
            dfs(xx,yy++,index,father);
        }
    }
    else
    {
        father--;
        dfs(f[father],1,index,father);
        sum++;
    }
    if(sum==m) for(int i=1;i<=n;i++)
        cout<<f[i]<<' ';
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("trevel.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=1000; i++)
        for(int j=1; j<=1000; j++)
        {
            city[i][j]=0;
            bb[i][j]=true;
        }
    for(int i=1; i<=m; i++)
    {
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=m;i++)
        full(a[i],b[i]);
    dfs(1,2,1,1);
    for(int i=1;i<=n;i++)
        cout<<f[i]<<' ';
    return 0;
}
