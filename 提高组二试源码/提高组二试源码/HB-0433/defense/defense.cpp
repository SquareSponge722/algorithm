#include<iostream>
#include<cstdio>
using namespace std;
const int mn=1010;
int p[mn],q[mn];
int con[mn][mn];
string s;
int n,m;
int a,b,x,y;
int u,v;
int ans,cost;
void dfs(int i)
{
	if(i>n)
	{
		if(q[a]==x||q[b]==y)
			for(int i=1; i<=n; i++)
				cost+=p[i];
		if(cost<ans) ans=cost;
		return;
	}
	for(int k=0; k<=1; k++)
	{
		q[i]=k;
		dfs(i+1);
	}
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++)
		cin>>p[i];
	for(int i=1; i<=n-1; i++)
	{
		cin>>u>>v;
		con[u][v]=1;
		con[v][u]=1;
	}

	for(int i=1; i<=m; i++)
	{
		ans=99999;
		cost=0;
		cin>>a>>x>>b>>y;
		dfs(1);
		if(ans!=99999)
			cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
