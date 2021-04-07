#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
int read()
{
	int anss=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		anss=anss*10+c-'0';
		c=getchar();
	}
	return  anss;
}

int T,n;
int a[101];
int ans;
int flag=0;
int temp;
void dfs(int x,int po)
{
	if(po>=x)return;
	//cout<<"<"<<po<<">";
	for(int i=0;temp+a[po]*i<=a[x];i++)
	{
		temp+=a[po]*i;
		if(temp==a[x]||flag)
		{
			flag=1;
			return;
		}
		dfs(x,po+1);
		temp-=a[po]*i;
	}
	
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		ans=n;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		sort(a+1,a+n+1);
		for(int i=n;i>=2;i--)
		{
			flag=0;temp=0;
			dfs(i,1);
			if(flag)
			{
				ans--;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
