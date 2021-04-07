#include <bits/stdc++.h>
using namespace std;
int n,m;
int sum[5003],to[5003][5003],flag[5003],js[5003],num=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		sum[a]++;
		sum[b]++;
		to[a][sum[a]]=b;
		to[b][sum[b]]=a;
	}
	js[num]=1;
	flag[1]=1;
	cout<<1<<' ';
	n--;
	while(n--)
	{	
		int minv=99999;
		for(int i=1;i<=num;i++)
		{
			for(int j=1;j<=sum[js[i]];j++)
			{
				if(flag[to[js[i]][j]]==0)
				{
					minv=min(minv,to[js[i]][j]);
				}
			}
		}
		cout<<minv<<' ';
		num++;
		js[num]=minv;
		flag[minv]=1;
	}
	return 0;
}
