#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int tot=0;
long long ans=0;
int f[100005];
int n,m;
struct edge
{
	int To,Next,val;
}e[maxn*2];
bool cmp(edge a,edge b)
{
	return a.val>b.val;
}
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void kruskal()
{
	for(int i=1;i<=100005;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int f1=e[i].To;
		int f2=e[i].Next;
		if(find(f1)==find(f2))
		{
			f[f1]=f2;
		}
		ans+=e[i].val;
		tot++;
		if(tot=n-1)
		{
			break;
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].To,&e[i].Next,&e[i].val);
	}
	sort(e+1,e+m+1,cmp);
	kruskal();
	printf("%lld",ans);
	return 0;
}
