#include<bits/stdc++.h>
#define Side(x) for(int i=p[x];i;i=nt[i])
using namespace std;
const int N=100020,M=200020;
const long long INF=1LL<<61;
int n,m,c[N],tot,e[M],nt[M],p[N],tsize[N],depth[N],son[N],pre[N],clc,dfn[N],bel[N];
long long dp[N][2];
void _add(int x,int y){e[++tot]=y,nt[tot]=p[x],p[x]=tot;}
inline void add(int x,int y){
//cerr<<x<<' '<<y<<endl;
_add(x,y),_add(y,x);
}
void dfs(int x)
{
	tsize[x]=1,dp[x][1]=c[x];
	Side(x)
	{
		if(depth[e[i]])continue;
		depth[e[i]]=depth[x]+1,pre[e[i]]=x;
		dfs(e[i]);
		dp[x][0]+=dp[e[i]][1];
		dp[x][1]+=min(dp[e[i]][0],dp[e[i]][1]);
		son[x]=tsize[son[x]]>tsize[e[i]]?son[x]:e[i];
		tsize[x]+=tsize[e[i]];
	}
}
void dfs1(int x,int anc)
{
	dfn[x]=++clc,bel[x]=anc;
	if(son[x])dfs1(son[x],anc);
	Side(x)
	{
		if(dfn[e[i]])continue;
		dfs1(e[i],e[i]);
	}
}
struct BIT
{
	long long t[N];
	inline int lowbit(int x){return x&(-x);}
	void add(int x,long long v)
	{
		while(x<=n)
			t[x]+=v,x+=lowbit(x);
	}
	long long sum(int x)
	{
		long long rt=0;
		while(x)rt+=t[x],x-=lowbit(x);
		return rt;
	}
	long long get(int x)
	{
		return sum(x);
	}
	inline void update(int x,int y,long long v){add(x,v),add(y+1,-v);}
	void pathModify(int x,long long v)
	{
		//cerr<<"modifying path from "<<x<<" to 1"<<"------------"<<endl;
		//if(x==1)
		//	cerr<<"here"<<endl;
		while(x)
		{
		//	cerr<<"now"<<x<<endl;
 			update(dfn[bel[x]],dfn[x],v);
			x=pre[bel[x]];
		}
	}
}T[2];
void ddfs(int x)
{
	if(dp[x][1]<INF)dp[x][1]=c[x];
	if(dp[x][0]<INF)dp[x][0]=0;
	Side(x)
	{
		if(e[i]==pre[x])continue;
		ddfs(e[i]);
		if(dp[x][0]<INF)dp[x][0]+=dp[e[i]][1];
		if(dp[x][1]<INF)dp[x][1]+=min(dp[e[i]][0],dp[e[i]][1]);
	}
}
void solve1()
{
	for(int i=1,ai,xi,bi,yi;i<=m;i++)
	{
		scanf("%d%d%d%d",&ai,&xi,&bi,&yi);
		if(depth[ai]>depth[bi])swap(ai,bi),swap(xi,yi);
		if(pre[bi]==ai&&!xi&&!yi)
		{
			printf("-1\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		dp[ai][xi^1]=dp[bi][yi^1]=INF;
		ddfs(1);
		printf("%lld\n",min(dp[1][0],dp[1][1]));
		//dp[ai][xi^1]=dp[bi][yi^1]=0;
	}
}
void print()
{
	for(int j=1;j<=n;j++)
	{
		cerr<<"After changing"<<endl;
		printf("%d:%lld %lld\n%lld %lld\n\n",j,dp[j][0],dp[j][1],T[0].get(dfn[j]),T[1].get(dfn[j]));
	}
}
void change(int x,int b,long long flag)
{
	if(b==0)
	{
		T[1].update(dfn[x],dfn[x],flag*INF);
		long long va=dp[x][0]-min(dp[x][0],dp[x][1]);
		x=pre[x];
		if(!x)return;
		T[1].pathModify(x,va*flag);
		T[0].pathModify(pre[x],va*flag);
	}
	else
	{
		long long	dltfx1=dp[x][1]-min(dp[x][0],dp[x][1]),
					newfx1=dp[pre[x]][1]+dltfx1,
					dltgf1=min(dp[pre[x]][0],newfx1)-min(dp[pre[x]][1],dp[pre[x]][0]),
					dltggf1=min(dltfx1,dltgf1);
		T[0].update(dfn[x],dfn[x],flag*INF);
		x=pre[x];
		if(!x)return;
		T[1].update(dfn[x],dfn[x],dltfx1*flag);
		x=pre[x];
		if(!x)return;
		T[0].update(dfn[x],dfn[x],dltfx1*flag);
		T[1].update(dfn[x],dfn[x],dltgf1*flag);
		x=pre[x];
		if(!x)return;
		T[0].update(dfn[x],dfn[x],dltgf1*flag);
		T[1].pathModify(x,dltggf1*flag);
		x=pre[x];
		if(!x)return;
		T[0].pathModify(x,dltggf1*flag);
	}
}
char type[20];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,type);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1,ui,vi;i<n;i++)
 		scanf("%d%d",&ui,&vi),add(ui,vi);
	if((long long)n*m<=4e8)
	{
		depth[1]=1;
		dfs(1);
		solve1();
		return 0;
	}
	depth[1]=1;
	dfs(1);
	dfs1(1,1);
	for(int i=1;i<=n;i++)
		T[1].update(dfn[i],dfn[i],dp[i][1]),T[0].update(dfn[i],dfn[i],dp[i][0]);
	//for(int i=1;i<=n;i++)
	//{
	//	printf("%d %d\n%d %d\n\n",dp[i][0],dp[i][1],T[0].get(dfn[i]),T[1].get(dfn[i]));
	//}
	for(int i=1,ai,xi,bi,yi;i<=m;i++)
	{
		scanf("%d%d%d%d",&ai,&xi,&bi,&yi);
		if(depth[ai]>depth[bi])swap(ai,bi),swap(xi,yi);
		if(pre[bi]==ai&&!xi&&!yi)
		{
			printf("-1\n");
			continue;
		}
		change(ai,xi,1);
		//print();
		change(bi,yi,1);
		//cerr<<"A="<<ai<<"B="<<bi<<endl;
		//print();
		printf("%d\n",min(T[0].get(dfn[1]),T[1].get(dfn[1])));
		change(ai,xi,-1);
		change(bi,yi,-1);
	}
}
