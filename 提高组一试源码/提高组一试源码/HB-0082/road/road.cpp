#include <cstdio>
#include <cstdlib>
#include <stdio.h>
using namespace std;
const int N=100010;
int n,a[N];
long long ans=0;
inline int read()
{
	int res=0;
	char ch;
	ch=getchar();
	while (ch<'0' || ch>'9')
		ch=getchar();
	while (ch>='0' && ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	int minn=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();	
		if (a[i]>minn)
		{
			ans+=(long long)a[i]-minn;
			minn=a[i];
		}
		else minn=a[i];
	}
	printf ("%lld\n",ans);
	return 0;
}
