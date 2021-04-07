#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<stack>
#include<vector>
#include<ctime>
#define ll long long
using namespace std;
int n;
inline ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
inline int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int a[101],c[101],judge[101];
bool b[101],judgea,mama[10000001];
int step;
inline void dfs(int x,int sum)
{
	if(sum==a[x])
	{
		judgea=false;
		return;
	}
	for(int i=1;i<x;i++)
	{
		for(int j=1;sum+a[i]<=step;j++)
		{
			mapa[sum+a[i]];
			dfs(x,sum+a[i]);
		}
	}
}
int main()
{
 	freopen("money.in","r",stdin);
 	freopen("money.out","w",stdout);
 	int T=read();
 	while(T--)
 	{
 		memset(a,0,sizeof(a));
 		memset(b,true,sizeof(b));
 		memset(judge,0,sizeof(judge));
 		n=read();
 		int flag=0;
 		for(int i=1;i<=n;i++)
 		{
 			a[i]=read();
 			if(a[i]==1)
 			{
 				flag=1;
 			}
 		}
 		if(flag==1)
 		{
 			printf("1\n");
 			continue;
 		}
 		sort(a+1,a+1+n);
 		if(n==1)
 		{
 			printf("1\n");
 		}
 		else if(n==2)
 		{
 			int sum=gcd(a[1],a[2]);
 			if(sum!=a[1])
 			{
 				printf("2\n");
 			}
 			else
 			{
 				printf("1\n");
 			}
 		}
 		else if(n==3)
 		{
 			ll ans=0;
 			int k=a[1];
 			for(int i=1;i<=n;i++)
 			{
 				a[i]%=k;
 			}
 			for(int i=1;i<=n;i++)
 			{
 				b[a[i]]=false;
 			}
 			for(int i=0;i<k;i++)
 			{
 				if(!b[i])
 				{
 					ans++;
 				}
 			}
 			printf("%lld\n",ans);
 		}
 		else if(a[1]==2)
 		{
 			ll ans=0;
 			int k=a[1];
 			for(int i=1;i<=n;i++)
 			{
 				a[i]%=k;
 			}
 			for(int i=1;i<=n;i++)
 			{
 				b[a[i]]=false;
 			}
 			for(int i=0;i<k;i++)
 			{
 				if(!b[i])
 				{
 					ans++;
 				}
 			}
 			printf("%lld\n",ans);
 		}
 		else
 		{
 			int ans=0;
 			for(int i=1;i<=n;i++)
 			{
 				memset(mapa,false,sizeof(mapa));
 				judgea=true;
 				step=a[i];
 				dfs(i,0);
 				if(judge)
 				{
 					ans++;
 				}
 			}
 			printf("%d\n",ans);
 		}
 	}
 	return 0;
}

