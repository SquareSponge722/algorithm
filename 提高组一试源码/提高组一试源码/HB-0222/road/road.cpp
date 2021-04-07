#include<bits/stdc++.h>
//#define DEBUG
using namespace std;
const int maxn=100000+10;
long long ans;//sum(1,10000),maybe boom
int n;//<=100000,no boom int
int d[maxn];
int now=0;//<=10000,no boom int
int main()
{
    #ifndef DEBUG
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",d+i);
    for(int i=1;i<=n;i++)
    {
        if(now<*(d+i))ans+=*(d+i)-now;
        now=*(d+i);
    }
    printf("%lld",ans);
}
