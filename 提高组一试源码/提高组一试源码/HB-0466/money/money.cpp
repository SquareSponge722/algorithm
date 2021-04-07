#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
using namespace std;
int a[N];
bool f[1000010],af[1000010];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(af,0,sizeof(af));
		int n,i,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++){scanf("%d",&a[i]);f[a[i]]=af[a[i]]=true;}
		sort(a+1,a+n+1);
		int ans=n;
		for(i=1;i<=a[n];i++)
			if(f[i])
				for(j=i;i+j<=a[n];j++)
					if(f[j])
					{
						if(af[i+j])ans--,af[i+j]=false;
						else f[i+j]=true;
					}
		printf("%d\n",ans);
	}
	return 0;
}
