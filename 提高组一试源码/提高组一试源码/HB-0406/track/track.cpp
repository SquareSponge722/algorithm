#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int N=50100;
struct node{
	int nu,v,ne;
}edge[N*2];
int head[N],tot,n,m;
long long maxn1[N],maxn2[N];//m=1
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return w*s;
}
int be,ed,cnt;
long long sum;
struct node2{
	int a,b;
	long long v;
	bool operator<(const node2&other)const{
	return v<other.v;}
};
priority_queue<node2>q;//b=a+1
long long ans;
int mp[N],g[1010][1010];
map<int,bool>mp2[N];
void add(int a,int b,int c){
	edge[++tot].nu=b;
	edge[tot].ne=head[a];
	edge[tot].v=c;
	head[a]=tot;
}
bool cmp(int a,int b){
	return b>a;
}
void dfs1(int u,int fa){
	int maxn1p=u;
	for(int i=head[u];i!=-1;i=edge[i].ne){
		int v=edge[i].nu;
		if(v==fa)continue;
		dfs1(v,u);
		if(edge[i].v+maxn1[v]>maxn1[u]){
			maxn1[u]=maxn1[v]+edge[i].v;
			maxn1p=v;
		}
	} 
	for(int i=head[u];i!=-1;i=edge[i].ne){
		int v=edge[i].nu;
		if(v==fa||v==maxn1p)continue;
		maxn2[u]=max(maxn2[u],maxn1[v]+edge[i].v);
	}
	ans=max(ans,(long long)maxn1[u]*(1ll)+maxn2[u]);
}
void solve1(){//Ê÷µÄÖ±¾¶
	dfs1(1,-1);
	printf("%lld\n",ans);
}
void solve2(){//b=a+1 
	be=1,ed=2;
	q.push((node2){1,n,sum});
	mp2[1][n]=true;
	for(int i=n-1;i>1;i--){
		q.push((node2){be,i,sum-mp[i]});
		sum-=mp[i];
		mp2[1][i]=true;
	}
	int ct=0;
	while(!q.empty()){
		node2 a=q.top();
		q.pop();
		ct++;
		if(ct==m){
			printf("%lld\n",a.v);
			return ;
		}
		if(a.a+1<a.b&&!mp2[a.a+1][a.b])q.push((node2){a.a+1,a.b,a.v-mp[a.a]}),mp2[a.a+1][a.b]=true;
		if(a.b-1>a.a&&!mp2[a.a][a.b-1])q.push((node2){a.a,a.b-1,a.v-mp[a.b]}),mp2[a.a][a.b-1]=true;
	}
}
void dfs2(int u,int fa){
	for(int i=head[u];i!=-1;i=edge[i].ne){
		int v=edge[i].nu;
		if(v==fa)continue;
		g[u][v]=g[v][u]=-1;
		dfs2(v,u);
	}
}
void solve3(){
	dfs2(1,-1);
	int pp[N];
	memset(g,0x3f,sizeof(g)); 
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
				pp[++pp[0]]=g[i][j];
	sort(pp+1,pp+1+pp[0],cmp);
		printf("%d\n",pp[m]);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(head,-1,sizeof(head));
	bool flag2=true; 
	n=read(),m=read();
	for(int i=1;i<n;i++){
		int a,b,c;
		a=read(),b=read(),c=read();
		sum+=c;
		mp[a]=c;
		if(b!=a+1)flag2=false;
		add(a,b,c);
		add(b,a,c);
	}
	if(!flag2&&m==1){
		solve1();
		return 0;
	}
	if(flag2){
		solve2();
		return 0;
	}
	else {
		solve3();
		return 0;
	}
	return 0;
}
