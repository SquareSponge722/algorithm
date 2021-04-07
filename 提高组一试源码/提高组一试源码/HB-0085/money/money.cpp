#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 110;
int T,n,a[maxn],maxx,tong[25010],Time,ans;

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        maxx = 0;
        ++Time;
        ans = 0;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            maxx = max(maxx,a[i]);
        }
        tong[0] = Time;
        sort(a + 1,a + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            int temp = a[i];
            if (tong[temp] != Time)
            {
                ans++;
                for (int j = temp; j <= maxx; j++)
                    if (tong[j - temp] == Time)
                        tong[j] = Time;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
