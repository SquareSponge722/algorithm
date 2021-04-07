#include <cstdio>
long long p[200005];
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,kind,a,b,x,y;
	char op;
	scanf("%d%d ",&n,&m);
	scanf("%c%d",&op,&kind);
	if(op=='A')
	{
		long long even=0,odd=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&p[i]);
			if(i%2==1)
				even+=p[i];
			else
				odd+=p[i];
		}
		for(int i=1;i<n;i++)
			scanf("%d%d",&a,&b);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&a,&x,&b,&y);
			if((a%2!=b%2 && x==y) || (a%2==b%2 && x!=y))
			{
				printf("-1\n");
				continue;
			}
			else
			{
				int t=a%2;
				if(x==1)
				{
					if(t==1)
						printf("%lld\n",even);
					else
						printf("%lld\n",odd);
				}
				else
				{
					if(t==0)
						printf("%lld\n",even);
					else
						printf("%lld\n",odd);
				}
			}
		}
	}
	return 0;
}