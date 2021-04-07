#include<iostream>
#include<cstdio>
using namespace std;
int mapp[9527][9527]= {0};
int book[9527]= {0};
int ff(int num)
{
    int j=1;
    while(mapp[num][j]==0||book[j]==1)
        j++;
    return j;
}
int main()
{
    freopen("travel3.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        mapp[a][b]=mapp[b][a]=1;
    }
    book[1]=1;
    cout<<1<<" ";
    for(int i=2; i<=n; i++)
    {
        int minn=9527;
        for(int j=1; j<=n; j++)
            if(book[j]==1)
                if(ff(j)<minn)minn=ff(j);
        book[minn]=1;
        cout<<minn<<" ";
    }
    return 0;
}
