#include<cstdio>
#include<algorithm>
using namespace std;
int g[260][2],n,m;
const int mod=1e9+7;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int j=0;j<(1<<n);++j) g[j][1]=1;
	for(register int i=2;i<=m;++i)
		for(register int j=0;j<(1<<n);++j)
			for(register int k=1;k<n;++k){
				if((1<<k)&j)  for(register int l=k;l<n;++l) g[j][i&1]=(g[(j|(1<<k)|(1<<(k-1))|(1<<l))+(1<<l)][(i-1)&1]+g[(l|(1<<k)|(1<<(k-1)|(1<<l))+(1<<l))-(1<<k)][(i-1)&1])%mod;
				else for(register int l=k;l<n;++l)g[j][i&1]=(g[(j|(1<<k)|(1<<(k-1)))+(1<<l)][(i-1)&1]+g[(j|(1<<k)|(1<<(k-1)))-(1<<k)+(1<<l)][(i-1)&1]+
							  	g[(j|(1<<k)|(1<<(k-1))|(1<<l))-(1<<k)-(1<<(k-1))+(1<<l)][(i-1)&1]+g[(j|(1<<k)|(1<<(k-1))|(1<<l))-(1<<(k-1))+(1<<l)][(i-1)&1])%mod;
			}
	int ans=0;
	for(register int j=0;j<(1<<n);++j) ans=(ans+g[j][m&1])%mod;
	printf("%d\n",ans%mod);
	return 0;
}
