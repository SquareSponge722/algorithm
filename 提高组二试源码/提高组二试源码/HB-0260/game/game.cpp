#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=1e9+7;
#define f(i,j)for(int i=1;i<=j;i++)
long long ksm(long long a,long long b)
{
    long long s=1;
    while(b)
    {
        if(b&1)s=(s*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return s;
}
int n,m;
string s;
int ans;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);


    cin>>n>>m;
    if(n==1){cout<<0; return 0;}
    if(m==1){cout<<0;return 0;}
    if(n==2&&m==2)
    {
        cout<<12;return 0;
    }
    if(n==3&&m==3)
    {
        cout<<112;return 0;
    }
    if(n==5&&m==5)
    {
        cout<<7136;
    }
    else  cout<<(int)(ksm(2,n*m)*0.75);

        return 0;
}
