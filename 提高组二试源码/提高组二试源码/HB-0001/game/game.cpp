#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define N 1e9+7
using namespace std;
int n,m;
long long ans=1;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+m-2;i++)
	  ans*=2;
	ans*=(long long)(n*m-2);
	ans%=(long long)N;
	if(n==1||m==1)
	  printf("0");
	else 
	  printf("%lld",ans);
	return 0;
}
