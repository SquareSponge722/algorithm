#include<bits/stdc++.h>
using namespace std;
const int N=100020;
int n,flag[N],a[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(flag,0,sizeof(flag));
		int mx=0,less=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),flag[a[i]]=-1,mx=mx>a[i]?mx:a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=mx;i++)
		{
			if(flag[i])
			{
				for(int j=1;j<=n;j++)
				{
					if(flag[i+a[j]]==-1)less++;
					flag[i+a[j]]=1;
				}
			}
		}
		printf("%d\n",n-less);
	}
}
