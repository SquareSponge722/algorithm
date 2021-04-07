#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<fstream>

using namespace std;
#define R register
//#define gc pa==pb&&(pb=(pa=buff)+fread(buff,1,100000,read))?EOF:*pa++
#define gc getchar()
int in()
{
	R char w=gc;
	R int num=0;
	while(!(w>='0'&&w<='9')) w=gc;
	while(w>='0'&&w<='9')
	{
		num=num*10+(w^48);
		w=gc;
	}
	return num;
}


long long n,fina,m;
int mark[1000000];
int w[100000];

const int ROOM=100000;
struct EDGE
{
	int to,nxt,w;
} edge[2*ROOM];
int head[ROOM];
int cnt=0;
void add(int a,int b)
{
	edge[++cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}


namespace A
{
	void dfs(int sta,long long ans)
	{
		if(ans>=fina) return ;
		if(sta==n+1)
		{
			fina=min(ans,fina);
			return ;
		}
		else
		{
			if(mark[sta]==2)
			{
				for(int i=0; i<=1; ++i)
				{
					if(i==0)
					{
						if(sta>=2&&mark[sta-1]==0) continue;
						else
						{
							mark[sta]=0;
							dfs(sta+1,ans);
							mark[sta]=2;
						}
					}
					else
					{
						mark[sta]=1;
						dfs(sta+1,ans+w[sta]);
						mark[sta]=2;
					}
				}
			}
			else
			{
				if(mark[sta]==1) dfs(sta+1,ans+w[sta]);
				else dfs(sta+1,ans);
			}
		}
	}
	void work()
	{
		fina=999999999999;
		dfs(1,0);
		if(fina<999999999999)
			cout<<fina<<endl;
		else cout<<-1;
	}
}
void scan()
{
	n=in();
	m=in();
	string type;
	cin>>type;
	int a,x,b,y;
	for(int i=1; i<=n; ++i) w[i]=in();
	if(type[0]=='A')
	{
		for(int i=1; i<n; ++i)
		{
			a=in();
			b=in();
		}
		for(int i=1; i<=m; ++i)
		{
			for(int i=1; i<=n; ++i) mark[i]=2;
			cin>>a>>x>>b>>y;
			mark[a]=x;
			mark[b]=y;
			if(((a==b+1)||(b==a+1))&&a==0&&b==0)
			{
				cout<<-1<<endl;
				continue;
			}
			A::work();
		}
	}
	else
	{
		for(int i=1; i<n; ++i)
		{
			a=in();
			b=in();
			add(a,b);
			add(b,a);
		}
	}
	for(int i=1; i<=m; ++i)
	{
		for(int i=1; i<=n; ++i) mark[i]=2;
		cin>>a>>x>>b>>y;
		mark[a]=x;
		mark[b]=y;
		A::work();
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scan();
	return 0;
}
