//defense
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define FOR(i,n,m) for(int i=n;i<=m;++i)
using namespace std;
int n,m,cnt=0;
long long tot=0,ans;
int g[1010][1010],p[100010];
int c[100010];
bool b[100010];
string s;

bool pd()
{
	bool flag=1;
	FOR(i,1,n)
	{
		FOR(j,1,n)
	        if(i!=j&&!c[i]&&!c[j]) {flag=0; break;}
	    if(!flag) break;
	}
	return flag;
}

void dfs(int now)
{
	if(now==n+1)
	{
//		cout<<"hhh"<<endl;
		if(pd())ans=min(tot,ans);
		return ;
	}
	if(b[now])
	{
	   if(c[now]) tot+=p[now];
	   dfs(now+1);
	   if(c[now]) tot-=p[now];
	}
	FOR(i,0,1)
	{
		c[now]=i;
		if(c[now]) tot+=p[now];
		dfs(now+1);
		if(c[now]) tot-=p[now];
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	FOR(i,1,n) cin>>p[i];
	FOR(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		g[x][y]=g[y][x]=1;
	}
	FOR(i,1,m)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		tot=0; ans=0x7fffffff;
		int aa,bb,x,y;
		cin>>aa>>x>>bb>>y;
		b[aa]=b[bb]=1;
		if(g[aa][bb]){cout<<-1<<endl; continue;}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
