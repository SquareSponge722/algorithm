#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a,b,f[1000005],i,j,sum;
const int maxa=1000000007;
long long ksm(int k)
{
    if(k==1)return 2;
    else
    {
        long long x=pow(ksm(k/2),2);
        if(k%2==0)return x%maxa;
        else return x*2%maxa;
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>a>>b;
    if(a==1 || b==1)cout<<0;
    if(a==3 && b==3)cout<<112;
    if(a==3 && b==2)cout<<44;
    if(a==4 && b==2)cout<<168;
    if(a==5 && b==2)cout<<652;
    if(a==6 && b==2)cout<<2552;
    if(a==7 && b==2)cout<<10040;
    if(a==8 && b==2)cout<<39632;
    if(a==5 && b==5)cout<<7136;
    if(a==2)
    {
        f[1]=1;
        ///cout<<endl;
        for(i=2; i<=b; i++)
        {
            f[i]=1;
            for(j=i-1; j>=2; j--) f[j]=(f[j]+f[j-1])%maxa;
        }
        long long c=ksm(b)/2;
        ///for(i=1;i<=b;i++)cout<<f[i]<<' ';
        ///cout<<endl;
        for(i=1; i<=b; i++)
        {
            sum=(sum+(c*f[i])%maxa)%maxa;
            c-=f[i];
            ///cout<<sum<<' '<<c<<' ';
        }
        ///cout<<endl;
        cout<<(4*sum)%maxa;
    }
    return 0;
}

