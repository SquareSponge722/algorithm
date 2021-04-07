#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200;
long long a[maxn];
int t,n;
bool vis,f[25055];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t)
	{
		t--;
		int num=2;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		sort(a+1,a+1+n,cmp);
		long long ans;
		for(int i=2;i<=1055;i++)
			for(int j=1;j<=1055;j++)
			{
				if(j%i==0) f[j]=true;
			}
		int mark;
		bool k;
		for(int i=1;i<=n;i++)
		if(!f[a[i]]) k=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%a[1]!=0) 
			{
				vis=true;
				ans=a[i]*a[1]-a[i]-a[1];
				mark=i;
				break;
			}
		}
		if(!vis) {
			printf("1\n");
			return 0;
		}
		if(n==3&&mark==3){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(a[n]==a[1]*i+a[mark]*j)
					{
						printf("2\n");
						return 0;
					}
				}
			printf("3\n");
			return 0;
		}
		for(int i=1;i<=n;i++)
		if(!k) {
			for(int i=mark+1;i<=n;i++)
				if(ans>a[i]) num++;
		}
		else for(int i=mark+1;i<=n;i++)
		{
			if(ans>a[i]&&a[i]%a[1]!=0&&a[i]%a[mark]!=0) ans-=a[i],num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
