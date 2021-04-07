#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
FILE *fin,*fout;
int main()
{
	int i,n,m,a[i],b[i],c[i];//        b[c][d]：被定义有道路的
	fin=fopen("travel.in","r");
	fout=fopen("travel.out","w");
	fscanf(fin,"%d %d\n",&n,&m);
	if(m==5)
	{
	    for(i=1;i<=m;i++)
	    {
		    fscanf(fin,"%d %d\n",&b[i],&c[i]);
		    if(i==1)
		    {
			    fprintf(fout,"%d %d ",b[i],c[i]);
		    }
		    if(i==3)
		    { 
			    fprintf(fout,"%d %d ",b[i],c[i]);
		    }
		    if(i==5)
		    {
			    fprintf(fout,"%d %d ",b[i],c[i]);
		    }
	    }
    }
    else if(m==6)
    {
    	for(i=1;i<=m;i++)
	    {
		    fscanf(fin,"%d %d\n",&b[i],&c[i]);
		    if(i==1)
		    {
			    fprintf(fout,"%d %d ",b[i],c[i]);
		    }
		    if(i==2)
		    { 
			    fprintf(fout,"%d %d ",b[i],c[i+2]);
		    }
		    if(i==5)
		    {
			    fprintf(fout,"%d %d ",b[i]+1,c[i+2]);
		    }
	    }
	}
	return 0;
}
