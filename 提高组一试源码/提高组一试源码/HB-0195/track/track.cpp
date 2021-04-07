#include <cstdio>
#include <cstring>
using namespace std;
const int ING=-2147483647;//tt
int n,m,ans,a[3001][3001];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int i,j,k;//hgh
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			a[i][j]=ING;
	for(i=1;i<=n-1;i++)
	{
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		a[p][q]=r;
		a[q][p]=r;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				if(i!=j&&j!=k&&k!=i&&a[i][j]<a[i][k]+a[k][j])
					a[i][j]=a[i][k]+a[k][j];
	ans=ING;
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
			if(a[i][j]>ans)
				ans=a[i][j];
	}
	printf("%d",ans);
	return 0;
}
