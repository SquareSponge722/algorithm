#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=110;
int t,n,ans;
int a[N];
bool vis[25050];
bool jud(int);
bool dfs(int,int);
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);ans=n;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
			for(int j=a[i]+a[i];j<=a[n];j+=a[i])
				vis[j]=1;
		for(int i=2;i<=n;i++)
			if(jud(i)) ans--;
		printf("%d\n",ans);
	}
	return 0;
}
bool jud(int k)
{
	if(vis[a[k]]) return true;
	if(dfs(a[k],k)) return true;
	vis[a[k]]=1;
	return false;
}
bool dfs(int num,int pos)
{
	if(vis[num]) return true;
	for(int i=1;i<pos;i++)
	{
		if(num-a[i]==0) return true;
		if(num-a[i]>0)
			if(dfs(num-a[i],pos)) return true;
	}
	return false;
}
