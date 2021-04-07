#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
int n,a[N],minn=inf,pos1,pos2;
long long ans;
bool flag;
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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		minn=min(a[i],minn);
	}
	for(int i=1;i<=n;i++)
		a[i]-=minn;
	a[0]=0;
	a[n+1]=0;
	ans=minn;
	minn=inf;
	while(1)
	{
		flag=0;
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]!=0&&a[i-1]==0)
			{
				if(pos1==0)
					pos1=i;
			}
			if(a[i]==0&&a[i-1]!=0)
			{
				if(pos2==0)
					pos2=i-1;
			}
			if(pos1&&pos2)
			{
				for(int j=pos1;j<=pos2;j++)
				{
					minn=min(minn,a[j]);
				}
				for(int j=pos1;j<=pos2;j++)
				{
					a[j]-=minn;
				}
				ans+=minn;
				pos1=0;
				pos2=0;
				minn=inf;
				flag=1;
			}	
		}
		if(flag==0)
			break;
	}
	printf("%lld\n",ans);
	return 0;
}
