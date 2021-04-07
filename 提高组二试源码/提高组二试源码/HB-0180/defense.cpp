#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 100010
#define INF 999999999999
#include<vector>
#define LL long long
#include<algorithm>
using namespace std;
vector<int> E[MAXN];
int n,m,lima,limb,cana,canb;
LL dp[MAXN][2],v[MAXN];
char s[5];
void DP(int now,int last){
	dp[now][1]=v[now],dp[now][0]=0;
	if(now==lima){
		if(cana) dp[now][0]=(LL)INF;
		else dp[now][1]=(LL)INF;
	}
	if(now==limb){
		if(canb) dp[now][0]=(LL)INF;
		else dp[now][1]=(LL)INF;
	}
	for(int i=0;i<E[now].size();i++){
		if(E[now][i]!=last){
			DP(E[now][i],now);
			if(dp[now][1]<INF) dp[now][1]+=min(dp[E[now][i]][0],dp[E[now][i]][1]);
			if(dp[now][0]<INF) dp[now][0]+=dp[E[now][i]][1];
		}
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) scanf("%lld",&v[i]);
	for(int i=1;i<=n-1;i++){
		int x,y; scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i=1;i<=m;i++){
		int a,x,b,y; scanf("%d%d%d%d",&a,&x,&b,&y);
		lima=a,limb=b,cana=x,canb=y;
		DP(1,0);
		if(min(dp[1][0],dp[1][1])>=(LL)INF) printf("%d\n",-1);
		else printf("%lld\n",min(dp[1][0],dp[1][1]));
	}
	return 0;
}
