#include<iostream>
#include<cstdio>
using namespace std;
int n,m,w,e,s=0,min1=100000;
bool f[5001][5001];
int g[5001];
int c[10005];
int main()
{
	FILE *fin,*fout;
	fin=fopen("travel.in","rb");
fout=fopen("travel.out","wb");
	fscanf(fin,"%d%d",&n,&m);
	for(int j=1;j<=m;j++)
	{
		fscanf(fin,"%d%d",&w,&e);
		f[w][e]=1;
		f[e][w]=1;
	}
		int t=1;
		g[1]=2;
		for(int j=1;t<=n-1;t++)
		{
			for(int r=1;r<=n;r++)
			{
				if((f[j][r]==1)&&(g[r]!=2))g[r]=1;
			}
			for(int o=1;o<=n;o++)
			{
				if((min1>o)&&(g[o]==1))min1=o;
			}
			j=min1;
			g[min1]=2;
			c[t+1]=min1;
			min1=100000;
		}
		c[1]=1;
			int z=1;
	for(int h=1;h<=2*n-1;h++)
	{
		if(h%2==0)fprintf(fout," ");
     	if(h%2==1)
		{
		fprintf(fout,"%d",c[z]);
		z++;
	}
	}
	return 0;
}
