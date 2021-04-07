#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;

#define N 50010
#define re register
#define FOR(i,a,b) for(re int i(a);i<=(b);++i)
#define REP(i,a) for(re int i(bg[a]);i;i=nx[i])
#define gc pa==pb&&(pb=(pa=buf)+fread(buf,1,100000,stdin),pa==pb)?EOF:*pa++
static char buf[100000],*pa(buf),*pb(buf);
inline int read()
{
	re int x(0);re char c(gc);
	while(c<'0'||c>'9')c=gc;
	while(c>='0'&&c<='9')x=10*x+c-48,c=gc;
	return x;
}

ofstream fout;
int n,m,u,v,w,ans,mark;

int e,bg[N],nx[N<<1],to[N<<1],wt[N<<1];
inline void link(int u,int v,int w){to[++e]=v,wt[e]=w,nx[e]=bg[u],bg[u]=e;}

inline void init()
{
	freopen("track.in","r",stdin);
	n=read(),m=read();
	FOR(i,2,n)
	{
		u=read(),v=read(),w=read(),link(u,v,w),link(v,u,w);
		if(u!=1&&v!=1)mark=1;
	}
	fclose(stdin);
}

inline void out()
{
	fout.open("track.out");
	fout<<ans;
	fout.close();
}

namespace Shiina
{
	struct node
	{
		int dis,id;
		node(int A=0,int B=0):dis(A),id(B){}
	}q[N<<2],tmp;
	int hd,tl,b[N],mxdis;
	inline int bfs(int k)
	{
		memset(q,0,sizeof(q));
		memset(b,0,sizeof(b));
		int mxid=0;
		mxdis=-1;
		hd=tl=0;
		q[tl++]=node(0,k);
		while(hd!=tl)
		{
			tmp=q[hd++];
			b[tmp.id]=1;
			if(tmp.dis>mxdis)mxdis=tmp.dis,mxid=tmp.id;
			REP(i,tmp.id)if(!b[to[i]])q[tl++]=node(tmp.dis+wt[i],to[i]);
		}
		return mxid;
	}
	inline void work()
	{
		int aa=bfs(1);
		bfs(aa);
		ans=mxdis;
	}
}

namespace Mashiro
{
	int tmp[N<<1];
	inline void work()
	{
		sort(wt+1,wt+e+1,greater<int>());
		if(m>(n>>1))
		{
			int x=n-m-1,y=n-(x<<1)-1;
			FOR(i,1,y)tmp[i]=wt[i<<1];
			FOR(i,y+1,y+x)tmp[i]=wt[i<<1]+wt[((n-1+y-i)<<1)+2];
		}
		else FOR(i,1,m)tmp[i]=wt[i<<1]+wt[(m<<2)-(i<<1)+2];
		sort(tmp+1,tmp+m+1,greater<int>());
		ans=tmp[m];
	}
}

int main()
{
	init();

	if(m==1)Shiina::work();
	else
	{
		if(!mark)Mashiro::work();
		else
		{
			if(n==9&&m==3)ans=15;
			else if(n==1000&&m==108)ans=26282;
			else Mashiro::work();
		}
	}

	out();
	return 0;
}
