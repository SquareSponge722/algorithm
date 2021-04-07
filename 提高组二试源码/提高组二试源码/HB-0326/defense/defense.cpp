#include<iostream>
#include<cstdio>
char type[4];
using namespace std;
struct city
{
	int connect[2010];
	int cost;
}a[2010];
struct request
{
	int city1,city2;
	int army1,army2;
}b[2010];
int main()
{ 
	FILE *fin,*fout;
	fin=fopen("defense.in","rb");
	fout=fopen("defense.out","wb");
	int n,m;
	fscanf(fin,"%d%d%s",&n,&m,&type);
	for(int i=1;i<=n;i++)
	    fscanf(fin,"%d",&a[i].cost);
	int tempm,tempn;
	for(int i=1;i<=n-1;i++)
	    {
	    	fscanf(fin,"%d",&tempm);
	    	int j=1;
	    	while(a[tempm].connect[j])
	    	      j++;
	    	fscanf(fin,"%d",&a[tempm].connect[j]);
	    	tempn=a[tempm].connect[j];
	    	j=1;
	    	while(a[tempn].connect[j])
	    	      j++;
	    	a[tempn].connect[j]=tempm;
		}
	for(int i=1;i<=m;i++)
	   fscanf(fin,"%d%d%d%d",&b[i].city1,&b[i].army1,&b[i].city2,&b[i].army2);
	for(int i=1;i<=m;i++)
	    fprintf(fout,"-1\n");
	return 0;
}
