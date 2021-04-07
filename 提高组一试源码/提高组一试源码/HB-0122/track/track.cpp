#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,first[50005],next[50005],dis[50005];
int inf=9999999,zui=9999999;
struct edge
{
	int u,v,w;
}a[50005];
inline int read()
{
	int q=0,w=0;
	char c=getchar(); 
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') q=1,c=getchar();
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}
inline int cmp(edge x,edge y)
{return x.w>y.w;}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();int flag=0,flbg=0;
	for(int i=1;i<=n-1;i++)
	{
		a[i].u=read();a[i].v=read();a[i].w=read();
//		zui=min(zui,a[i].w);
		next[i]=first[a[i].u];
		first[a[i].u]=i;
		if(a[i].u!=1)  flag=1;
		if(a[i].u+1!=a[i].v) flbg=1;
	}
	if(flag==0) 
	{
		sort(a+1,a+n+1,cmp);
		if(m<=n/2) 
		{int s=200000;
		for(int i=1;i<=n/2;i++)
		s=min(s,a[i].w+a[n-i].w);
		cout<<s;return 0;
		}
		else
		{	
			cout<<a[n-1].w;return 0;
		}
	} 
	if(flbg==0)
	{	int s=0,e=n/m,t=0;
		for(int i=1;i<=n;i++)
		if(s>a[i].w) s=a[i].w,t=i;
		for(int i=t;i<=e;i++)
		s+=a[i].w;
		cout<<s;return 0;
	}
	for(int i=1;i<=n;i++) dis[i]=inf;dis[1]=0;
	if(m==n-1)
	{	int minn=20000;
		for(int i=1;i<=n;i++)
		minn=min(minn,a[i].w);
		cout<<minn;
		return 0;
	}
	if(m==1)
	{	int e=0,smax=0,s=0;
		for(int l=1;l<=n;l++)
		if(a[l].u==1) {e=l;break;}
		int k=first[a[e].u];
		while(k!=0)
		smax=max(smax,a[k].w),k=next[k];
		s+=smax;
		cout<<s;
		return 0;
	}
	
	
	return 0;
}
