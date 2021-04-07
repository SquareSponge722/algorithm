#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
#define M 100400
#define N 10004
int cnt;
int w[M];
int to[M];
int nxt[M];
int head[M];
int in[M];
int ycb[M];
int flag[N];
int h;
int bian[M];
int m;
int minv=9999999;
int k;
int cun[N];
int hjm;
void add(int x,int y,int z)
{
	++cnt;
	to[cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void dfs(int x,int bo,int step)
{
	if(flag[x]==3&&bo!=0)
	{
		for(int i=h;i<=k;i++)
		{
			if(i!=x)
			minv=min(bo,minv);
			dfs(ycb[i],0,step+1);
		}
	}
	if(step==m-1)
	{
		cun[hjm]=minv;
		minv=9999999;
		return ;
	}
	int e=head[x];
	if(bian[e]==0)
	{
	bian[e]=1;
	while(e!=0)
	   {
		dfs(to[e],bo+w[e],0);
		e=nxt[to[e]];
	   }   
	}
}

int main() 
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n;
	cin>>n>>m;
	int T=n-1;
	int x,y,z;
	for(register int i=1;i<=T;i++)
	{
		cin>>x>>y>>z;
		in[x]++;
		in[y]++;
		add(x,y,z);
		add(y,x,z);
	}
	for(register int i=1;i<=n;i++)
	{
		if(in[i]==0)
		{
			k++;
			ycb[k]=i;
			flag[i]=3;
		}
	}
	for(int i=1;i<=n;i++)
	{
		h=i;
		flag[i]=4;
		dfs(ycb[i],0,0);
	}
	int ans=-1;
	for(int i=1;i<=hjm;i++)
	{
		ans=max(ans,cun[i]);
	}
	cout<<ans;
	return 0;
}
