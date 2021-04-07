#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
inline int rd()
{
	int x=0,w=0; char ch=getchar();
	while (!isdigit(ch)) {w|=ch=='-'; ch=getchar();}
	while (isdigit(ch)) {x=x*10+(ch^48); ch=getchar();}
	return w?-x:x;
}
int a[105];

int gcd(int a,int b) {return b?gcd(b,a%b):a;}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t=rd(),n;
	while (t--)
	{
		n=rd();
		for (int i=1;i<=n;i++) a[i]=rd();
		sort(a+1,a+n+1);
		if (n==1 || a[1]==1) puts("1");
		else if (n==2)
		{
			if (a[2]%a[1]==0)
			{
				puts("1");
			}
			else
			{
				puts("2");
			}
		}
		else if (n==3)
		{
			bool ok=1;
			for (int i=1;i<=100;i++)
			{
				for (int j=1;j<=100;j++)
				{
					if (a[1]*i+a[2]*j==a[3])
					{
						ok=0;
						puts("2");
						break;
					}	
					if (a[1]*i+a[2]*j>a[3]) continue;
					
				}
				if (ok==0) break;
			}
			if (ok) puts("3");
		}
		else
		{
			long long ans=0;
			for (int i=1;i<n;i++)
				for (int j=i+1;j<=n;j++)
					if (a[j] && gcd(a[i],a[j])==a[i])
						a[j]=0;
			for (int i=1;i<=n;i++)
				if (a[i])
					ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
