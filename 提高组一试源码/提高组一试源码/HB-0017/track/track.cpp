#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int a[maxn],b[maxn],l[maxn];
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<n;i++)
	scanf("%d %d %d\n",a[i],b[i],l[i]);
	sort(l+1,l+n+1);
	ans=l[n]+l[n-1];
	cout<<ans;
}
