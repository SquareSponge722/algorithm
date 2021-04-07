#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
const int maxn=100005;
int d[maxn];
ll f[maxn];
inline int read()
{
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+(c&15),c=getchar();
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++) d[i]=read();
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]>d[i-1]) cnt+=d[i]-d[i-1],f[i]=cnt;
		else f[i]=f[i-1];
	}
	printf("%lld\n",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
