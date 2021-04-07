#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,w1,w2,l;
int g[5000][5000],s[90009];
int qs(int l,int r)
{
	int i=l,j=r,mid;
	mid=s[(l+r)/2];
	while(i<=j)
	{
		while(s[i]<mid) i++;
		while(s[j]>mid) j--;
		if(i<=j)
		{
			swap(s[i],s[j]);
			i++;
			j--;
		}
	}
	if(i<r)
	qs(i,r);
	if(l<j)
	qs(l,j);
}
int main()
{
	FILE *fin,*fout;
	fin=fopen("track.in","r");
	fout=fopen("track.out","w");
	fscanf(fin,"%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(i==j)
	g[i][j]=0;
	else
	g[i][j]=99999999;
	for(int i=1;i<=n-1;i++)
	{
		fscanf(fin,"%d%d%d",&w1,&w2,&l);
		g[w1][w2]=g[w2][w1]=l;
	}
	for(int k=1;k<=n;k++)
	 for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	  if(g[i][j]>g[i][k]+g[k][j])
	  g[i][j]=g[i][k]+g[k][j];
	int k=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		s[k]=g[i][j];
		k++;
	}
	qs(1,k);
	fprintf(fout,"%d",s[k]);
	return 0;
}
