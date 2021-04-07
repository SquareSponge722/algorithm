#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+55;
int n,d[maxn],a[maxn],k[maxn],t[maxn];
inline int min(int a,int b)
{
	return a<b?a:b;
}
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]),k[i]=d[i];
	sort(k+1,k+n+1,cmp);
	int num=1;
	for(int i=1;i<=n;i++)
	{
		if(k[i]!=k[i-1]&&k[i])
		t[num]=k[i],num++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!t[i]) break;
		int tot=0;
		for(int j=1;j<=n;j++)
		{
			if(d[j]&&d[j-1]==0) tot++;
		}
		for(int k=1;k<=n;k++)
		if(d[k]) d[k]-=t[i]-t[i-1];
		ans+=(t[i]-t[i-1])*tot;
	}
	printf("%d",ans);
	return 0;
}
