#include<iostream>
#include<cstdio>
using namespace std;
long long f[100010];
int a[100010];
int n;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int mi;
    mi=a[1];f[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>mi)f[i]=f[i-1]+a[i]-mi;
        else f[i]=f[i-1];
        mi=a[i];
    }
    cout<<f[n];

    return 0;
}
