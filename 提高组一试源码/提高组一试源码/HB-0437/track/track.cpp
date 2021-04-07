#include<bits/stdc++.h>
#define Side(x) for(int i=p[x];i;i=nt[i])
using namespace std;
const int N=10020,M=20020;
int tot,e[M],nt[M],w[M],p[N],ind[N];
void _add(int x,int y,int z){e[++tot]=y,nt[tot]=p[x],w[tot]=z,p[x]=tot,ind[y]++;}
void add(int x,int y,int z){_add(x,y,z),_add(y,x,z);}
int n,m,mi,sum,ans,f[N],g[N];
void dfs(int x,int fr,int lim)
{
	f[x]=g[x]=0;
	vector<int>vct;
	 Side(x)
	 {
	 	if(e[i]==fr)continue;
	 	dfs(e[i],x,lim);
	 	vct.push_back(g[e[i]]+w[i]);
	 	f[x]+=f[e[i]];
	 }
	 sort(vct.begin(),vct.end());
	 for(int i=0,k;i<vct.size();i++)
	 {
	 	k=lower_bound(vct.begin()+i+1,vct.end(),lim-vct[i])-vct.begin();
	 	//cerr<<"find"<<vct[i]<<"("<<lim-vct[i]<<")in"<<x<<':'<<k<<"="<<vct[k]<<endl;
	 	if(k>=vct.size())
		{
			if(vct[i]>g[x])
			{
				f[x]+=g[x]>=lim;
				g[x]=vct[i];
			}
		}
	 	else {
	 		vct.erase(vct.begin()+k);
	 		f[x]++;
	 	}
	 }
}
bool chk(int x)
{
	dfs(1,0,x);
	f[1]+=g[1]>=x;
	if(f[1]>=m)return true;
	return false;
}
int st,mx;
void dfs1(int x,int fr,int d)
{
	if(d>mx)
	{
		mx=d;
		st=x;
	}	
	Side(x)
	{
		if(e[i]==fr)continue;
		dfs1(e[i],x,d+w[i]);
	}	
}
const int N1=110;
int dp[N1][N1*10010];
int dfs2(int x,int fr,int lim)
{
	int rt=0,cnt=0,to[2],l[2],d[2];
	Side(x)
	{
		if(e[i]==fr)continue;
		rt=max((d[cnt]=dfs2(e[i],x,lim))+w[i],rt);
		l[cnt]=w[i],to[cnt++]=e[i];
	}
	if(cnt==1)
	{
		for(int i=l[0];i<=rt;i++)
		{
			dp[x][0]=max(dp[x][0],dp[to[0]][i-l[0]]+(bool)(i>=lim));
			dp[x][i]=max(dp[x][i],dp[to[0]][i-l[0]]);
		}
	}
	else if(cnt==2)
	{
		for(int i=0;i<=d[0];i++)
			for(int j=0;j<=d[1];j++)
				dp[x][0]=max(dp[x][0],dp[to[0]][i]+dp[to[1]][j]+(bool)((l[0]+l[1]+i+j)>=lim));
		g[x]=dp[x][0];
		for(int i=1;i<=rt;i++)
		{
			if(i>=l[0]&&i<=l[0]+d[0])dp[x][i]=max(dp[x][i],dp[to[0]][i-l[0]]+g[to[1]]);
			if(i>=l[1]&&i<=l[1]+d[1])dp[x][i]=max(dp[x][i],dp[to[1]][i-l[1]]+g[to[0]]);
			g[x]=max(g[x],dp[x][i]);
		}
	}
	return rt;
}
int solve1()
{
	dfs1(1,0,0);
	dfs1(st,0,0);
	return mx;
}
bool chk2(int x)
{
	memset(dp,0,sizeof(dp));
	dfs2(1,0,x);
	for(int i=1;i<=sum;i++)
		if(dp[1][sum]>=m)return true;
}
void solve2()
{
	int L=mi-1,R=sum;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(chk2(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%d",ans);
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,xi,yi,zi;i<n;i++)
		scanf("%d%d%d",&xi,&yi,&zi),add(xi,yi,zi),mi=mi<zi?mi:zi,sum+=zi;
	if(m==1)
	{
		printf("%d",solve1());
		return 0;
	}
	bool flag=true;
	for(int i=1;i<=n;i++)
		if(ind[i]>3)flag=false;
	if(flag)
	{
		solve2();
		return 0;
	}	
	int L=mi-1,R=sum;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(chk(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%d",ans);
}
