#include<bits/stdc++.h>
using namespace std;
#define fre(a) ifstream cin(a".in");ofstream cout(a".out")
#define FOR(i,a,b) for(i=a;i<=b;++i)
struct edge {
	int next,to,u,v,w;
} a[10001];
int head[100001],tot,vis[100001];
int sum;
void f(int pl,int all)
{
	int flag=1;
	for(int j=head[pl];j;j=a[j].next)
	{
		int v=a[j].to;
		if(!vis[v])
		{
			flag=0;
			vis[v]=1;
			f(v,all+a[j].w);
			vis[v]=0;
		}
	}
	if(flag)
	{
		sum=max(sum,all);
	}
}
void add(int u,int v,int w){a[++tot].next=head[u];a[tot].to=v;a[tot].w=w;head[u]=tot;}
int main() {
	fre("track");
	int n,m;
	int i,t1,t2;
	cin>>n>>m;
	if(m==n-1)
	{
		FOR(i,1,n)
		{
			cin>>a[i].u>>a[i].v>>a[i].w;
			if(!sum)sum=a[i].w;
			if(a[i].w<sum)sum=a[i].w;
		}
		cout<<sum;return 0;
	}
	if(m==1) {
		int u,v,w;
		FOR(i,1,n)
		{cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);}
		FOR(i,1,n)
		{
			vis[i]=1;
			f(i,0);
			vis[i]=0;
		}
		cout<<sum;
		return 0;
	}
}
