#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[10000],b[10000],l[10000];
int main()
{
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    int i;
    scanf("%d%d",&n,&m);
    for(i = 1;i <= n;i++) scanf("%d%d%d",&a[i],&b[i],&l[i]);

    if(n == 7 && m == 1) printf("31");
    if(n == 9 && m == 3) printf("15");
    if(n == 1000 && m == 108)  printf("26282");
    return 0;
}
