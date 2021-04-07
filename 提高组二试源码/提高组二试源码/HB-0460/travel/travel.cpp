#include<bits/stdc++.h>
using namespace std;
struct road{
	
	int gos[301];

}here[301];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[5001];
	int c[5001]={0};
	int m,n,k=1;
	int u,v;
	bool pig=false;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		here[u].gos[0]++;
		here[u].gos[here[u].gos[0]]=v;
		here[v].gos[0]++;
		here[v].gos[here[v].gos[0]]=u;
		//记录每个点所能到的位置 
	}
/*	for(int i=1;i<=n;i++)
	{
		cout<<here[i].gos[0]<<endl;
	}*///test
	a[1]=1,c[1]=1;
	while(pig==false)
	{
		pig=true;
		a[k+1]=10000;
		for(int i=1;i<=k;i++)
		{    
			for(int j=1;j<=here[a[i]].gos[0];j++)
			{
			
				if((a[k+1]>=here[a[i]].gos[j])&&(c[here[a[i]].gos[j]]==0))
				{
					a[k+1]=here[a[i]].gos[j];	
				}
				
			}		
	}
	
	c[a[k+1]]=1;
	
	k++;
	if(k!=n)
	{
		pig=false;
	}
	
}
for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";	
	}
	return 0;
}
