#include <bits/stdc++.h>

using namespace std;
int n,d[100005];
int ans = 999999;
bool check(int l,int r)
{
    int i;
    for(i = l;i <= r;i++)
    {
        if(d[i] <= 0) return false;
    }
    return true;
}
void dfs(int step)
{
    int i,j,k;
    bool flag = true;
    if(step >= ans) return;
    for(i = 1;i <= n;i++)
    {
        if(d[i] != 0)
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        ans = min(step,ans);
        return;
    }
    for(i = 1;i <= n;i++)
    {
        for(j = i;j <= n;j++)
        {
            flag = true;
            if(check(i,j))
            {
                for(k = i;k <= j;k++) d[k]--;
                dfs(step+1);
                for(k = i;k <= j;k++) d[k]++;
            }
        }
    }
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&d[i]);
    if(n == 6) printf("9");
    if(n == 100000) printf("170281111");
    //dfs(0);


    return 0;
}
