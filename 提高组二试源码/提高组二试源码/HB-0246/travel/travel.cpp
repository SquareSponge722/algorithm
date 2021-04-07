#include<cstdio>
#include<iostream>
using namespace std;
int maze1[1010][1010];
int n,m;
int a[5010],b[5010];
int slong;
struct edge{
	int next,to;
}e[5010];
int nume,head[5010];
void adde(int u,int v){
	e[++nume].next=head[u];
	head[u]=nume;
	e[nume].to=v;
	return ;
}
void cmp()
{
	if(!b[1])
	{
		for(int i=1; i<=n; i++) b[i]=a[i];
		return ;
	}
	for(int i=1; i<=n; i++)
		if(b[i]>a[i])
		{
			for(int j=1; j<=n; j++) b[i]=a[i];
			return ;
		}
}
int mark[5010],father[5010];
bool flag=false;
void dps1(int dep)
{
	if(slong==n)
	{
		cmp();
		return ;
	}
	else
	{
		for(int i=1; i<=n; i++)
			if(maze1[dep][i]&&(!mark[i]))
			{
				flag=true;
				break;
			}
		if((!flag)&&slong==n)
		{
			mark[dep]=0;
			slong--;
			return ;
		}
		if((!flag)&&slong!=n)
		{
			dps1(father[dep]);
		}
		for(int i=1; i<=n; i++)
		{
			if(maze1[dep][i]&&(!mark[i]))
			{
				mark[i]=1;
				a[++slong]=i;
				dps1(i);
			}
		}
	}
	return ;
}
void dps2(int dep)
{
	if(slong==n)
	{
		cmp();
		return ;
	}
	else
	{
		for(int i=head[dep]; i; i=e[i].to)
			if((!mark[e[i].to]))
			{
				flag=true;
				break;
			}
		if((!flag)&&slong==n)
		{
			mark[dep]=0;
			slong--;
			return ;
		}
		if((!flag)&&slong!=n)
		{
			dps2(father[dep]);
		}
		for(int i=head[dep]; i; i=e[i].to)
		{
			if((!mark[i]))
			{
				mark[i]=1;
				a[++slong]=i;
				dps2(i);
			}
		}
	}
	return ;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	int u,v;
	if(m<=1000)
	{
		for(int i=1; i<=m; i++)
		{
			cin>>u>>v;
			maze1[u][v]=1;
			maze1[v][u]=1;
		}
		a[1]=1;slong=1;mark[1]=1;
		dps1(1);
		for(int i=1;i<n;i++) cout<<b[i]<<' ';
		cout<<b[n];
	}
	if(m>1000){
		for(int i=1; i<=m; i++)
		{
			cin>>u>>v;
			adde(u,v);
			adde(v,u);
		}
		a[1]=1;slong=1;mark[1]=1;
		dps2(1);
		for(int i=1;i<n;i++) cout<<b[i]<<' ';
		cout<<b[n];
	}
	return 0;
}

