#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define N 100000+10
using namespace std;
int n,d[N],num,a[N],l1,r1,l2,r2,flag[N];
void dfs(int l,int r)
{
	int sum=0,cnt=1;
	for(int i=l;i<=r;i++)sum+=a[i];
	if(sum==0)return ;
	int t=0,minv=99999;
	for(int i=l;i<=r;i++)
	if(minv>a[i]&&a[i]!=0){minv=a[i];t=i;}
	for(int i=1;i<=n;i++)
	if(flag[i]==0&&flag[i+1]==1)cnt++;
	num+=(cnt*minv);
	for(int i=1;i<=n;i++)a[i]-=minv;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0&&!flag[i])
		{
			flag[i]=1;
			l1=l;r1=t-1;
			l2=t+1;r2=r;
		}
	}
	dfs(l1,r1);
	dfs(l2,r2);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int i=1;i<=n;i++)a[i]=d[i];
	dfs(1,n);
	cout<<num;
	return 0;
}
