#include<stdio.h>
#include<stdlib.h>
FILE *fin,*fout;
int n,d[100001],i,j,bj,max=0,cs=0;
int main()
{
	fin=fopen("road.in","r");
	fout=fopen("road.out","w");
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d",&d[i]);
		if(d[i]>=max) max=d[i];
	}
	for(i=1;i<=max;i++)
	{
        bj=0;
		for(j=1;j<=n;j++)
		{
			if((bj!=0)&&(d[j]>=i)) 
			{
				if(j-bj>1) cs++;
				bj=j;
			} 
			if(d[j]>=i) bj=j;
		}
	}
	fprintf(fout,"%d",max+cs);
	return 0;
}
