#include<bits/stdc++.h>
using namespace std;
int m,minn,n,f1,f2,sum[50005],dp[5005][5005],a[50005];
int min(int a,int b) {
	return a<b?a:b;
}
int max(int a,int b) {
	return a>b?a:b;
}
struct yuansu {
	int l,r,len;
} bian[50005];
int cmp(yuansu a,yuansu b) {
	return a.len<b.len;
}
void work1() {
	minn=1e9;
	sort(bian+1,bian+n,cmp);
	for(int i=n-m,num=n-1; i<=n-1&&i>=num; i++,num--) {
		minn=min(minn,bian[i].len+bian[num].len);
	}
	cout<<minn;
	return;
}
int dfs(int r,int cishu) {
	if(r<1)return 0;
	if(r==1&&cishu!=m)return 0;
	if(cishu==m)return sum[r];
	if(dp[r][cishu]!=-1)return dp[r][cishu];
	int ans=0;
	for(int i=1; i<=r; i++) {
		ans=max(ans,min(dfs(i,cishu+1),sum[r]-sum[i]));
	}
	return dp[r][cishu]=ans;
}
void work2() {
	memset(dp,-1,sizeof(dp));
	for(int i=1; i<=n-1; i++)
		a[bian[i].l]=bian[i].len;
	for(int i=1; i<=n-1; i++)
		sum[i]=sum[i-1]+a[i];
	cout<<dfs(n-1,1);
	return;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	f1=1;
	f2=1;
	for(int i=1; i<=n-1; i++) {
		cin>>bian[i].l>>bian[i].r>>bian[i].len;
		if(bian[i].l!=1)f1=0;
		if(bian[i].l!=bian[i].r-1)f2=0;
	}
	if(m==1) {
		int sum=0;
		for(int i=1;i<=n-1;i++)
		sum+=bian[i].len;
		cout<<sum;
		return 0;
	}
	if(f1) {
		work1();
		return 0;
	} else if(f2)
		work2();
	return 0;
}
/*
6 3
1 2 4
2 3 3
3 4 1
4 5 9
5 6 7

6 3
1 2 3
1 3 4
1 4 5
1 5 6
1 6 7
*/
