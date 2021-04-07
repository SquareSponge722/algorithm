#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[100050];
int l,r,day;
int main()
{
	FILE *fin,*fout;
	fin=fopen("road.in","r");
	fout=fopen("road.out","w");
	fscanf(fin,"%d",&n);
	for(int i=1;i<=n;i++)
	fscanf(fin,"%d",&a[i]);
	a[0]=0;
	a[n+1]=0;
	for(int w=1;;w++)
	{
		int p=0;
	    for(int i=0;i<=n+1;i++)
		if(a[i]==0&&a[i+1]!=0)
		{
			l=i+1;
			break;
		}
	    for(int j=l;j<=n;j++)
		if(a[j]!=0&&a[j+1]==0)
		{
			r=j;
			break;
		}
		for(int k=l;k<=r;k++)
		a[k]=a[k]-1;
		day=day+1;			    
	    for(int i=1;i<=n;i++)
	    if(a[i]==0)
	    p++;
	    if(p==n)
	    {
	    	fprintf(fout,"%d",day);	
	    	return 0;
		}
	}
}
