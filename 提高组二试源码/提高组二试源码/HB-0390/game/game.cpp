#include<bits/stdc++.h>
using namespace std;
long long int ans[10005];
int n,m;
int mo=1e9+7,sz[100005],sum,cnt,fail,a[100005],cntt,anss=1;
//void check() {
//	int sum=0;
//	for(int i=1,num=n+m-2; i<=n+m-1; i++,num--) {
//		if(ans[i])sum+=pow(2,num);
//	}
//	for(int i=1; i<=cnt; i++)
//		if(sum<sz[i]) {
//			fail=1;
//			return;
//		}
//	sz[++cnt]=sum;
//	return;
//}
//void dfs2(int step,int now) {
//	if(step==n+m-2) {
//		check();
//		return;
//	}
//	for(int i=0; i<=1; i++) {
//		if(!i) {
//			ans[step+1]=a[now+1];
//			dfs2(step+1,now+1);
//		} else ans[step+1]=a[now+m];
//		dfs2(step+1,now+m);
//	}
//}
//void dfs(int step) {
//	if(step==n*m+1) {
//		cnt=0;
//		fail=0;
//		memset(sz,0,sizeof(sz));
//		ans[1]=1;
//		dfs2(1,1);
//		if(!fail) {
//			for(int i=1; i<=n*m; i++) {
////				cout<<a[i]<" ";
////				if(!(i%m))cout<<endl;
//				cntt++;
//			}
//		}
//		return;
//	}
//	for(int i=0; i<=1; i++) {
//		a[step]=i;
//		dfs(step+1);
//		a[step]=-1;
//	}
//	return;
//}
//void work1() {
//	dfs(1);
//	return;
//}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1) {
		cout<<2;
		return 0;
	}
	for(int i=2; i<=n; i++) {
		anss*=i*i;
		anss%=mo;
	}
	anss*=n+1;
	anss%=mo;
	for(int i=1; i<=m-n; i++) {
		anss*=n+1;
		anss%=mo;
	}
	cout<<anss;
	return 0;
}
