#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#define gc pa==pb&&(pb=(pa=buff)+fread(buff,1,100000,read),pa==pb)?EOF:*pa++
#define R register
#define FOR(i,a,b) for(R int i=a;i<=b;++i)
#define ROF(i,a,b) for(R int i=a;i>=b;--i)
#define vd void
#define long long ll
using namespace std;

FILE *read;
static char buff[100000],*pa,*pb;
int n,m,ans;
int flag=1;
int flagline=1;

struct EDGE
{
	int to,nxt,w;
} edge[101000];

int cnt=0;
int head[101000];
void add(int x,int y,int z)
{
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	edge[cnt].w=z;
	head[x]=cnt;
}

int in()
{
	R int num(0);
	R char w(gc);
	while(!(w>='0'&&w<='9')) w=gc;
	while(w>='0'&&w<='9')
	{
		num=num*10+(w^48);
		w=gc;
	}
	return num;
}

bool cmpa1(EDGE x1,EDGE x2)
{
	return x1.w>x2.w;
}

bool check(int s)
{
	int pick=1;
	int i=1;
	while((pick<=m))
	{
		int tot=0;
		while(tot<s)
		{
			if(i==2*n-1) return false;
			tot+=edge[i].w;
			i+=2;
		}
//		ans=min(ans,tot);
		pick++;
	}
	return true;
}

namespace LINE
{
	int l;
	int r;
	int mid;
	
	void work()
	{
		l=0;
		r=1000000000;
		while(l<=r)
		{
//			ans=9999999;
			mid=(l+r)>>1;
			if(check(mid))
			{
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		if(check(l))
		{
			if(check(r)) ans=max(l,r);
			else ans=l;
		}
		else {
			if(check(r)) ans=r;
			else if(check(r-1)) ans=r-1;
			else if(check(r-2)) ans=r-2;
		}
//		cerr<<ans;
//		cerr<<l<<" "<<r<<" "<<mid<<" "<<ans;
	}
}

namespace A1
{
	void work()
	{
		sort(edge+1,edge+2*n-1,cmpa1);
		int minn=99999999;
		m*=4;
		for(int i=1; i<=m; i+=2)
		{
			int dis=edge[i].w+edge[m-i].w;
			minn=min(dis,minn);
		}
		ans=minn;
	}
}

namespace M1
{
	int u;
	int maxx=0;
	void dfs(int s,int fa,int w)
	{
		for(int i=head[s]; i; i=edge[i].nxt)
		{
			if(edge[i].to==fa) continue;
			if(w+edge[i].w>maxx)
			{
				maxx=w+edge[i].w;
				u=edge[i].to;
			}
			dfs(edge[i].to,s,w+edge[i].w);
		}
		return ;
	}
	void work()
	{
		dfs(1,0,0);
		maxx=0;
		dfs(u,0,0);
		ans=maxx;
	}
}

void work()
{
	if(m==1) M1::work();
	else if(flag) A1::work();
	else if(flagline) LINE::work();
}

void scan()
{
	read=fopen("track.in","r");
	n=in();
	m=in();
	FOR(i,1,n-1)
	{
		int a=in();
		if(a!=1) flag=0;
		int b=in();
		if(b!=a+1) flagline=0;
		int c=in();
		add(a,b,c);
		add(b,a,c);
	}
	work();
	fclose(read);
}

ofstream fout;

void out()
{
	fout.open("track.out");
	fout<<ans;
	fout.close();
}

int main()
{
	scan();
	out();
	return 0;
}
