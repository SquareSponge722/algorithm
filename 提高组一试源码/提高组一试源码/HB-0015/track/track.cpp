#include<bits/stdc++.h>
using namespace std;
const int N=30006;
int n,tot=1,m;
int ver[2*N],edge[2*N],nxt[2*N],head[N];
long long ans=0,d[N];
bool v[2*N];
void dp(int x) {
	if(v[x])return;
	v[x]=1;
	for(int i=head[x];i;i=nxt[i]) {
		int y=ver[i];
		if(v[y])continue;
		dp(y);
		ans=max(ans,d[y]+edge[i]+d[x]);
		d[x]=max(d[y]+edge[i],d[x]);
	}
}
void add(int x,int y,int z){
	ver[++tot]=y;edge[tot]=z;
	nxt[tot]=head[x];head[x]=tot;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(head,0,sizeof(head));
	for(int i=1; i<n; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dp(1);
	cout<<ans<<endl;
	return 0;
}
