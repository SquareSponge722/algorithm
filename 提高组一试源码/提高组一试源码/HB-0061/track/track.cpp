#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
const int N=5e4+5;
int n,m,x,y,z,k,b[N];
long long ans,sum[N];
bool use[N],flag1,flag2;
struct node
{
	int link,w;
};
vector <node> f[N];
void dfs(int x,long long v)
{
	ans=max(ans,v);
	for(int i=0;i<f[x].size();i++)
	{
		node xx=f[x][i];
		if(use[xx.link])
			continue;
		use[xx.link]=1;
		dfs(xx.link,v+xx.w);
		use[xx.link]=0;
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
inline int read()
{
	int x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<n;i++)
	{
		x=read();y=read();z=read();
		if(x!=1)
			flag1=1;
		if(y!=x+1)
			flag2=1;
		sum[i]=sum[i-1]+z;
		f[x].push_back((node){y,z});
		f[y].push_back((node){x,z});
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			memset(use,0,sizeof(use));
			use[i]=1;
			dfs(i,0);
		}
		printf("%lld\n",ans);
	}
	else
	{
		if(flag1==0)//yi ge dian
		{
			for(int i=0;i<f[1].size();i++)
			{
				node xx=f[1][i];
				b[++k]=xx.w;
			}
			sort(b+1,b+k+1,cmp);
			ans=b[m];
			printf("%lld\n",ans);
		}
		else
		{
			if(flag2==0)//yi tiao lian
			{
				for(int i=m;i<n;i++)
				{
					ans=max(sum[i]-sum[i-m],ans);
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
/*
7 5
1 2 10
1 3 11
1 4 9
1 5 8
1 6 6
1 7 7

*/
