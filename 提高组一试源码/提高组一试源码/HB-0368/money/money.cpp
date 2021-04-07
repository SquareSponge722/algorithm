#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=102;
const int M=25010;
int n,a[N],dp[M];
void work()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    std::sort(a+1,a+1+n);
    int ans=0;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        ans+=dp[a[i]]==0;
        for(int j=a[i];j<=a[n];j++)
            dp[j]|=dp[j-a[i]];
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
        work();
    return 0;
}