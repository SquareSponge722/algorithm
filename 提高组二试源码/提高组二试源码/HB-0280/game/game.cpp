#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll P=1e9+7;
int n,m; ll ans=1;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m<n) swap(n,m);
	for(int i=1;i<=n;i++) ans=(ans*(i+1))%P;
	for(int i=1;i<=m-n;i++) ans=(ans*(n+1))%P;
	for(int i=n-1;i>=1;i--) ans=(ans*(i+1))%P;
	printf("%lld\n",ans);
	return 0;
}
