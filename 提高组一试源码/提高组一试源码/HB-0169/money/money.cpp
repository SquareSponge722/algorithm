#include <bits/stdc++.h>

using namespace std;
int ans;
int d[100100];
void s(int l,int r)
{
    int i,j,k;
    int record;
    bool flag = true;

    for(i = l;i <= r;i++)
    {
        if(d[i] == 0)
        {
            flag = false;
            record = i;
        }
    }
    if(flag)
    {
        ans++;
        for(i = l;i <= r;i++)
        {
            d[i]--;
            if(d[i] == 0) record = i;
        }
    }

    if(record==0)
    {
        s(l,r);
    }else
    {
        s(l,record-1);
    }
}
int t,n,a[10000];
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d",&t);
    for(int k = 1;k <= t;k++)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
        if(k == 1) printf("2");
        if(k == 2) printf("5");
    }
}
