#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int i,a[n],b[n],l[n];
    for(i=1;i<n;i++)
        scanf("%d%d%d",&a[i],&b[i],&l[i]);
    sort(l+1,l+n);
    printf("%d",l[n-1]+l[n-1]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
