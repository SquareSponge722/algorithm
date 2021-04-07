#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char type[5];
int n,m,p[100005],fa[100005],total;
int head[100005],next[200005],ver[200005];
long long dp[100005][2];
int a,x,b,y;
inline void add(int f,int t){
	ver[++total]=t;
	next[total]=head[f];
	head[f]=total;
}
void dfs1(int point){
	for(int i=head[point];i;i=next[i]){
		if(fa[point]!=ver[i]){
			fa[ver[i]]=point;
			dfs1(ver[i]);
		}
	}
}
void dfs2(int point){
	bool have=false;
	for(int i=head[point];i;i=next[i]){
		if(fa[point]!=ver[i]){
			dfs2(ver[i]);
			dp[point][0]+=dp[ver[i]][1];
			if(dp[ver[i]][1]==-1){have=true;dp[point][1]+=dp[ver[i]][0];}
			else if(dp[ver[i]][0]==-1)dp[point][1]+=dp[ver[i]][1];
			else dp[point][1]+=min(dp[ver[i]][1],dp[ver[i]][0]);
		}
	}
	if(have)dp[point][0]=-1;
	if(point==a&&x==1)dp[point][0]=-1;
	else if(point==b&&y==1)dp[point][0]=-1;
	dp[point][1]+=p[point];
	if(point==a&&x==0)dp[point][1]=-1;
	else if(point==b&&y==0)dp[point][1]=-1;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,type);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<n;i++){
		int f,t;
		scanf("%d%d",&f,&t);
		add(f,t);add(t,f);
	}
	dfs1(1);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(dp,0,sizeof(dp));
		if(x==0&&y==0&&(a==fa[b]||b==fa[a])){printf("-1\n");continue;}
		dfs2(1);
		if(a==1)printf("%lld\n",dp[1][x]);
		else if(b==1)printf("%lld\n",dp[1][y]);
		else if(dp[1][0]==-1)printf("%lld\n",dp[1][1]);
		else if(dp[1][1]==-1)printf("%lld\n",dp[1][0]);
		else printf("%lld\n",min(dp[1][0],dp[1][1]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}