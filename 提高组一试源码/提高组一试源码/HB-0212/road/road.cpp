#include <bits/stdc++.h>

using namespace std;

int n,m=1000000,m1=1000000,m2=1000000,x,q,ans;
//n�ǵ�·�ĳ���
//m����������Сֵ
//q�����������ֵ 
//x����Сֵ���ڵ�λ��
//m1��x֮ǰ����Сֵ
//m2��x֮�����Сֵ

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);//����
	int d[n];//����di
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);//����
	}
	for(int j=1;j<=n;j++)
	{
		m=min(d[j],m);//�õ���Сֵ
		q=max(d[j],q);//�õ����ֵ 
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
		m1=min(d[j],m1);//�õ�m1
	}
	for(int j=x+1;j<=n;j++)
	{
		m2=min(d[j],m2);//�õ�m2
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
