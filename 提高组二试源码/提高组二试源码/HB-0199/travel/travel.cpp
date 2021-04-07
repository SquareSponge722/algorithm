#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[6000],ww[6001],d[6001],ans[10001];
int l,xx,yy;
int jk,ll,inq[6000],we[6000];
bool p[6001];
vector<int>head[6000];
struct node{
	friend bool operator < (node aa,node bb){
		if(aa.dc==bb.dc)return aa.poi<bb.poi;
		return aa.dc<bb.dc;
	}
	int poi,dc;
}a[6000];
void dfs(int u){
inq[u]=1;ll=head[u].size();
for(int i=0;i<head[u].size();i++)we[head[u][i]]=1;
for(int i=2;i<=n;i++){
if(we[a[i].poi]){
	if(a[i].dc>dp[u]&&!inq[a[i].poi]){
		ans[++l]=a[i].poi;
		dfs(a[i].poi);
		}
}
}
for(int i=0;i<head[u].size();i++)we[head[u][i]]=0;
}
void ff(int u,int dep){
	jk=max(jk,dep);
	dp[u]=dep;
	for(int i=0;i<head[u].size();i++){
		int v=head[u][i];
		if(!dp[v])ff(v,dep+1);
	}
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
jk=-1;
cin>>n>>m;
for(int i=1;i<=m;i++){
	scanf("%d%d",&xx,&yy);
	head[xx].push_back(yy);
	head[yy].push_back(xx);
}
ff(1,1);
for(int i=1;i<=n;i++){
	a[i].poi=i;
	a[i].dc=dp[i];
}
sort(1+a,a+1+n);
l=1;ans[1]=1;
inq[1]=1;
for(int i=0;i<head[1].size();i++){
	int v=head[1][i];
	ans[++l]=v;
	dfs(v);
}
for(int i=1;i<=l;i++)cout<<ans[i]<<" ";
	return 0;
}
