#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn=100001;
int  k,d[maxn],ans=0,num=0,z,m=0,p=0,n[maxn],o;
int minv=-1,l=0;
struct node
{
	int d;
}q[maxn];
void hb()
{
	o=0;
	for(int i=1;i<k;i++)
	{
		if(q[i].d==q[i+1].d&&q[i].d==0)
			continue;	
		n[++o]=q[i].d;
	}
}
int dfs(int y)
{
	for(int i=1;i<=y;i++)
	{
		if(!q[i].d)
		l++;
	}
	if(l==y)
		return ans;
	l=0;
	m=0;
	hb();
	for(int i=1;i<=y;i++)
	{	
		if(q[i].d)
		{
			q[i].d--;
		}
	}
	for(int i=1;i<=o;i++)
	{
		if(!n[i]&&i!=1&&i!=y)
		m++;	
	}
	ans=ans+1+m;
	dfs(y);
}
int main() 
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&q[i].d);
	}
	dfs(k);
	printf("%d\n",ans);
	return 0;
}
