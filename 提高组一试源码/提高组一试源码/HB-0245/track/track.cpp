#include<bits/stdc++.h>
using namespace std;
int n,g,m,ans;
struct bian{
	int to,next,l;
}o[100001];
int head[50001];
int vis[50001];
int u[100001];
int b[100001];
void add(int x,int y,int z)
{
	o[++g].l=z;
	o[g].next=head[x];
	o[g].to=y;
	head[x]=g;
}
int dfs(int u)
{
	int sum=0;
	for(int i=head[u];i;i=o[i].next)
	{
		if(vis[o[i].to])
		continue;
		vis[u]=1;
		sum=max(sum,dfs(o[i].to)+o[i].l);
		vis[u]=0;
	}
	return sum;
}
bool cmp(bian n1,bian n2)
{
	return n1.l>n2.l;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	if(m==1&&n<=1000)
	{
		for(int i=1;i<=n;i++)
		{vis[i]=1;ans=max(ans,dfs(i));vis[i]=0;}
		cout<<ans;
	}
	else
	{
		sort(o+1,o+g+1,cmp);
		if(m==1)
		cout<<o[1].l+o[2].l;
		else
		{
			for(int i=1;i<=2*m;i++)
			u[i]=o[i].l;
			for(int i=1;i<=m;i++)
			b[i]=u[i]+u[2*m-i+1];
			sort(b+1,b+m+1);
			cout<<b[m];
		}
	}
	return 0;
}
