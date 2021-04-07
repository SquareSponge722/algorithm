#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int u[m],v[m];
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d ",u[i],v[i]);
        i++;
    }
    return 0;
}
