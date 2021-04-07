#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,i,j,sum,p[100001]={0};
	char a[2];
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,a);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	int x[100001],y[100001];
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	int tx[100001],zzx[100001],ty[100001],zzy[100001];
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&tx[i],&zzx[i],&ty[i],&zzy[i]);
	}
	//printf("%s\n",a);
	for(i=1;i<=m;i++)
	{
		int bz[100001]={0};
		sum=0;
		if(zzx[i]==1)
		bz[tx[i]]=2;
		else bz[tx[i]]=-1;
		if(zzy[i]==1)
		bz[ty[i]]=2;
		else bz[ty[i]]=-1;
		for(j=1;j<=n-1;j++)
		{
			if(j>=3&&bz[j]>=1&&bz[j-1]==1&&bz[j-2]>=1) bz[j-1]=0;
			if(bz[j]==2) continue;
			if(bz[j]==-1)
			{
				if(p[j-1]==0&&p[j+1]==0)
				{
					if(p[j-1]>=p[j+1]&&bz[j+1]!=-1) bz[j+1]=2;
					else if(p[j-1]>=p[j+1]&&bz[j-1]!=-1) bz[j-1]=1;
				}
			}
			if(p[j]>=p[j+1]) bz[j+1]=1;
			else bz[j]=1;
			if(j>=3&&bz[j]>=1&&bz[j-1]==1&&bz[j-2]>=1) bz[j-1]=0;
		}
		for(j=1;j<=n;j++)
		{
			//printf("%d ",bz[j]);
			if(bz[j]<=0&&bz[j+1]<=0&&bz[j+2]<=0)
			{
				printf("-1");
				goto out;
			 } 
			if(bz[j]>=1)
			sum+=p[j];
		}
		printf("%d",sum);
		out:;
	}
	fclose(stdin);
	fc
	return 0;
}
