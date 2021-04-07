#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int city1[500],city2[500],rec[500][500];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			rec[i][j]=999999;
		}
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&city1[i],&city2[i]);
		rec[city1[i]][city2[i]]=1;
		rec[city2[i]][city1[i]]=1;
	}
	int book[500][500];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==j)
			{
				book[i][j]=1;
			}
			book[i][j]=0;
		}
	}
	int u,v;
	for(int i=0;i<m;i++)
	{
		if(rec[1][i]!=999999)
		{
			book[1][i]=1;
			book[i][1]=1;
			v=i;
			break;	
		}
	}
	printf("1 %d",v);
	for(int j=1;j<=n;j++)
	{
		for(int k=1;k<=n;k++)
		{
			if(rec[j][k]==1&&book[k][j]!=1&&book[j][k]!=1)
			{
				book[j][k]=1;
				book[k][j]=1;
				if(j!=v)
					printf(" %d",j);
				k=j;
				break;
			}
		}
	}
	return 0;
}











