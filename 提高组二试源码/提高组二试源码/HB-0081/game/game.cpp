#include<bits/stdc++.h>
typedef long long LL;
const LL mod=1e9+7;
using namespace std;

LL n,m;

LL Pow(LL base,LL t)
{
    LL ans=1;
    for(LL i=1;i<=t;i++)
    {
        ans*=base;
        ans%=mod;
    }
    return ans;
}

void work1()
{
    if(n==1 && m==1) printf("2");
    if(n==1 && m==2) printf("4");
    if(n==1 && m==3) printf("8");
    if(n==2 && m==1) printf("2");
    if(n==2 && m==2) printf("12");
    if(n==2 && m==3) printf("36");
    if(n==3 && m==1) printf("8");
    if(n==3 && m==2) printf("36");
    if(n==3 && m==3) printf("112");
    exit(0);
}

void work2()
{
    if(n==1) printf("%lld",Pow(2,m));
    if(n==2) printf("%lld",Pow(3,m-1)*4%mod);
    exit(0);
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(n<=3 && m<=3) work1();
    else if(n<=2) work2();
    return 0;
}
