#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f
using namespace std;
int n,m,x,y,a,b,ans;
long long dp[100010][5],p[100010];
vector<int>v[100010];
char cha,chb;
void dfs(int now,int f) {
	for(int i=0; i<v[now].size(); i++)
		if(v[now][i]!=f)dfs(v[now][i],now);
	if(now==x) {
		if(a==1) {
			dp[now][1]=p[now];
			dp[now][0]=inf;
			for(int i=0; i<v[now].size(); i++)
				if(v[now][i]!=f)
					dp[now][1]+=min(dp[v[now][i]][1],dp[v[now][i]][0]);
		}
		if(a==0) {
			dp[now][1]=inf;
			dp[now][0]=0;
			for(int i=0; i<v[now].size(); i++)
				if(v[now][i]!=f)
					dp[now][0]+=dp[v[now][i]][1];
		}
	} else 	if(now==y) {
		if(b==1) {
			dp[now][1]=p[now];
			dp[now][0]=inf;
			for(int i=0; i<v[now].size(); i++)
				if(v[now][i]!=f)
					dp[now][1]+=min(dp[v[now][i]][1],dp[v[now][i]][0]);
		}
		if(b==0) {
			dp[now][1]=inf;
			dp[now][0]=0;
			for(int i=0; i<v[now].size(); i++)
				if(v[now][i]!=f)
					dp[now][0]+=dp[v[now][i]][1];
		}
	} else {
		dp[now][1]=p[now];
		dp[now][0]=0;
		for(int i=0; i<v[now].size(); i++)
			if(v[now][i]!=f)dp[now][1]+=min(dp[v[now][i]][1],dp[v[now][i]][0]);
		for(int i=0; i<v[now].size(); i++)
			if(v[now][i]!=f)dp[now][0]+=dp[v[now][i]][1];
	}
	return ;
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>cha>>chb;
	for(int i=1; i<=n; i++)
		scanf("%lld",&p[i]);
	for(int i=1; i<n; i++) {
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int T=1; T<=m; T++) {
		scanf("%d%d%d%d",&x,&a,&y,&b);
		bool ok=0;
		if(a==0&&b==0)for(int i=0; i<v[x].size(); i++)
				if(v[x][i]==y) {
					printf("-1\n");
					ok=1;
					break;
				}
		if(ok==1)continue;
		for(int i=1; i<=n; i++)dp[i][0]=dp[i][1]=inf;
		dfs(1,0);
		if(x==1)printf("%lld\n",dp[1][a]);
		else if(y==1)printf("%lld\n",dp[1][b]);
		else printf("%lld\n",min(dp[1][0],dp[1][1]));
	}
	return 0;
}
