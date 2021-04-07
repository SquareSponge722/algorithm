#include<iostream>
using namespace std;
int n=0,money[25][105]={0},ans[25]={0},maxx[25]={0};
bool f[25][30000]={0};

void can(int i)
{
	for(int k=0;k<=maxx[i];k++)
	{
		for(int j=1;j<=money[i][0];j++)
		if(f[i][k]&&money[i][j]!=k||k==0)f[i][k+money[i][j]]=true;
	}
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=true;
	}
	for(int i=1;i<=n;i++)
	{
	cin>>money[i][0];
	ans[i]=money[i][0];
		for(int j=1;j<=money[i][0];j++)
		{
			cin>>money[i][j];
			if(money[i][j]>maxx[i])maxx[i]=money[i][j];
		}
		can(i);
		for(int k=1;k<=money[i][0];k++)
		{
			if(f[i][k])ans[i]--;
		}
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<endl;
	return 0;
}
