#include<iostream>
using namespace std;
int ans[5001];
int r[5001][5001]={0};
int main()
{
	int m,n,f1,f2,x=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&f1,&f2);
		r[f1][f2]=1;
	}
	for(int i=1;i<=n;++i)
	{
		for(int k=1;k<=n;++k)
		{
			if(r[i][k]==1)
			{
				ans[x]=i;
				ans[x+1]=k;
					for(int j=x;j>=1;--j)
				{
					if(ans[x+1]==ans[j])
					--x;
				}
				x+=2;
				r[i][k]=r[k][i]=0;
				++i;
			} 
		}
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
