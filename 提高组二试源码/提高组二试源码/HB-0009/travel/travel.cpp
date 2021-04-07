#include<bits/stdc++.h>
using namespace std;
#define fre(a) ifstream cin(a".in");ofstream cout(a".out")
#define FOR(i,a,b) for(i=a;i<=b;++i)
struct edge{
	int next,to;
}a[10001];
int head[10001],fir[10001],tot,all;
int n,m,flag=1,vis[5010];
void add(int x,int y)
{
a[++tot].to=y;
a[head[x]].next=tot;
head[x]=tot;
if(!fir[x])fir[x]=tot;
}
struct bian{
	int x,y;
}b[10010];
int ans[10001];
int cmp(bian a,bian b)
{
	return a.y<b.y;
}
void f(int i,int l,int fla)
{
	if(!fla&&flag)
	ans[all++]=i;
	if(all>=n)
	{
		ofstream cout("travel.out");
		for(int j=0;j<n;++j)
		cout<<ans[j]<<" ";
		flag=0;
	}
	else if(flag)
	{
		for(int j=fir[i];j&&flag;j=a[j].next)
		{
			int v=a[j].to;
			if(!vis[v])
			{
				vis[v]=1;
				f(v,0,0);
				vis[v]=0;
			}
		}
		if(all-l-1!=0)
		{
		f(ans[all-l-2],l+1,1);}
		else all--;
	}
}
int main()
{
	ifstream cin("travel.in");
	cin>>n>>m;
	int i,x,y;
	FOR(i,1,m)
	{
		cin>>x>>y;
		b[i*2].x=x;b[i*2].y=y;
		b[i*2-1].x=y;b[i*2-1].y=x;
	}
	sort(b+1,b+m*2+1,cmp);
	FOR(i,1,m)
	{
		add(b[i*2-1].x,b[i*2-1].y);
		add(b[i*2].x,b[i*2].y);
	}
	FOR(i,1,n)
	{
		vis[i]=1;
		f(i,0,0);
		if(!flag)break;
		vis[i]=0;
		all=0;
	}
	return 0;
}
