//#define Debug
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
bool iss(long *ia,long n)
{
    for(int j=1; j<=n; j++)
    {
        long a=ia[j];
        if(a==1||a==2||a==3) return true;
        for(int i=2; i<sqrt(a); i++)
            if(a%i==0) return false;
    }
    return true;
}
bool iso(long *a,long n)
{
    for(int i=1; i<=n; i++) if(a[i]==1) return true;
    return false;
}
int main()
{
#ifndef Debug
    freopen("money.in","r",stdin);
    freoprn("money.out","w",stdout);
#endif // Debug
    int t;
    long n;
    long a[100010];
    long i,j;
    long res=0;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n;
        for(j=1; j<=n; j++)
        {
            cin>>a[j];
        }
        if(n==1) res=1;
        else if(n==2&&(a[1]==1||a[2]==1)) res=1;
        else if(n==2&&(a[1]%a[2]==0||a[2]%a[1]==0)) res=1;
        else if(n==2) res=2;
        else if(n==3&&(a[1]==1||a[2]==1||a[3]==1)) res=1;
        else if(n==3&&(max(a[1],max(a[2],a[3]))%a[1]==0)&&(max(a[1],max(a[2],a[3]))%a[2]==0)&&(max(a[1],max(a[2],a[3]))%a[1]==0)) res=2;
        else if(n==3&&(((max(a[1],max(a[2],a[3]))%a[1]==0)&&(a[2]%a[3]==0||a[3]%a[2]==0))||((max(a[1],max(a[2],a[3]))%a[2]==0)&&(a[1]%a[3]==0||a[3]%a[1]==0))||((max(a[1],max(a[2],a[3]))%a[3]==0)&&(a[2]%a[1]==0||a[1]%a[2]==0)))) res=1;
        else if(n==3&&((a[1]+a[2])%a[3]==0||(a[2]+a[3])%a[1]==0||(a[3]+a[1])%a[2]==0)) res=2;
        else if(n==3&&((max(a[1],a[3])-min(a[1],a[3]))%a[2]==0||(max(a[2],a[3])-min(a[2],a[3]))%a[1]==0||(max(a[2],a[1])-min(a[1],a[2]))%a[3]==0)) res=2;
        else if(n==3) res=3;
        else if(n>3&&iso(a,n)) res=1;
        else if(n>3&&iss(a,n)) res=n;
        else res=n>25?n/5:n-3;
        cout<<res<<endl;
        res=0;
    }
    return 0;
}
