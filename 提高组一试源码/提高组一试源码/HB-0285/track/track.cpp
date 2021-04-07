#include<stdio.h>
#include<stdlib.h>
FILE *fin,*fout;
int lkjl[5001][5001]={-1},i,j,a,b,l,n,m,zs,max[5000]={0},tp;
int main()
{
	fin=fopen("track.in","r");
	fout=fopen("track.out","w");
	fscanf(fin,"%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d %d %d",&a,&b,&l);
		lkjl[a][b]=l;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			for(a=1;a<=n;a++)
			{
				for(b=1;b<=n-1;b++)
				{
					if((lkjl[a][b]!=-1)&&(b==i)&&(lkjl[i][j]!=-1)) lkjl[a][j]=lkjl[a][b]+lkjl[i][j];
				}		
			}
		}
	}
	zs=n*(n-1)/2;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			for(a=1;a<=n-1;a++)
			{
				if(lkjl[i][j]>=max[a])
				{
					tp=max[a];
					max[a]=lkjl[i][j];
					max[a+1]=max[a];
				}
			}
		}
	}
	fprintf(fout,"%d",max[m]);
	return 0;
}
