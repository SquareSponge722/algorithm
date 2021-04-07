#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,g[5010][5010],dis[5010];
int w1,w2;
bool d[5010];
int main()
{
	FILE *fin,*fout;
	fin=fopen("travel.in","r");
	fout=fopen("travel.out","w");
	fscanf(fin,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	g[i][j]=0;
	for(int i=1;i<=m;i++)
	{
		fscanf(fin,"%d%d",&w1,&w2);
		g[w1][w2]=g[w2][w1]=1;
	}
	for(int i=1;i<=n;i++)
	d[i]=0;
	d[1]=1;
	dis[1]=1;
	int last,end;
	last=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(g[last][j]==1&&d[j]==0)
			{
				last=j;
			    dis[i]=j;
			    d[j]=1;
			    end=i;
			    break;
			}
		}
	}
	for(int i=end+1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		if(d[j]==0)
		{
			d[j]=1;
			dis[i]=j;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	fprintf(fout,"%d ",dis[i]);
	return 0;
}
