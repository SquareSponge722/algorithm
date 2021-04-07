#include<cstdio>
#include<iostream>
using namespace std;
int n,d[100001];
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&d[i]);
    for(int i=1;i<=n;++i)if(d[i]>d[i-1])ans+=d[i]-d[i-1];
    printf("%ld",ans);
    return 0;
}
