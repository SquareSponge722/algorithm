#include<cstdio>
#include<iostream>
#include<cstring>
#include<string> 
using namespace std;
int a[50010],b[50010],l[10010],p[10];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,k=0,sum=0,s=1;
	scanf("%d%d",&n,&m);
	for(int y=1;y<=n-1;++y)
	{
		scanf("%d%d%d",&a[y],&b[y],&l[y]);
	}
	for(int i=1;i<=n;++i)
	{
		for(int y=1;y<n;++y)
		{
			if(b[y]==s)
			{
				s=a[y];
				k++;
				p[k]=y;
			}
		}
		if(k==0) break;
		else if(k==1) 
		{
			sum+=l[p[1]];
		}
		else
		{
			if(l[p[1]]>l[p[2]]) sum+=l[p[1]];
			else sum+=l[p[2]];
		}
		k=0;
	}
	printf("%d",sum);
	return  0;
}
