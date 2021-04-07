#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=105;
int T,n,a[maxn],b[maxn];
bool pd[105][25005];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(pd,0,sizeof(pd));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&a[i]);
			b[i]=1;
		}
		sort(a+1,a+1+n);
		int cnt=n;
		for(int i=2; i<=n; i++)
		{
			for(int j=1; j<i; j++)
			{
				if(b[j])
				{
					int val=a[i]%a[j];
					if(val==0)
					{
						cnt--;
						b[i]=0;
						pd[j][0]=1;
						break;
					}
					else if(pd[j][val])
					{
						cnt--;
						b[i]=0;
						break;
					}
					pd[j][val]=1;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
