#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m,a,b;
struct node{
	int to;
	int p;
};
bool cmp(node a,node b){
	return a.to<b.to;
}
vector<node>t[5005];
node c;
bool pd[5005];
void dfs(int now){
	printf("%d ",now);
	sort(t[now].begin(),t[now].end(),cmp);
	for(int i=0;i<t[now].size();i++){
		if(pd[t[now][i].p]!=1){
			pd[t[now][i].p]=1;
			dfs(t[now][i].to);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			c.p=i;
			c.to=b;
			t[a].push_back(c);
			c.to=a;
			t[b].push_back(c);
		}
		dfs(1);
	}
	
}
