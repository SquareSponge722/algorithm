#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
int d[N];
int n,minnum,mind=N;
int ans;
using namespace std;
void F(int l,int r)
{
	if(l>r)  return;
	if(l==r) {ans+=d[l];d[l]=0;}
	if(l<r)
	{
			mind=N;
		for(int i=l;i<=r;i++)
		  if(mind>d[i])
		  {
		  	  mind=d[i];
		  	  minnum=i;
		  }
		ans+=mind;
		for(int i=l;i<=r;i++)
		  d[i]-=mind;
		F(l,minnum-1);
		F(minnum+1,r);
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	F(1,n);
	printf("%d",ans);
	return 0;
}
