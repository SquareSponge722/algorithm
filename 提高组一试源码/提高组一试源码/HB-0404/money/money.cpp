#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int bk[250010];
int a[2001];
int n;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(bk,0,sizeof(bk));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		int mxn=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mxn=max(mxn,a[i]);
		}
		sort(a+1,a+n+1);
		int cur=0;
		bk[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(bk[a[i]]==0)
			{
				cur++;
				for(int j=a[i];j<=mxn;j++)
					bk[j]=max(bk[j],bk[j-a[i]]);
			}
		}
		printf("%d\n",cur);
	}
	return 0;
}
