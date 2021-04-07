#include<bits/stdc++.h>
using namespace std;
int n;
long long d[100050];
long long dfs(int l,int r)
{
	int minn=1000005,pos=0;
	if(l>r) return 0; 
	if(l==r) return d[l];
	for(int i=l;i<=r;i++)
		{
			if(minn>d[i])
			   {
			   	minn=d[i];
			   	pos=i;
			   }
		}
	for(int i=l;i<=r;i++)
		{
			d[i]-=minn;
		}
	return minn+dfs(l,pos-1)+dfs(pos+1,r);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		{
		scanf("%lld",&d[i]);
		}
	cout<<dfs(1,n)<<endl;
	return 0;
}
