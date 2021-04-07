#include<bits/stdc++.h>
using namespace std;
const int N=500010;
struct node
{
	int a,b,l;
	bool operator < (const node&other) const
	{
		return l<other.l;		
	}
}d[N];
int main ()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d",&d[i].a,&d[i].b,&d[i].c);
	sort(d+1,d+1+n);
	long long ans=0;
	for(int i=1;i<n;i++)

		for(int j=n;j>0;j--)
			ans+=d[j].l;
	printf("%lld",ans);
	return 0;
}
