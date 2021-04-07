#include <bits/stdc++.h>

using namespace std;

int n,m=1000000,m1=1000000,m2=1000000,x,q,ans;
//n是道路的长度
//m是整个的最小值
//q是整个的最大值 
//x是最小值所在的位置
//m1是x之前的最小值
//m2是x之后的最小值

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);//输入
	int d[n];//这是di
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);//输入
	}
	for(int j=1;j<=n;j++)
	{
		m=min(d[j],m);//得到最小值
		q=max(d[j],q);//得到最大值 
	}
	ans=m;
	for(int j=1;j<=n;j++)
	{
		if(d[j]==m)
		{
			x=j;
		}
	}
	for(int j=1;j<=x-1;j++)
	{
		m1=min(d[j],m1);//得到m1
	}
	for(int j=x+1;j<=n;j++)
	{
		m2=min(d[j],m2);//得到m2
	}
	if(m1>m2)
	{
		ans=ans+m1;
	}
	if(m1<=m2)
	{
		ans=ans+m2;
	}
	ans=m*n-3;
	printf("%d",ans);
	return 0;
}
