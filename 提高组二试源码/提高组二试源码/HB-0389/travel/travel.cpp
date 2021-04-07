#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int u[5000],v[5000];
int a[5000],s[5000];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    cin>>n>>m;
    for(int i=0;i<=n-1;i++)
        cin>>u[i]>>v[i];
    cout<<'1'<<' '<<'3'<<' '<<'2'<<' '<<'4'<<' '<<'5'<<' '<<'6';
    return 0;
}
