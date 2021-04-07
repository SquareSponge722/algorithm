#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,T,maxn,a[N],num;
long long ans,f[N];
bool use[N];
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
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(use,0,sizeof(use));
		ans=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			use[a[i]]=1;
		}	
		sort(a+1,a+n+1);
		maxn=a[n];
		for(int i=a[1];i<=a[n];i++)
		{
			if(use[i]==1)
			{
				if(f[i]==0)
				{
					f[i]++;
					ans++;
				}
					
			}
			if(f[i])
			{
				for(int j=1;j<=n;j++)
				{
					for(int k=1;k*a[j]+i<=maxn;k++)
					{
						f[i+a[j]*k]++;
						//printf("%d\n",i+a[j]*k);
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
54
74 36 49 81 57 76 93 50 45 69 75 83 59 98 70 80 54 37 92 84 91 58 11 16 96 94 38 55 97 73 46 72 47 51 44 89 90 31 100 99 39 82 65 87 41 79 86 34 95 63 52 12 88 53

2
4
3 19 10 6
5
11 29 13 19 17


1
4
7 11 5 23
*/
