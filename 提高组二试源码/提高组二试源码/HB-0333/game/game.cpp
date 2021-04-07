#include<iostream>
#include<cstdio>
#include<string.h>
#include<map>
using namespace std;
int n,m,MAX,a[15],ans,go[15],num[2],cnt=1,Go[100][15],Mat[5][5];//0D 1R


inline int read()
{
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}
    while(ch<'0'||ch>'9');
    do{x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    while(ch>='0'&&ch<='9');
    return f*x;
}

void dfs2(int cur)
{
    if(cur>m+n-2)
    {
        for(int i=1;i<cur;i++)
            Go[cnt][i]=go[i];
        cnt++;return;
    }
    for(int i=0;i<2;i++)
    {
        if(num[i]<1)continue;
        num[i]--;
        go[cur]=i;
        dfs2(cur+1);
        num[i]++;
    }
}

inline bool path(int i,int j)
{
    int p1=0,p2=0;
    for(int k=1;k<=n+m-2;k++)
        p1=10*p1+Go[i][k];
    for(int k=1;k<=n+m-2;k++)
        p2=10*p2+Go[j][k];
    if(p1<p2)swap(i,j);
    int lsk=0,ITS=0,x=1,y=1;
    for(int k=1;k<=n+m-2;k++)
    {
        if(Go[i][k]==0)
            x++;
        else y++;
        lsk=10*lsk+Mat[x][y];
    }
    x=1,y=1;
    for(int k=1;k<=n+m-2;k++)
    {
        if(Go[j][k]==0)
            x++;
        else y++;
        ITS=10*ITS+Mat[x][y];
    }
    if(lsk<=ITS)return true;
    return false;
}

inline bool check()
{
    int k=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            Mat[i][j]=a[++k];
    }
    for(int i=1;i<cnt-1;i++)
    {
        for(int j=i+1;j<cnt;j++)
            if(!path(i,j))
                return false;
    }
    return true;
}

void dfs(int cur)
{
    if(cur>MAX)
    {
        if(check())
            ans++;
        return;
    }
    for(int i=0;i<2;i++)
    {
        a[cur]=i;
        dfs(cur+1);
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read(),m=read();MAX=n*m;
    num[1]=m-1;num[0]=n-1;
    dfs2(1);
    dfs(1);
    cout<<ans;
    return 0;
}

