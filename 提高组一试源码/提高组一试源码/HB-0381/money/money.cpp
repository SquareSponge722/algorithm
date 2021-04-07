#include<cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,a[100010],sx;
int min=999999;int num[10010];
long long ans=0;
int maxx=0;
int T;
struct str{
	int x,w;
}e[100010];
bool cmp(str a,str b)
{
	return a.w<b.w;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		maxx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		if(n==2)
		{
			int ans=2;
			if(a[2]%a[1]==0)
				ans=1;
			printf("%d\n",ans);
			continue;
		}
		int ans=n;
		for(int m=2;m<=n;m++){
			int flag=0;
			for(int i=1;i<=m;i++)
			{
				if(i==m)continue;
				for(int j=1;j<=m;j++)
				{
					if(j==m)continue;
					for(int q=1;q<=m;q++)
					{
						if(q==m)continue;
						for(int l=0;l<=(a[m]/a[i])+1&&l*a[i]<=a[m];l++){
							for(int r=0;r<=(a[m]/a[j])+1&&r*a[j]<=a[m];r++){
								for(int t=0;t<=(a[m]/a[q])+1&&t*a[q]<=a[m];t++)
								if(a[m]==a[i]*l+a[j]*r+a[q]*t)
								{
									ans--;flag=1;
									break;
								}
								if(flag)
								break;
							}
								if(flag)
								break;
							}
						if(flag)
							break;
					}
				if(flag)
					break;
				}
				if(flag)
					break;
			}
		}
		printf("%d\n",ans);
	}
	
}
