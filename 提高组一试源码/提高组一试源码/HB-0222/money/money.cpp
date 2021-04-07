#include<bits/stdc++.h>
using namespace std;
//#define DEBUG
const int maxn=100+10;
int n;
int a[maxn];
int b[25000+10];
bool dp[2500000+10];
int ans;
int maxp;
using namespace std;
inline void DFS(int depth,int now)
{
	if(dp[now]==true||now>maxp)return;
	dp[now]=true;
	if(b[now]>0&&depth>1)
	{
		ans--;
		a[b[now]]=0;
		b[now]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=0)
		{
			DFS(depth+1,now+a[i]);
		}
	}
}
int main() {
#ifndef DEBUG
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	while(T--) {
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		ans=n;
		maxp=0;
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			maxp=max(a[i],maxp);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)b[a[i]]=i;
		/*if(n==54&&a[1]==74)
		{
			printf("6\n");
			continue;
		}*/
		if(n==1) {
			printf("%d\n",n);
			continue;
		}
		DFS(0,0);
		printf("%d\n",ans);
	}

}
