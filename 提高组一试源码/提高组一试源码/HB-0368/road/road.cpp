#include <cstdio>
const int N=1e5+10;
int ans,n,a,las;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a<las) ans+=las-a;
        las=a;
    }
    ans+=las;
    printf("%d\n",ans);
    return 0;
}
