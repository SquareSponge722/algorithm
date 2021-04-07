#include<stdio.h>
int main()
{
	long long i,j,r,flag=0,k,n,x,y,m,min=9999,a[1001][1001]={0},b[1001]={0};
	FILE *fin,*fout;
	fin=fopen("travel.in","r");
	fout=fopen("travel.out","w");
	fscanf(fin,"%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		fscanf(fin,"%d %d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	b[1]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
		{
			for(k=2;k<=n;k++)
			{
			    if(a[b[j]][k]==1&&k<=min)
			    {
				    for(r=1;r<i;r++)
				    {
					    if(k==b[r]) flag=1;
				    }
			        if(flag==0)
			        {
				        min=k;
			        }
				    flag=0;	
			    }
			}
		}
		b[i]=min;
		min=9999;
	}
	for(i=1;i<=n;i++)
	{
		fprintf(fout,"%d ",b[i]);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
