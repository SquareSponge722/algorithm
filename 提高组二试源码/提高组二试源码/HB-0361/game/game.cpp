#include <cstdio>
#include <iostream>
#include <algorithm>
#define mod 1000000007
typedef long long ll;
using namespace std;
int n,m;
int main(){
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
scanf("%d%d",&n,&m);
int minv=min(n,m);
int maxv=max(n,m);
ll djx=(ll)((minv+1)*(maxv-minv+1))%mod;
for(int i=0;i<=minv-2;i++){djx*=(ll)(minv-i)*(minv-i)%mod;
}
printf("%lld",djx);
return 0;
}
