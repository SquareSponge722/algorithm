#include<bits/stdc++.h>
using namespace std;
int m,n,cost[100005];
string ty;
queue<int> q;
vector<int> path[100005];
int pd[100005],pass[100005];
int ans[100005],ls;
bool work(int x) {
	if(pd[x]!=-1) pass[x]=1;
	for(int i=0; i<path[x].size(); i++) {
		if(pd[path[x][i]]==1) continue;
		if(pd[x]==-1&&pd[path[x][i]]==-1) return 1;
		return work(path[x][i]);
	}
	if(pd[x]!=-1) pass[x]=0;
}
void dfs(int x) {
	for(int i=0; i<path[x].size(); i++) {
		if(pd[x]==1) pd[path[x][i]]=1;
		if(pd[path[x][i]]==1) continue;
		if(ans[path[x][i]]>ans[x]+cost[x]) {
			ans[path[x][i]]=ans[x]+cost[x];
			ls=x;
		}
		dfs(path[x][i]);
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>ty;
	for(int i=1; i<=n; i++) {
		scanf("%d",&cost[i]);
	}
	for(int i=1; i<=n-1; i++) {
		int from,to;
		scanf("%d%d",&from,&to);
		path[from].push_back(to);
		path[to].push_back(from);
	}
	for(int i=1; i<=m; i++) {
		int x1,x2,pd1,pd2;
		scanf("%d%d%d%d",&x1,&pd1,&x2,&pd2);
		pd1=pd1==0?-1:1;
		pd2=pd2==0?-1:1;
		pd[x1]=pd1,pd[x2]=pd2;
		if(pd1==1) q.push(x1);
		if(pd2==1) q.push(x2);
		if(work(x1)==1) {
			printf("-1\n");
			continue;
		}
		dfs(x1);
		printf("%d",ans[ls]);
		memset(pd,0,sizeof(pd));
		memset(pass,0,sizeof(pass));
	}
	return 0;
}
