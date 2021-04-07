#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int m,n,i,a,b,c,s;
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    cin>>m>>n;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        s+=c;
    }
    cout<<s/n;
    return 0;
}

