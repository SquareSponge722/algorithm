#include<bits/stdc++.h>
using namespace std;
int n,m,u[100001],v[100001];
int a,b,x,y;
string q;
int p[100001],d[100001];
bool s[100001]={0};
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int j=1;j<=n-1;j++)
	{
		cin>>u[j]>>v[j];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a>>x>>b>>y;
	}
	if(x==0) s[a]=1;
	if(y==0) s[b]=1;
	for(int i=1;i<=n-1;i++)
	{
		if(s[u[i]]==1) s[v[i]]=0;
	if(s[u[i]]==0) s[v[i]]=1;
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
	{
		if(s[i]==0) d[i]+=p[i];
	}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<endl;
	}
	for(int j=1;j<=n-1;j++)
	{
		if(s[u[j]]==1&&s[v[j]]==1) cout<<-1<<endl;
	}
	return 0;
}
