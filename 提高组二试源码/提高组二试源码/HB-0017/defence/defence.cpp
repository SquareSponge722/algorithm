#include<bits/stdc++.h>
using namespace std;
int n,m;
string type;
const int maxn=100001;
int p[maxn],q[maxn],c[maxn],a[maxn],x[maxn],b[maxn],y[maxn];
int ans[maxn];
int main()
{
	freopen("defence.in","r",stdin);
	freopen("defence.out","w",stdout);
	scanf("%d %d %s\n",&n,&m,&type);
	for(int i=1;i<=n;i++)
	scanf("%d ",&p[i]);
	for(int i=1;i<n;i++)
	scanf("%d %d\n",&q[i],&c[i]);
	for(int i=1;i<=m;i++)
	scanf("%d %d %d %d\n",&a[i],&x[i],&b[i],&y[i]);
	for(int i=1;i<=m;i++)
	{
		/*if(a[i]+b[i]>n&&x[i]==0&&y[i]==0)
		{
			ans[i]=-1;
		}*/
		if(x[i]==1&&y[i]==1)
		{
			if(b[i]-a[i]>=3)
			ans[i]=-1;
			else ans[i]=p[a[i]]+p[b[i+1]];
		}
		if(x[i]==0&&y[i]==0)
		{
			if(b[i]-a[i]>=3)
			ans[i]=-1;
			else ans[i]=p[a[i+1]]+p[b[i]];
		}
		if(x[i]==1&&y[i]==0)
		{
			ans[i]=p[a[i+1]]+p[b[i-1]];
		}
		if(x[i]==0&&y[i]==1)
		{
			ans[i]=p[a[i-1]]+p[b[i+1]];
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d\n",ans[i]);
	return 0;
}
