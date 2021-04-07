#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int const N=101;
long long d[N];
long long n,t,cou;
void inn()
{
	for(long long i=1;i<=n;i++)
		d[i]=0;
	scanf("%lld",&n);
	cou=n;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
	}
}
bool dfs1(long long cs,long long he,long long fi)
{
	if(cs>=fi||he>d[fi])
		return false;
	else
	{
		if(he==d[fi])
			return true;
		else
		{
			if(dfs1(cs,he+d[cs],fi))
				return true;
			if(dfs1(cs+1,he,fi))
				return true;
			return false;
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		inn();
		sort(d+1,d+n+1);
		for(long long i=2;i<=n;i++)
		{
			if(dfs1(1,0,i))
				cou--;
		}
		printf("%lld\n",cou);
	}
	return 0;
}
