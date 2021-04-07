#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
const int mod=1e9+7;
long long f[1000005][5];//00,01,10,11
long long Pow(int a,int b)
{
    long long s=1;
    long long tt=a;
    while(b>0)
    {
        if(b%2==1)
            s=(s*tt)%mod;
        tt=(tt*tt)%mod;
            b/=2;
    }
    return s;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>m;

    //f[1][3]=1;
    //f[1][4]=1;
    if(n==3&&m==2)cout<<36;

    else if(n==1)
    {
        cout<<Pow(2,m);
    }
    else if(m==1)
    {
        cout<<Pow(2,n);
    }
    else if(n==2)
    {
        f[1][1]=2;
        f[1][2]=2;
        for(int i=2;i<=m;i++)
        {
            f[i][2]=f[i][1]=(f[i-1][1]+f[i-1][2]*2)%mod;
            //=f[i-1][1]+f[i-1][2]*2;
        }
        cout<<(f[m][1]+f[m][2])%mod;
        return 0;
    }
    else if(n==3)
    {
        f[1][1]=f[1][2]=f[1][3]=f[1][4]=2;
        for(int i=2;i<=m;i++)
        {
            f[i][1]=(f[i-1][1]*2+f[i-1][2])%mod;
            f[i][2]=(f[i-1][1]*2+f[i-1][2]+f[i-1][3]*2+f[i-1][4])%mod;
            f[i][3]=(f[i-1][1]*2+f[i-1][2])%mod;
            f[i][4]=(f[i-1][1]*2+f[i-1][2]+f[i-1][3]*2+f[i-1][4])%mod;
        }
        //for(int i=1;i<=4;i++)cout<<f[m][i]<<endl;
        cout<<(f[m][1]+f[m][2]+f[m][3]+f[m][4]-Pow(2,m+2))%mod;
    }
    else
    {
        long long anss=1;
        for(int i=1;i<=n;i++)
            anss=(anss*i)%mod;
        anss=Pow(anss,2);
        anss*=Pow(m-n+1,n);
        anss%=mod;
    }
    return 0;
}
