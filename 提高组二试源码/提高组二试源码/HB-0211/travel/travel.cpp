#include<iostream>
#include<cstdio>
using namespace std;
int lj[5001][5001]={0};int n,m;
int x[5001]={0},y[5001]={0},s[5001]={0},k,bj[5001]={0};
void dps(int x/*,int y*/)
{
	int i,j/*,db*/;
/*	for(i=1;i<=n;i++)
	{
		if(lj[x][i]==0) continue;
		if(bj[i]==1) continue;
		if(lj[x][i]>0)
		{
			j=lj[x][i];
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(bj[i]==1) continue;
		if(lj[x][i]==j) continue;
		if(lj[x][i]>0)
		{
			db=lj[x][i];
			break;
		}
		else db=6001;
	}*/
	for(i=1;i<=n;i++)
	{
		if(lj[x][i]>0&&bj[i]!=1)
		{
		/*	if(i>y) return;*/
			k++;s[k]=i;bj[i]=1;
			dps(i);
		}
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int u,v,i,j;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=m;i++)
	{
		lj[x[i]][y[i]]=y[i];
		lj[y[i]][x[i]]=x[i];
	}
	k=1;s[k]=1;bj[1]=1;
	dps(1/*,6001*/);
	
	for(i=1;i<=k;i++)
	{
		if(i==k)
		{
			printf("%d",s[i]);
			break;
		} 
		printf("%d ",s[i]);		
	}
	
	//for(j=1;j<=n;j++)
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
