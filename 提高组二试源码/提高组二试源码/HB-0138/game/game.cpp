#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
using namespace std;
typedef long long LL;
const LL P=1e9+7;
LL n,m;
LL a[9][9]={
    {0,  0,   0,    0,    0,     0,     0,      0,      0},
    {0,  1,   4,    8,   16,    32,    64,    128,    256},
    {0,  4,  12,   36,  108,   324,   972,   2916,   8748},
    {0,  8,  36,  112,  336,  1008,  3024,   9072,  27216},
    {0, 16, 108,  336,  912,  2688,  8064,  24192,  72576},
    {0, 32, 324, 1008, 2688,  7136, 21408,  64224, 192672},
    {0, 64, 972, 3024, 8064, 21408, 64224, 192672, 578016},
    {0,128,2916, 9072,24192, 64224,192672, 578016,1734048},
    {0,256,8748,27216,72576,192672,578016,1734048,5202144},
};
inline LL read()
{
    LL re=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) re=(re<<3)+(re<<1)+ch-'0',ch=getchar();
    return re;
}
inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y)
    {
        if(y&1) ans=(ans*x)%P;
        y>>=1;
        x=(x*x)%P;
    }
    return ans;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read(),m=read();
    if(n<=8&&m<=8) printf("%lld",a[n][m]);
    else printf("%lld",a[n][8]*power(3,m-8)%P);
    return 0;
}
