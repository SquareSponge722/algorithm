#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 50005

int n, m, head[maxn], tail, ans[maxn], len[maxn], arr[maxn], vis[maxn];

struct edge {
	int v,w,next;
}edges[maxn<<1];

void add_edge(int u,int v,int w) {
	edges[++tail].v=v;
	edges[tail].w=w;
	edges[tail].next=head[u];
	head[u]=tail;
}

int calc(int tl, int lim) {
	int p2=1; int ret=0;
	for (int i=tl;i>p2;i--) {
		if (vis[i]) continue;
		while (p2<i&&(arr[p2]+arr[i]<lim||vis[p2])) p2++;
		if (p2<i&&!vis[p2]&&arr[i]+arr[p2]>=lim) ret+=1;
		p2++;
	}return ret;
}

void dfs(int u, int f, int lim) {
	ans[u]=0;
	for (int i=head[u];i;i=edges[i].next) {
		if (edges[i].v==f) continue;
		len[edges[i].v]=edges[i].w;
		dfs(edges[i].v, u, lim);
		ans[u]+=ans[edges[i].v];
	}int tl=0; 
	for (int i=head[u];i;i=edges[i].next) {
		if (edges[i].v==f)continue;
		arr[++tl]=len[edges[i].v];
	}if (tl>0)	{
		std::sort(arr+1,arr+tl+1); arr[0]=0;
		int vl=calc(tl,lim); ans[u]+=vl;
		int lb=0, rb=tl, res;
		while (lb<=rb) {
			int mid=(lb+rb)>>1;
			vis[mid]=1;
			if (calc(tl,lim)==vl){
				res=mid; lb=mid+1;
			}else rb=mid-1;
			vis[mid]=0;
		}len[u]+=arr[res];
	}if (len[u]>=lim) {len[u]=0; ans[u]++;}
//	printf("%d:%d %d\n", u, len[u],ans[u]);
}

int check(int v) {
//	printf("checking:%d\n", v);
	std::memset(ans,0,sizeof(ans));
	std::memset(len,0,sizeof(len));
	dfs(1, 0, v);
	return ans[1]>=m;
}

int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	std::memset(vis,0,sizeof(vis));
	tail=0;std::memset(head,0,sizeof(head));
	int l=1; int r=0;
	int u,v,w,ret;
	scanf("%d %d", &n, &m);
	for (int i=1;i<n;++i) {
		scanf("%d %d %d", &u, &v, &w); r+=w;
		add_edge(u, v, w);add_edge(v, u,w);
	}while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) {ret=mid; l=mid+1;}
		else r=mid-1;
	}printf("%d", ret);
	return 0;
}

