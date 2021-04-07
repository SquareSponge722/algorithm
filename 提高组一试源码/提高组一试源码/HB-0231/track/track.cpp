#include<bits/stdc++.h>
using namespace std;
const int maxn = 50005;

int n,m;
bool jh=true;
bool lian=true;

struct edge{
	int v,w;
	edge(int a=0,int b=0){
		v=a,w=b;
	}
};
vector<edge> g[maxn];
int x,y,c;
edge ed[maxn];
int sig;
int fm[maxn];
int ansa,ansb;

bool cmp(edge a,edge b){
	return a.w>b.w;
}

void mian1(){
	for (int i=0;i<g[1].size();i++){
		ed[i+1] = g[1][i];
	}
	sort(ed+1,ed+n,cmp);
	printf("%d\n",ed[m].w);
}

bool check2(int x){
	int ret=0,sum=0;
	for (int i=1;i<=n-1;i++){
		if(sum+fm[i]>=x){
			ret++;sum=0;
		}
		else{
			sum+=fm[i];
		}
	}
	if(ret<m)return false;
	return true;
}

void mian2(){
	/*int tot=0;
	for (int i=1;i<n;i=g[i][0]){
		tot++;
		fm[tot] = g[i][0].w;
	}*/
	int l=0,r=sig;
	while(l<r-1){
		int mid=(l+r)/2;
		if(check2(mid))l=mid;
		else r=mid;
	}
	if(check2(r)){
		printf("%d\n",r);
	}
	else printf("%d\n",l);
}

int dfs(int x,int fa){
	int mm=0;
	for (int i=0;i<g[x].size();i++){
		if(g[x][i].v==fa)continue;
		mm = max(dfs(g[x][i].v,x)+g[x][i].w,mm);
	}
	return mm;
}

void dfs0(int x,int fa,int k){
	if(k>ansa){
		ansa=k;ansb=x;
	}
	for (int i=0;i<g[x].size();i++){
		if(g[x][i].v==fa)continue;
		dfs0(g[x][i].v,x,k+g[x][i].w);
	}
}


int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n-1;i++){
		cin>>x>>y>>c;
		if(x!=1)jh=false;
		if(y!=x+1)lian=false;
		g[x].push_back(edge(y,c));
		g[y].push_back(edge(x,c));
		sig+=c;
		fm[x] = c;
	}
	if(jh){
		mian1();return 0;
	}
	if(lian){
		mian2();return 0;
	}
	dfs0(1,0,0);
	printf("%d\n",dfs(ansb,0));
	
	return 0;
}
