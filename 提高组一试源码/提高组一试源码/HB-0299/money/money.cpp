#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int t,n,a[110],ans,q[26000];
bool g[26000];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(g,0,sizeof(g));
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		g[0]=1;
		q[0]=0;
		q[++q[0]]=0;
		for(int i=1;i<=n;++i){
			if(!g[a[i]]){
				int t=q[0];
				for(int j=1;j<=t;++j){
					for(int k=0;q[j]+k*a[i]<=a[n];++k){
						int p=q[j]+k*a[i];
						if(g[p])continue;
						g[p]=1;
						q[++q[0]]=p;
					}
				}
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
