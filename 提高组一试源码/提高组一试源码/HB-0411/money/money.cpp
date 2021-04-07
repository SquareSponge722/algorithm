#include <bits/stdc++.h>
#define N 300
#define M 30000
using namespace std;
bool vis[N],flag;
int dp[M],b[M],tot;
int t,n,a[N],ans;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		if(a[1]==1){
			printf("1\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		ans=n;
		tot=1;
		dp[0]=true;
		for(int i=1;i<=n;i++){
			if(dp[a[i]]){
				ans--;
			}
			else{
				for(int j=1;j<=tot;j++){
					for(int k=1;k*a[i]+b[j]<=25000;k++){
						int x=k*a[i]+b[j];
						if(dp[x]==i){
							break;
						}
						else{
							if(dp[x]==0)
								b[++tot]=x;
							dp[x]=i;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

