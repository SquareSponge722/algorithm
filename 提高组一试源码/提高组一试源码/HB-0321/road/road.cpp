#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[110000],i,n;
long long v,m;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        m+=a[i];
    }
    a[0]=a[m+1]=-1;
    v=m/n;
    ///cout<<v<<endl;
    ///for(i=1;i<=n;i++) cout<<a[i]<<' ';
    ///cout<<endl;
    for(i=1; i<=n; i++)
    {
        a[i]-=v;
    }
    ///for(i=1;i<=n;i++) cout<<a[i]<<' ';
    for(i=2;i<=n-1;i++)
    {
        v+=min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]));
    }
    cout<<v;
    return 0;
}

