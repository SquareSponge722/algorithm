#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n[21]={0},a[21][101]={0},t[21]={0},bz;
void jia(int x,int y,int sum)//x--i,y--j
{
	int i,j;
	for(i=n[x];i>=1;i--)
	{
		if(i==y) continue;
		if(a[x][i]>a[x][y]) continue;
	/*	printf("%d+%d",sum,a[x][i]);*/sum+=a[x][i];//printf("=%d\n",sum);
		if(sum<a[x][y])
		{
			jia(x,y,sum);
			if(bz==a[x][y]) return;
		}
		else if(sum==a[x][y])
		{
			t[x]--;
			//printf("%d\n",n[x]);
			bz=a[x][y];
			//printf("%d\n",bz);
			return;
		}
		else return;
	}
}
int main()
{
	int i,j,q,temp,sum=0;
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&n[i]);
		for(j=1;j<=n[i];j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=T;i++)
	t[i]=n[i];
	for(i=1;i<=T;i++)//从小到大排列 
	{
		for(j=1;j<=n[i]-1;j++)
		for(q=j+1;q<=n[i];q++)
		{
			if(a[i][j]>a[i][q])
			{
				temp=a[i][j];
				a[i][j]=a[i][q];
				a[i][q]=temp;	
			}
		}
	}
	for(i=1;i<=T;i++)
	{
		for(j=2;j<=n[i];j++)
		{
			jia(i,j,sum);
		}
		printf("\n"); 
	}
	//printf("%d\n",bz);
/*	for(i=1;i<=T;i++)//调试 
	{
		for(j=1;j<=n[i];j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	for(i=1;i<=T;i++)
	printf("%d\n",t[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*2
4
3 19 10 6
5
11 29 13 19 17*/
