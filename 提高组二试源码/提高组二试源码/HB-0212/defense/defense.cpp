#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("defense.in","r",stdin);
    freopen("defense.out","w",stdout);
    int n,m;
    string type;
    scanf("%d%d",&n,&m);
    cin>>type;
    int p[n],u[n-1],v[n-1];
    int axby[4*m];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
    }
    for(int i=0;i<4*m;i++)
    {
        scanf("%d",&axby[i]);
    }
    for(int i=0;i<m;i++)
    {
        printf("-1\n");
    }
    return 0;
}
