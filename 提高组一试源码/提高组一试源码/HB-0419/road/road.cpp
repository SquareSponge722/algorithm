#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int n;
int k,flag,mmin,sum,t;
void fuck(int t)
{
	mmin=99999999;
	if(a[t]<=0)
		return;
	for(int i=t;i<=n&&a[i]>0;i++)
		if(a[i]>0&&a[i]<mmin)
			mmin=a[i];
	for(int i=t;i<=n&&a[i]>0;i++)
		a[i]-=mmin;
	sum+=mmin;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		while(a[i]!=0)
			fuck(i);
	printf("%d",sum);
	return 0;
}