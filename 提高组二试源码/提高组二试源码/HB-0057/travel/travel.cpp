#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define ll long long

using namespace std;

int n,m;
int a[5005][5005];
bool book[5005];
int flag[5005];

int judge()
{
    for(int i=1;i<=n;i++)
        if(book[i]==0)
            return 0;
    return 1;
}

void dfs1(int x)
{
    if(judge())
        return ;
    for(int i=1;i<=n;i++)
        if(i!=x&&book[i]==0&&a[x][i]==1)
        {
            book[i]=1;
            printf("%d ",i);
        }
    flag[x]++;
    for(int i=1;i<=n;i++)
        if(a[x][i]&&flag[i]==0)
            dfs1(i);
    return ;
}

void dfs2(int x)
{
    if(judge())
        return ;
    for(int i=1;i<=n;i++)
        if(i!=x&&book[i]==0&&a[x][i]==1)
        {
            book[i]=1;
            printf("%d ",i);
            dfs2(i);
        }
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    memset(flag,0,sizeof(flag));
    memset(a,0,sizeof(a));
    memset(book,0,sizeof(book));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=1;
        a[y][x]=1;
    }
    book[1]=1;
    printf("1 ");
    if(n==m)
        dfs1(1);
    else
        dfs2(1);
    return 0;
}
