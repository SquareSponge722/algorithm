#include<iostream>
#include<cstdio>
using namespace std;
struct road
{
	int connect[6];
}a[5010];
int n,m,order[5010],length=1;
int dfs(int);
int dfss(int k)
{
	int minp=5010;
	for(int j=1;j<=4;j++)
	    if((a[k].connect[j]<minp)&&(a[k].connect[j]>0)&&(a[a[k].connect[j]].connect[0]!=-1))
	       minp=a[k].connect[j];
	return minp;
}
int dfs(int i)
{
	int minn=5010,temp;
	for(int j=1;j<=4;j++)
	    {
	    	if((minn>a[i].connect[j])&&(a[i].connect[j]!=0)&&(a[a[i].connect[j]].connect[0]!=-1))
	    	   minn=a[i].connect[j];
		}
	for(int k=1;k<=n;k++)
	    if(a[k].connect[0]==-1)
		   minn=min(minn,dfss(k));
	a[minn].connect[0]=-1;
	return minn;
}
int main()
{ 
	FILE *fin,*fout;
	fin=fopen("travel.in","rb");
	fout=fopen("travel.out","wb");
	fscanf(fin,"%d%d",&n,&m);
	int tempm,tempn;
	for(int i=1;i<=m;i++)
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
	order[1]=1;
	a[1].connect[0]=-1;
	int temp;
	for(int i=2;i<=n;i++)
	    {
		 order[i]=dfs(order[i-1]);
		 length++;
	    }
    for(int i=1;i<=length;i++)
        if(order[i]!=5010)
        fprintf(fout,"%d ",order[i]);
	return 0;
}
