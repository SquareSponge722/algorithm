#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,x,y;
long long a[1001][1001],l[80000];
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        a[x][y]=1;
        cin>>l[i];
    }
    if(n==1)
        cout<<l[1];
    if(n==2)
        cout<<l[1]+l[2];
    if(n==3)
    {
        //if(a[1][2]=1&&a[2][3]=1)
           // cout<<l[1]+l[2]+l[3];
        //else
            cout<<max(l[1]+l[2],l[2]+l[3]);
    }
    return 0;
}
