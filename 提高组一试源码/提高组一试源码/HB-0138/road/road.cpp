#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
using namespace std;
typedef long long LL;
const LL MAXN=1e5+5;
LL n,d[MAXN],f[MAXN];
inline LL read()
{
    LL re=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) re=(re<<3)+(re<<1)+ch-'0',ch=getchar();
    return re;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    for(register LL i=1;i<=n;i++) d[i]=read();
    f[1]=d[1];
    for(register LL i=2;i<=n;i++)
    {
    	if(d[i]<=d[i-1]) f[i]=f[i-1];
    	else f[i]=f[i-1]+d[i]-d[i-1];
	}
	printf("%lld",f[n]);
    return 0;
}
