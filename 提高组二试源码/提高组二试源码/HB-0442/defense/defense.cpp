#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
char c,num;
int p[2005];
bool v[2005][2005];
int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.in","w",stdout);
    cin>>n>>m>>c>>num;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x][y]=v[y][x]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int a,x,b,y;
        cin>>a>>x>>b>>y;
        if(v[a][b]==1&&x==0&&y==0)cout<<-1<<endl;
    }
    return 0;
}
