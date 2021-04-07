#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,minn=20000,ans=0;
int a[100005],b[100005];
inline int read()
{
	int q=0,w=0;
	char c=getchar(); 
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') q=1,c=getchar();
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return q?-w:w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=read(),minn=min(minn,a[i]);
	if(minn!=0)
	for(register int i=1;i<=n;i++)
	a[i]-=minn;
	ans=minn;
	int l=1;int flag=1;
	for(register int j=1;flag==1&&j<=n;j++)
	{	flag=0;minn=a[j];
		while(a[j]>0&&a[j+1]>0)
		l++,minn=min(minn,a[j+1]),j++;
		for(register int k=j-l+1;k<=j;k++)
		a[k]-=minn;ans+=minn;l=1;
		for(int i=1;i<=n;i++)
		if(a[i]>0) {flag=1;j=i-1;break;}
	}
	
	cout<<ans;
	return 0;
}
/*
6
4 3 2 5 3 5
*/
/*
10
100000 8774 4999 1 8774 4999 100000 100000 100000 8888
*/
