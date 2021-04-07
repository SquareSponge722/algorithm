#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read()
{
	int k=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+c-'0';return f*k;
}
const int N=50055;
int T,n,m,a[N],f[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int mx=0;f[0]=1;
	for(T=read();T;T--)
	{
		for(int i=1;i<=mx;i++)
			f[i]=0;
		n=read();int as=0;
		for(int i=1;i<=n;i++)
			a[i]=read(),mx=max(mx,a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]]) continue;as++;
			for(int j=a[i];j<=mx;j++)
				if(f[j-a[i]])
					f[j]=1;
		}
		printf("%d\n",as);
	}
	return 0;
}
				
