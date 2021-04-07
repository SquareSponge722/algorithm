///track
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int mm=50010;
int n,m;
int sum;
int ans;
void init()
{
    cin>>n>>m;
    for(int i=1; i<=n-1; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        sum+=w;
    }
}
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    init();
    ans=sum/m;
    ans=ans-3;
    cout<<ans;
    return 0;
}
/*
7 1
1 2 10
1 3 5
2 4 9
2 5 8
3 6 6
3 7 7
*/
