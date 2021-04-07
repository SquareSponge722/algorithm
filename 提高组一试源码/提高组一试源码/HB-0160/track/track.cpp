#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
const int maxn = 50005;
//int maxw = 0,minw = maxn;
int read(){
	int re = 0,ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) re = (re<<1) + (re<<3) + ch - '0',ch = getchar();
	return re;
}
int n,m,ans[maxn],maxd;//deg[maxn],st;
struct edge{
	int v,w,nxt;
}e[maxn<<1];
int h[maxn],cnt,d[maxn];
void add(int u,int v,int w){
	e[++cnt].v = v,e[cnt].w = w,e[cnt].nxt = h[u],h[u] = cnt;
	e[++cnt].v = u,e[cnt].w = w,e[cnt].nxt = h[v],h[v] = cnt;
}
void dfs(int u,int fa){
	for(int i = h[u];i;i = e[i].nxt){
		int v = e[i].v;
		if(v != fa){
			d[v] = d[u] + e[i].w;
			maxd = max(d[v],maxd);
			dfs(v,u);
		}
	}
}
/*bool check(int mlen){
	int num = m,nlen = 0;
	for(int i = st;;i = e[h[st]].v){
		int nedge = h[i];
		if(nlen < mlen) nlen += e[nlen].w;
		else nlen = 0,num--;
		if(!num || (deg[i] == 1 && i != st)) break;
	}
	return !num;
}*/
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n = read(),m = read();
	for(int i = 1,u,v,w;i < n;i++){
		u = read(),v = read(),w = read();
		add(u,v,w);
		//deg[u]++;
		//deg[v]++;
		//maxw += w;
		//minw = min(minw,w);
	}
	//printf("good\n");
	if(m == 1){
		//printf("%d\n",cnt);
		cnt = 0;
		for(int i = h[1];i;i = e[i].nxt){
			maxd = e[i].w;
			d[e[i].v] = e[i].w;
			dfs(e[i].v,1);
			ans[++cnt] = maxd;
		}
		sort(ans + 1,ans + cnt + 1);
		//printf("%d %d\n",ans[2],ans[1]);
		printf("%d\n",ans[cnt] + ans[cnt-1]);
	}/*else{
		for(int i = 1;i <= n;i++)
			if(deg[i] == 1) st = i;
		int l = minw,r = maxw,mid,ans;
		while(l <= r){
			mid = (l + r >> 1);
			printf("%d %d\n",l,r);
			if(check(mid)) ans = mid,r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n",ans);
	}*/
	return 0;
}
