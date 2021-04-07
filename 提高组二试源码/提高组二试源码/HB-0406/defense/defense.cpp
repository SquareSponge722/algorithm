#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
#include<ctime>
using namespace std;
const int N=100100;
struct node{
	int nu,ne;
}edge[N*2];
int head[N],tot,n,m;
long long dpt[N][2],f[N],w[N],dp[N][2];
int a1,c1;
bool flag;
map<int,int>f1,f2;
void add(int a,int b){
	edge[++tot].nu=b;
	edge[tot].ne=head[a];
	head[a]=tot;
}
void dfsinit(int u,int fa){
	f[u]=fa;
	for(int i=head[u];i!=-1;i=edge[i].ne){
		int v=edge[i].nu;
		if(v==fa)continue;
		flag=true;
		dfsinit(v,u);
		dp[u][0]+=dp[v][1];
		dp[u][1]+=min(dp[v][1],dp[v][0]);
	}
	dp[u][1]+=w[u];
}
void dfs(int u,int so,long long l1,long long l2){
	long long la1=dpt[u][1],la2=dpt[u][0];
	dpt[u][0]-=l1,dpt[u][0]+=dpt[so][1];
	dpt[u][1]-=min(l1,l2),dpt[u][1]+=min(dpt[so][1],dpt[so][0]);
	if(dpt[u][0]>=1e11&&dpt[u][1]>=1e11){
		flag=true;
		return;
	}
	if(u==1)return;
	dfs(f[u],u,la1,la2);
	if(flag)return;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	char s[4];
	scanf("%d%d%s",&n,&m,s+1);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfsinit(1,-1);
	for(int i=1;i<=m;i++){
		int b,d;
		scanf("%d%d%d%d",&a1,&b,&c1,&d);
		flag=false;
		memcpy(dpt,dp,sizeof(dp));
		long long tmp1=dpt[a1][1],tmp2=dpt[a1][0],tmp3=dpt[c1][1],tmp4=dpt[c1][0];
		if(s[2]==2){
			printf("-1\n");
			continue;
		}
		if(b==1) f1[a1]=true,dpt[a1][0]=1e11;
		else f2[a1]=true,dpt[a1][1]=1e11;
		if(d==1) f1[c1]=true,dpt[c1][0]=1e11;
		else f2[c1]=true,dpt[c1][1]=1e11;
		if(a1!=1)
			dfs(f[a1],a1,tmp1,tmp2);
		if(c1!=1){
			dfs(f[c1],c1,tmp3,tmp4);
		}
		if(min(dpt[1][1],dpt[1][0])>=1e10||flag)printf("-1\n");
		else printf("%lld\n",min(dpt[1][0],dpt[1][1]));
		f1[a1]=f2[a1]=f1[c1]=f2[c1]=false;
	}
	return 0;
}
