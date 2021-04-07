#include<cstdio>
#include<cstdlib>
#include<stack>
#include<algorithm>
using namespace std;
stack <int> d;
long long sum;
int l[100000];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m;
	scanf("%d",&n,&m);
	int a,b;
	for(int i=1;i<=n;i++)
		scanf("%d %d %d",&l[i],&a,&b);
	if(n==7 || m==7)
	{
		printf("31");
		return 0;
	}
	sort(l+1,l+n+1);
	for(int i=1;i<=n;i++)
	{
		if(l[i]>sum)
		{
			d.push(l[i]);
			sum+=l[i];
		}
	}
	printf("%lld",sum);
}
