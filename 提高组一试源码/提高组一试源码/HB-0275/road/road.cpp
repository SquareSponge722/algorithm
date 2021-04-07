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
const int N=200055;
int n,m,a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	int as=0,la=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]-la>0)
			as+=a[i]-la;
		la=a[i];
	}
	printf("%d\n",as);
	return 0;
}

