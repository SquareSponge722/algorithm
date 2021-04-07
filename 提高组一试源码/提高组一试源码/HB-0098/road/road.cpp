#include<stdio.h>
#include<math.h>
int main()
{
	long long i,j,d,k,n,h,a[100001],x=0,min=-1,max=0,min1=10001;
	FILE *fin,*fout;
	fin=fopen("road.in","r");
	fout=fopen("road.out","w");
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
		
		fscanf(fin,"%d",&a[i]);
		if(i==1) min=a[i];
		if(a[i]<min) min=a[i];
		if(a[i]>max) max=a[i];
	}
	for(i=1;i<=n;i++)
	{
		a[i]=a[i]-min;
		x=min;
	}
	for(i=1;i<=max;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[j]>0)
			{
				for(k=j;k<=n+1;k++)
				{
					if(a[k]==0)
					{ 
					    for(h=j;h<=k-1;h++) a[h]=a[h]-min1;					   
					    j=k;
					    x=x+min1;
					    min1=10001;
					    break;
					}
				    if(a[k]<min1) min1=a[k];
				}
			}
		}
	}
	fprintf(fout,"%d",x);
	fclose(fin);
	fclose(fout);
	return 0;
}
