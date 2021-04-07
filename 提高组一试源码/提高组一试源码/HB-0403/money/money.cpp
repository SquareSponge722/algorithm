#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
int maxn=110;
int maxw=10000;
int T;
int n,a[max],a,ans,init(),sort;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n+1);
		mx=a[n];
		f[0]=true;
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]])
			continue;
			ans++;
			for(int j=a[i];j<=mx;j++)
			if(f[j-a[i]])
			f[j]=true;
		}
		printf("%d",ans);
	}
	return 0;
}
