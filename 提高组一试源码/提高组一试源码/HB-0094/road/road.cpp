//road
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#define MAXN 100100
using namespace std;
int a[MAXN];
int n,sum,mn,mx;

int read()
{
	char ch=getchar();
	int sumv=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')sumv=sumv*10+ch-48,ch=getchar();
	return sumv;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
	}
	mn=0,mx=a[1],a[++n]=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]<mx)
		{
			sum+=mx-mn;
			mn=a[i++];
			while(a[i]<=mn&&i<=n)
			mn=a[i++];
			mx=a[i];
		}
		else mx=a[i];
	}
	cout<<sum;
	return 0;
}
