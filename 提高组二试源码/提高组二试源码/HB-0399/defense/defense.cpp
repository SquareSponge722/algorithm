#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=100001;
int n,m;
char type[3];
int cost[maxn];
void zswap(int &x,int &y) {
	int t=x;
	x=y;
	y=t;
}

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin >> n >> m >> type;
	for(int i=1;i<=n;i++) cin >> cost[i];
	for(int i=1;i<n;i++) {
		int u,v;
		cin >> u >> v;
	}
	int ans=0;
	for(int i=1;i<=m;i++) {
		int a,x,b,y;
		cin >> a >> x >> b >> y;
		if(a>b) {
			swap(a,b);
			swap(x,y);
		}
		if(x==0&&y==0&&b-a==1) cout << -1 << endl;
		else {
			ans+=(cost[a]*x+cost[b]*y);
			if(x==1&&y==1) {
				int j=a,k=b;
				while(j>=1&&k<=n) {
					ans+=min(cost[j-1],cost[j-2]);
					j-=2;
					ans+=min(cost[k+1],cost[k+2]);
					k+=2;
				}
				j=a,k=b;
				while(j<=k) {
					ans+=min(cost[j+1],cost[j+2]);
					j+=2;
					ans+=min(cost[k-1],cost[k-2]);
					k-=2;
				}
			} else if(x==0&&y==1) {
				if(a+1!=b) ans+=(cost[a+1]+cost[a-1]);
				int j=a,k=b;
				while(j>=1&&k<=n) {
					ans+=min(cost[j-1],cost[j-2]);
					j-=2;
					ans+=min(cost[k+1],cost[k+2]);
					k+=2;
				}
				j=a,k=b;
				while(j<=k&&j!=a&&k!=b) {
					ans+=min(cost[j+1],cost[j+2]);
					j+=2;
					ans+=min(cost[k-1],cost[k-2]);
					k-=2;
				}
			} else if(x==1&&y==0) {
				if(a+1!=b) ans+=(cost[b-1]+cost[b+1]);
				int j=a,k=b;
				while(j>=1&&k<=n) {
					ans+=min(cost[j-1],cost[j-2]);
					j-=2;
					ans+=min(cost[k+1],cost[k+2]);
					k+=2;
				}
				j=a,k=b;
				while(j<=k&&j!=a&&k!=b) {
					ans+=min(cost[j+1],cost[j+2]);
					j+=2;
					ans+=min(cost[k-1],cost[k-2]);
					k-=2;
				}
			} else {
				if(a+1!=b) {
					ans+=(cost[a+1]+cost[a-1]);
					ans+=(cost[b-1]+cost[b+1]);
				}
				int j=a,k=b;
				while(j>=1&&k<=n) {
					ans+=min(cost[j-1],cost[j-2]);
					j-=2;
					ans+=min(cost[k+1],cost[k+2]);
					k+=2;
				}
				j=a,k=b;
				while(j<=k&&j!=a&&k!=b) {
					ans+=min(cost[j+1],cost[j+2]);
					j+=2;
					ans+=min(cost[k-1],cost[k-2]);
					k-=2;
				} 
			}
			cout << ans << endl;
			ans=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
