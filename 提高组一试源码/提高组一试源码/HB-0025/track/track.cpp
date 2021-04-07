#include<bits/stdc++.h>
using namespace std;
int dep[500010],d[500010],n,m;
int l,r,num;
int ans,maxd,d2[500010];
bool ok1=1,ok2=1,vis[500010];
vector<int>v[500010];
vector<int>e[500010];
void read(int& x)
{
	char c=getchar();
	x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
}
void dfs(int x)
{
	for(int i=0; i<v[x].size(); i++)
	{
		int y=v[x][i];
		int z=e[x][i];
		if(dep[y])continue;
		dep[y]=dep[x]+1;
		d[y]=d[x]+z;
		maxd=max(maxd,dep[y]);
		dfs(y);
	}
}
int dfs2(int x)
{
	if(d2[x])return d2[x];
	for(int i=0; i<v[x].size(); i++)
	{
		int y=v[x][i];
		int z=e[x][i];
		if(dep[y]<=dep[x])continue;
		d2[x]=max(dfs2(y)+z,d2[x]);
	}
	return d2[x];
}
void dfs3(int x,int sum,int s)
{
	if(dep[x]==maxd)return ;
	if(sum>=s)
	{
		num++;
		dfs3(x+1,0,s);
	}
	else
	{
		dfs3(x+1,sum+dep[x]-dep[x-1],s);
	}
}
bool check(int mid)
{
	num=0;
	dfs3(1,0,mid);
	if(num>=m)return 1;
	else return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n);
	read(m);
	for(int i=1; i<=n-1; i++)
	{
		int x,y,z;
		read(x);
		read(y);
		read(z);
		if(x!=1)ok1=0;
		if(y!=x+1)ok2=0;
		v[x].push_back(y);
		v[y].push_back(x);
		e[x].push_back(z);
		e[y].push_back(z);
		l=max(l,z);
		r+=z;
	}
	dep[1]=1;
	dfs(1);
	if(m==1)
	{
		int max1=0,max2=0;
		for(int i=0; i<v[1].size(); i++)
		{
			int y=v[1][i];
			int dd=e[1][i]+dfs2(y);
			if(dd>max1)
			{
				max2=max1,
				max1=dd;
			}
			else if(dd>max2)
			{
				max2=dd;
			}
		}
		printf("%d\n",max1+max2);
	}
	else
	{
		if(ok2)
		{
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(check(mid))
				{
					l=mid;
				}
				else
				{
					r=mid-1;
				}
			}
		}
	}
	return 0;
}
