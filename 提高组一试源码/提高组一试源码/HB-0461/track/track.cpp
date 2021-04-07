#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;
int n,m,a,b,l,cnt,ans,st,zs;
int head[maxn];
int le[maxn];
bool v[maxn];
struct edge {
	int f,g,w,next;
} e[2*maxn];
void adde(int f,int g,int w) {
	e[++cnt].f=f;
	e[cnt].g=g;
	e[cnt].w=w;
	e[cnt].next=head[f];
	head[f]=cnt;
}
void dfs(int o,int num) {
	for(int i=head[o]; i; i=e[i].next) {
		int to=e[i].g;
		if(v[to]) continue;
		v[to]=1;
		dfs(to,num+e[i].w);
	}
	if(num>ans) {
		ans=num;
		st=o;
	}
}
bool cmp(int l,int r){
	if(le[l]==le[r]) return cmp(l+1,r-1);
	if(le[l]<le[r]) return 1;
	return 0;
}
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	bool flag=1;
	scanf("%d%d",&n,&m);
	for(int i=1; i<n; i++) {
		scanf("%d%d%d",&a,&b,&l);
		if(b!=a+1) flag=0;
		le[a]=l;
		zs+=l;
		adde(a,b,l);
		adde(b,a,l);
	}
	if(m==1) {
		v[1]=1;
		dfs(1,0);
		memset(v,0,sizeof(v));
		dfs(st,0);
		printf("%d\n",ans);
	}
	else if(flag==1){
		int l=1,r=n-1;
		while(m!=1){
			m--;
			if(cmp(l,r)==1){
				zs-=le[l];
				l++;
			}
			else{
				zs-=le[r];
				r--;
			}
		}
		printf("%d\n",zs);
	}
	return 0;
}
