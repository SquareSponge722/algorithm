#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=5050;
priority_queue<int,vector<int>,greater<int> >q;
struct node{
	int nu,ne;
}edge[N*2];
vector<int>ne[N];
int head[N],f[N],tot,n,m;
bool vis[N],fl[N],flag[N];
void add(int a,int b){
	edge[++tot].nu=b;
	edge[tot].ne=head[a];
	head[a]=tot;
}
void solve1(int u,int fa){
	printf("%d ",u);
	for(int i=head[u];i!=-1;i=edge[i].ne){
		int v=edge[i].nu;
		if(v==fa)continue;
		ne[u].push_back(v);
	}
	sort(ne[u].begin(),ne[u].end());
	for(int i=0;i<ne[u].size();i++){
		int v=ne[u][i];
		solve1(v,u);
	}
}
void solve2(){
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	if(m==n-1)solve1(1,-1);
	return 0;
}
