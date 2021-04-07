#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 3001
using namespace std;
int f[N][N];
int maxn,n,m;
struct node
{
	int a;
	int b;
	int len;
}z[N];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d %d",&z[i].a,&z[i].b,&z[i].len);
		f[z[i].a][z[i].b]=z[i].len;
		f[z[i].b][z[i].a]=z[i].len;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][j]<f[i][k]+f[k][j]);
				{
					f[i][j]=f[i][k]+f[k][j];
				}
				maxn=max(maxn,f[i][j]);
			}
		}
	}
	printf("%d",maxn);
	return 0;
}
