#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q;
inline int gcd(int a,int b) {
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int a[105]= {0};
int b[105];
int n,t;
bool pd[25005];
int maxn;
int f[2000][2005];
int num;
void dfs() {
	for(int i=0; i<num; i++)
		for (int j=1; j<=1234; j++) {
			if(f[i][j]==1) {
				int k=0;
				while(j+k*a[i+1]<=1234) {
					f[i+1][j+k*a[i+1]]=1;
					k++;
				}
			}
		}
}
bool cmp(const int &a,const int &b) {
	return a<b;
}
void solve() {
	num=1;
	memset(f,0,sizeof(f));
//	sort(b+1,b+n+1,cmp);
	a[1]=b[1];
	if(a[1]==1) {
		cout<<1<<endl;
		return;
	}
	int k=2;
	while(gcd(a[1],b[k])!=1)
		k++;
	maxn=a[1]*b[k]-a[1]-b[k];
//	cout<<maxn<<' ';
	for(int i=2; i<=n; i++) {
		bool ok=1;
		for(int j=1; j<=num; j++) {
			if(b[i]%a[j]==0||b[i]>maxn) {
				ok=0;
				break;
			}
			if(j==k)
				ok=1;
		}
		if(ok) {
			a[++num]=b[i];
		}
	}
//	for(int i=1;i<=num;i++)
//	cout<<a[i]<<' ';
	f[0][a[1]]=1;
	dfs();
	int ans=num;
	for(int i=1; i<=num; i++)
		if(f[num][a[i]])
			ans--;
	if(ans<=1&&n!=1) {
		cout<<2<<endl;
		return;
	}
//	for(int j=1; j<=50; j++) {
//		for(int i=1; i<=num; i++) {
//			cout<<f[i][j]<<' ';
//		}
//		cout<<j<<endl;
//	}
	cout<<++ans<<endl;
	return;
}
int main() {
//	int a,b;
//	cin>>a>>b;
//	cout<<gcd(a,b);
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		scanf("%d",&n);
		for(int j=1; j<=n; j++) {
			int k;
			scanf("%d",&k);
			q.push(-k);
		}
		for(int j=1; j<=n; j++) {
			b[j]=-q.top();
			q.pop();
		}
//		for(int j=1;j<=n;j++)
//		cout<<b[j];
		solve();
	}
	return 0;
}
