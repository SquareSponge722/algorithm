#include<cstdio>
#include<cstring>
#define N 100010
#define INF 99999999999999
struct Edge{int to,next;}e[N<<1];
int first[N],p[N];
long long f[N][2];int a,x,b,y;
int mmin(int a,int b){return a<b?a:b;}
void dp(int u,int fa)
{
	int k=first[u];
	if(!k){f[u][1]=p[u];return;}
	while(k)
	{
		int v=e[k].to;k=e[k].next;
		if(v==fa)continue;
		dp(v,u);
		f[u][1]+=v==b?f[v][y]:mmin(f[v][0],f[v][1]);
		f[u][0]+=v==b&&y==0?INF:f[v][1];
	}
	f[u][1]+=p[u];
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,i;char type[10];
	scanf("%d%d %s",&n,&m,type);
	for(i=1;i<=n;i++)scanf("%d",&p[i]);
	int u,v;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[i]=(Edge){v,first[u]};first[u]=i;
		e[i+n]=(Edge){u,first[v]};first[v]=i+n;
	}
	while(m--)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		memset(f,0,sizeof(f));
		dp(a,0);
		printf("%lld\n",f[a][x]>=INF?-1:f[a][x]);
	}
	return 0;
}
