#include<bits/stdc++.h>
#define N 20
using namespace std;
int m,n;
long long ans=0;
char c[2];
int p[N];
int g[N][N];
void init()
{
	memset(g,0,sizeof(g));
	scanf("%d %d",&n,&m);
	for(int i=1; i<n; i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u][v]=1;
	}
}
int main ()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	init();
	while(m--)
	{
		int a,x,b,y;
		scanf("%d %d %d %d",&a,&x,&b,&y);
		if(c[0]=='A')
		{

			if(a%2!=b%2)
				printf("-1\n");
			else
			{
				if(x==1)
				{
					for(int i=a; i>0; i-=2)
					{
						ans+=i;
					}
					for(int i=a; i<=n; i+=2)
						ans+=i;
					ans+=a;
				}
				if(y==1)
				{
					for(int i=b; i>0; i-=2)
						ans+=i;
					for(int i=b; i<=n; i+=2)
						ans+=i;
					ans+=b;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
