#include<bits/stdc++.h>
#define add(x,y) edge[++cnt]=node(y,head[x]),head[x]=cnt
struct node {
	int ver,to;
	node(int ver=0,int to=0):ver(ver),to(to) {}
};
using namespace std;
const int MAXN=5010;
inline char nc() {
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
int read() {
	int x=0;
	char c=nc();
	while(!isdigit(c))c=nc();
	while(isdigit(c))x=x*10+c-48,c=nc();
	return x;
}
node edge[MAXN<<1];
int head[MAXN],cnt=-1;
vector<int> q[MAXN];
void dfs(int u,int fa) {
	printf("%d ",u);
	for(int i=head[u]; i!=-1; i=edge[i].to) {
		if(edge[i].ver==fa)continue;
		q[u].push_back(edge[i].ver);
	}
	sort(q[u].begin(),q[u].end());
	for(int i=0; i<q[u].size(); i++)dfs(q[u][i],u);
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n=read(),m=read();
	int u,ver,val;
	for(int i=0; i<m; i++) {
		u=read();
		ver=read();
		add(u,ver);
		add(ver,u);
	}
	dfs(1,0);
}
