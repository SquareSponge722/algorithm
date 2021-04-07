#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int n,m;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	int ss=pow(2,m-2)+pow(2,n-2);
	ss/=2;
	int ans=0;
	for(int i=1;i<=ss;++i){
		ans+=i;
		ans%=100000007;
	}
	int aa=pow(2,m*n-1)+pow(2,m*n-3)*(m+n-3)*(m+n-2);
	aa%=100000007;
	printf("%d",aa*ans%100000007);
}
