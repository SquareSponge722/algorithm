#include<bits/stdc++.h>
using namespace std;
struct yuansu {
	int x,y;
} bian[200005];
long long int dp[100005][2],sum[100005],v[100005],n,m,x,xx,y,yy,dui[100005],b[100005],fa[100005];
string ss;
int cmp(yuansu a,yuansu b) {
	return a.x<b.x;
}
long long int dfs(int now,int zt) {
	if(dp[now][zt]!=-1)return dp[now][zt];
	if(zt==0) {
		long long int ans=0;
		for(int i=sum[now-1]+1; i<=sum[now]; i++)
			if(bian[i].y!=fa[now])
				ans+=dfs(bian[i].y,1);
		return dp[now][0]=ans;
	} else {
		long long int ans=v[now];
		for(int i=sum[now-1]+1; i<=sum[now]; i++)
			if(bian[i].y!=fa[now])
				ans+=min(dfs(bian[i].y,0),dfs(bian[i].y,1));
		return dp[now][1]=ans;
	}
}
void work1() {
	if(dp[1][1]>=1e15)
		if(dfs(1,0)<1e15)
			cout<<dfs(1,0)<<endl;
		else cout<<-1<<endl;
	else if(dp[1][0]>=1e15) {
		if(dfs(1,1)<1e15) {
			cout<<dfs(1,1)<<endl;
		} else cout<<-1<<endl;
	} else {
		if(min(dfs(1,1),dfs(1,0))>=1e15) {
			cout<<-1<<endl;
		} else cout<<min(dfs(1,1),dfs(1,0))<<endl;
	}
	return;
}
void bfs() {
	int head=1,tail=2;
	dui[1]=1;
	b[1]=1;
	while(head!=tail) {
		for(int i=sum[dui[head]-1]+1; i<=sum[dui[head]]; i++) {
			if(!b[bian[i].y]) {
				b[bian[i].y]=1;
				fa[bian[i].y]=dui[head];
				dui[tail]=bian[i].y;
				tail++;
			}
		}
		head++;
	}
	return;
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=1; i<=n; i++) {
		cin>>v[i];
	}
	for(int i=1; i<=n-1; i++) {
		cin>>bian[i].x>>bian[i].y;
		bian[i+n-1].x=bian[i].y;
		bian[i+n-1].y=bian[i].x;
	}
	sort(bian+1,bian+2*n-1,cmp);
	for(int i=1; i<=2*n-1; i++)
		if(bian[i].x!=bian[i+1].x)
			sum[bian[i].x]=i;
	bfs();
	for(int i=1; i<=m; i++) {
		for(int j=1;j<=n;j++)
		dp[j][0]=dp[j][1]=-1;
		for(int i=2; i<=n; i++)
			if(sum[i]-sum[i-1]==1)
				dp[i][0]=0,dp[i][1]=v[i];
		cin>>x>>xx>>y>>yy;
		if(xx==0) {
			dp[x][1]=1e15;
		} else dp[x][0]=1e15;
		if(yy==0)dp[y][1]=1e15;
		else dp[y][0]=1e15;
//		if(n<=3000) {
		work1();
//		} else work2();
	}
	return 0;
}
