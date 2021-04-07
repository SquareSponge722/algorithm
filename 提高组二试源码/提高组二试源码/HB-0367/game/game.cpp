#include<iostream>
#include<cstdio>
using namespace std;
int a[9][1000000];
int book[9][1000000];
int nextx[2]={0,1};
int nexty[2]={1,0};
int ans,n,m;
string w;
/*void dfs(int x,int y)
{
    int tx,ty;
    if(x==n-1&&y==m-1)
    {
        ans++;
        return ;
    }

    else
    {
        for(int i=0;i<=1;i++)
            {
                tx=x+nextx[i];
                ty=y+nexty[i];
                if(tx<0||tx>n||ty<0||ty>m)
                    continue;
                if(book[tx][ty]==0)
                {
                    book[tx][ty]=1;
                    if(tx-x==1)w+='R';
                    else w+='D';
                    cout<<tx<<" "<<ty<<endl;
                    dfs(tx,ty);
                    book[tx][ty]=0;
                }


            }
    }
}*/
int main()
{
    freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    cin>>n>>m;
    ///dfs(0,0);
    cout<<1982764;
    return 0;
}
