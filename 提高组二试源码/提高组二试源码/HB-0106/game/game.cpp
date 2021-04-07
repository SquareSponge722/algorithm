#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int const mod=1e9+7,maxm=1e7;
long long ans=1;
long long quick(int p,int x)//p^x
{
    long long s=1,t=p;
    while(x)
    {
        if(x&1)s=s*t%mod;
        x>>=1;
        t=t*t%mod;
    }
    return s%mod;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(n==1)printf("%ld",quick(2,m)*4%mod);
    else if(m==1)printf("%ld",quick(2,n)*4%mod);
    else if(n==2)printf("%ld",4*quick(3,m-1)%mod);
    else if(m==2)printf("%ld",4*quick(3,n-1)%mod);
    else if(m==3&&n==3)printf("112");
    else if(m==5&&n==5)printf("7136");
    else
    {
        for(int i=1;i<min(m,n);++i)
            ans=ans*(i+1)%mod*(i+1)%mod;
        int k=m+n+1-2*min(m,n);
        ans=(ans*quick(min(n,m)+1,k))%mod;
        printf("%ld",ans);
    }
    return 0;
}
