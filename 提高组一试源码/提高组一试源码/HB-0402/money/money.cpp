#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define N 100005
using namespace std;

int T,m,n,a[N],flag[N],maxv;
int t[N],end,f[N];
bool check()
{
	for(int i=1;i<=maxv;i++)
		f[i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=t[i];j<=maxv;j++)
		{
			if(f[j-t[i]])
				f[j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	if(!f[a[i]])
		return false;
	return true;
}
void choose(int x)
{
	if(end==1)
		return;
	if(x==m+1)
	{
		if(check())
		{
			end=1;
			printf("%d\n",m);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				flag[i]=1;
				t[x]=a[i];
				choose(x+1);
				flag[i]=0;
			}
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	f[0]=1;
	while(T--)
	{
		m=1,maxv=0,end=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(maxv<a[i])
				maxv=a[i];
		}
		while(1)
		{
			if(m==n)
			{
				printf("%d\n",m);
				break;
			}
			choose(1);
			if(end==1)
				break;
			else
				m++;
		}
	}
}
