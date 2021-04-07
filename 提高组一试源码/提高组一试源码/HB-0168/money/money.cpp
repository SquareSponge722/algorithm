#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
bool dp[25005];
int a[105];
bool vis[105];
int main() {
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T --) {
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		int n;scanf("%d",&n);
		for(int i = 1;i <= n;i ++) {
			scanf("%d",a+i);
		}
		sort(a+1,a+n+1);
		int maxa = a[n];
		dp[0] = 1;
		for(int i = 1;i <= n;i ++) {
			for(int j = a[i];j <= maxa;j ++) {
				dp[j] = dp[j] || dp[j - a[i]];
			}
			for(int j = i + 1;j <= n;j ++) {
				if(dp[a[j]]) vis[j] = 1;
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++) if(vis[i]) ans ++;
		printf("%d\n",n - ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
