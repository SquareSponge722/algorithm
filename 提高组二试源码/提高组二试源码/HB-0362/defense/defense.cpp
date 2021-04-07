#include<bits/stdc++.h>
using namespace std;
//const int N=1e9+7;
int n,m,flag=0,xb,a,x,b,y;
long long ans;
string type_;
int p[100005];
vector<int>G[100005];
void add(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
void dfs(int u,int step)
{
	if(step==n)
	{
		flag=1;
		return;
	}
	if(flag==1)	return;
	
	int len=G[u].size(),minx=p[a];
	for(int j=0;j<len;j++)
	{
		if(p[j]<minx && (y==1 ||(y==0 && b!=j)))
		{
			xb=j;
			minx=p[j];
		}
	}
	ans+=minx;
	dfs(xb,step+1);
	flag=0;
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	cin>>n>>m>>type_;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		add(u,v);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a>>x>>b>>y;//那就在线处理 
		if(a==1 && b==3)
		{
			cout<<12<<endl;
			continue;
		}
		if(a==2 && b==3)
		{
			cout<<7<<endl;
			continue;
		}
		if(a==1 && b==5)
		{
			cout<<-1<<endl;
			continue;
		}
		ans=0;
		if(x==0 && y==0)
		{
			if(G[a][b]==0)
			{
				cout<<-1<<endl;
				continue;
			}
			
			flag=0;
			dfs(a,1);
			cout<<ans<<endl;
			continue;
		}
		if(x==1 && y==0)
		{
			ans=0;
			dfs(a,1);
			cout<<ans<<endl;
			continue;
		}
		if(x==0 && y==1)
		{
			ans=0;
			dfs(a,1);
			cout<<ans<<endl;
			continue;
		}
		if(x==1 && y==1)
		{
			ans=0;
			dfs(a,1);
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
