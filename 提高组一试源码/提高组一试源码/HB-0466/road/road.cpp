#include<cstdio>
#define N 100010
int a[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;bool up=false;
	for(i=1;i<=n+1;i++)
	{
		if(!up&&a[i]>a[i-1])ans-=a[i-1],up=true;
		else if(up&&a[i]<a[i-1])ans+=a[i-1],up=false;
	}
	printf("%d",ans);
	return 0;
}
