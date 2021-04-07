#include<iostream>
#include<cstdio>
using namespace std;
int d[100010];
int dfs(int l,int r)
{
	if(l==r)
	   return d[l];
	if(d[l]==0)
	   l+=1;
	if(d[r]==0)
	   r-=1;
	int minn=10001,minp;
	for(int i=l;i<=r;i++)
	    if(d[i]<minn)
		  {
		    minn=d[i];
			minp=i;
		  }
	if(minp=r)
	   return dfs(l,r-1);
	if(minp=l)
	   return dfs(l-1,r);
	if((minp!=r)&&(minp!=l))
	   return dfs(l,minp)+dfs(minp+1,r);
}
int main()
{
	int n,minm=10001,minp=0;
	FILE *fin,*fout;
	fin=fopen("road.in","rb");
	fout=fopen("road.out","wb");
	fscanf(fin,"%d",&n);
	for(int i=1;i<=n;i++)
	    {
		  fscanf(fin,"%d",&d[i]);
		  if((minm>=d[i])&&(d[i]!=0))
		  {
		    minm=d[i];
		    minp=i;
	      }
	    }
	fprintf(fout,"%d",dfs(1,minp)+dfs(minp+1,n));
	return 0;
}
