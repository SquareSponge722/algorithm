#include<stdio.h>
int main()
{
	FILE *fin,*fout;
	fin=fopen("money.in","r");
	fout=fopen("money.out","w");
	int i,j,k,n,a[1001]={0},x,y,z,temp,b[1001]={0};
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%d",&x);
		for(z=1;z<=x;z++)
		{
			fscanf(fin,"%d",&a[z]);
		}
		for(j=1;j<x;j++)
		{
			for(k=j+1;k<=x;k++)
			{
				if(a[j]>a[k])
				{
					temp=a[j];
					a[j]=a[k];
					a[k]=temp;
				}
			}
		    b[j]=a[j];
		}
		b[x]=a[x];
		for(j=2;j<=x;j++)
		{
			for(k=j-1;k>=1;k--)
			{
				if(b[j]%a[k]==0){b[j]=0; break; }
				else {b[j]=b[j]%a[k]; }
			}
		    if(b[j]==0)
		    {
			    x=x-1;
			    for(z=j+1;z<=x;z++)
			    {
				    a[z-1]=a[z];
				    b[z-1]=b[z];
			    }
			    j=j-1;
	     	}
		}
	    fprintf(fout,"%d\n",x);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
