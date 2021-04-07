#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=50005;
const int maxe=100005;

int n,m,cnt;
int head[maxn],eu[maxe],ew[maxe],ev[maxe],nxt[maxe];
int a[maxn],dis[maxn];

void adde(int u,int v,int w) {
	++cnt;
	eu[cnt]=u;ev[cnt]=v;ew[cnt]=w;nxt[cnt]=head[u];head[u]=cnt;
}

bool check(int mid) {
	int num,len;
	num=0;len=0;
	for(int i=1;i<n;i++) {
		len+=a[i];
		if(len>=mid) num++,len=0;
	}
	if(num>=m) return true;
	return false;
}

void dfs(int u,int fa) {
	for(int i=head[u];i;i=nxt[i]) {
		int v=ev[i];
		if(fa==v) continue;
		dis[v]=dis[u]+ew[i];
		dfs(v,u);
	}
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int u,v,w,l,r,mid;
	scanf("%d%d",&n,&m);
	l=0;r=0;
	for(int i=1;i<n;i++) {
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);adde(v,u,w);a[u]=w;
		r+=w;
	}
	if(m!=1) {
		while(l<=r) {
			mid=l+r>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		}
		printf("%d",l-1);
	}else {
		int mr,mlen;
		dis[1]=0;
		dfs(1,1);
		mlen=0;
		for(int i=1;i<=n;i++) 
			if(mlen<dis[i]) mlen=dis[i],mr=i;
		mlen=0;memset(dis,0,sizeof dis);
		dis[mr]=0;
		dfs(mr,mr);
		for(int i=1;i<=n;i++) if(mlen<dis[i]) mlen=dis[i];
		printf("%d",mlen);
	}
}
