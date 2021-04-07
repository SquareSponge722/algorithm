#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[2][2],p[100010];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	char type[10];
	scanf("%d%d%s",&n,&m,type);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
	}
	if(type[0]=='A')
	{
		for(int i=1;i<=m;i++)
		{
			int a,x,b,y;
			scanf("%d%d%d%d",&a,&x,&b,&y);
			memset(f,0x3f,sizeof(f));
			f[1][0]=0,f[1][1]=p[1];
			for(int i=1;i<=n;i++)
			{
				f[i&1][0]=f[(n-1)&1][1];
				f[i&1][1]=min(f[(n-1)&1][1]+p[i],f[(n-1)&1][0]+p[i]);
				if(i==a)f[i&1][(x+1)%2]=99999999;
				if(i==b)f[i&1][(x+1)%2]=99999999;
			}
			printf("%d\n",min(f[n&1][1],f[n&1][0]));
		}
	}
	return 0;
}