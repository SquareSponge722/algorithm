#include<cstdio>
#include <algorithm>
using namespace std;
int n,a[100010],sx;
int min=999999;int num[10010];
long long ans=0;
struct str{
	int x,w;
}e[100010];
bool cmp(str a,str b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		e[i].x=i;e[i].w=i;
		if(i==1)continue;
		if(a[i-1]-a[i]>0)
		ans+=a[i-1]-a[i];
	}
	ans+=a[n];
	/*sort(e+1,e+1+n,cmp);
	ans+=e[1].w;
	rec+=num[e[1].w];
	int duan=1;
	for(int i=1;i<=num[e[1].w];i++)
	{
		if(e[i].x!=1&&e[i].x!=n)
			duan++;
	}
	while(rec<=n)
	{
		ans+=
	}*/
	printf("%lld",ans);
}
