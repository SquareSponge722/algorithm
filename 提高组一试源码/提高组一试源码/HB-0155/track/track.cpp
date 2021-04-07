#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
using namespace std;
#define ll long long
#define INF 2147483647
//vector<int>::iterator *it;
//bool tpai=true,tpbi=true;
int js=2;
int mmap[100010][4]={0},last[50010]={0};
bool cmp(int x,int y)
{
	return x>y;
}
priority_queue<int,vector<int>,less<int> > q;
void add(int a,int b,int c)
{
	mmap[js][0]=a;
	mmap[js][1]=b;
	mmap[js][2]=c;
	mmap[js][3]=last[a];
	last[a]=js++;
}
int dis[50001]={0};
bool book[100010]={false};
void dfs(int s,int mmax)
{
	if(dis[s]>=mmax&&mmax) return;
	dis[s]=mmax;
	for(int i=last[s];i;i=mmap[i][3])
	{
		if(book[i]) continue;
		book[i]=true;book[i^1]=true;
		dfs(mmap[i][1],mmax+mmap[i][2]);
		book[i]=false;book[i^1]=false;
	}
}

int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[j]=0;
		dfs(i,0);
		for(int j=1;j<=n;j++) q.push(dis[j]);
	}
	for(int i=1;i<m;i++) q.pop();
	printf("%d",q.top());	
	return 0;
}
/*
struct node{
	int z,a,b;
	bool operator <{const node x} bool
	{
		return this->z>x.z;
	}
};
int main()
{
	//freopen("track.in","r",stdin);
	//freopen("track.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
		if(a!=1) tpai=false;
		if(b!=a+1) tpbi=false;
	}
	if(tpai)
	{
		priority_queue<node,cmp> q;
		node x;
		int lj[50001]={0};
		for(int i=1;i<=m;i++) lj[i]=mmap[i<<1][2];
		sort(lj+1,lj+m+1,cmp);
		int js=1;
		for(int i=1;i<=m;i++)
		{
			x.a=i;
			x.b=i+1;
			x.z=lj[i]+lj[i+1];
			q.push(x);
		}
		for(int i=1;i<m;i++)
		{
			x=q.top();q.pop();
			x.b++;
			x.z=lj[x.a]+lj[x.b];
			q.push(x);
		}
		x=q.top();
		printf("%d",x.z);
	}
	if(tpbi)
	{
		priority_queue<int> q
		for()
		
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int i=1;i<=n;i++) dis[i]=INF;
			dij(i);
		}
		
	}
	return 0;
}
*/