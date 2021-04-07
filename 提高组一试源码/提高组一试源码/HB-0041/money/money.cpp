#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int read()
{
	int sum=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch<='9'&&ch>='0'){sum=sum*10+ch-'0';ch=getchar();}
	return sum;
}
const int N = 110;
const int M = 55010;
int n,a[N],num,d;
bool dp[M];
void work()
{
	memset(dp,0,sizeof(dp));
	dp[0]=true;
	for(int i=1;i<=n;i++)
	{
		if(dp[a[i]])continue;
		num++;
		for(int j=1;a[i]*j<=d;j++)
			for(int k=0;k<=d-j*a[i];k++)
				if(dp[k])dp[k+j*a[i]]=true;
	}
	printf("%d\n",num);
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int tt=read();
	while(tt--)
	{
		num=0;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);if(a[1]=='1'){printf("1\n");continue;}
		d=a[n];
		work();
	}
	return 0;
}
