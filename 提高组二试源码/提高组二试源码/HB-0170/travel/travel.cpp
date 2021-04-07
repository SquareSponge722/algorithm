#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

struct node{
	int next,to;
}edge[5005];
int head[5005],cnt;

void add(int u,int v){
	edge[++cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n,m;
int q[5005],top;
int ans[5005];
int last[5005];
bool vis[5005];

bool dfs(int u){
	if(top == n+1){
		bool tag = 0;
		for(ri i = 1;i <= n;i ++){
			if(q[i] == ans[i])
				continue;
			if(q[i] < ans[i]){
				tag = 1;
				break;
			}
		}
		if(tag)
			for(ri i = 1;i <= n;i ++)
				ans[i] = q[i];
		return true;
	}
	for(ri i = head[u];i;i = edge[i].next){
		int v = edge[i].to;
		if(!vis[v]){
			last[v] = u;
			vis[v] = 1;
			int temp = q[top];
			q[top] = v;
			++ top;
			dfs(v);
			--top;
			q[top] = temp;
			vis[v] = 0;
		}
	}
	if(last[u] != u)
		if(dfs(last[u]))
			return true;
	return false;
}

bool check(){
	for(ri i = 1;i <= n;i ++)
		if(ans[i] == 0)
			return false;
	return true;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int a,b;
	for(ri i = 1;i <= m;i ++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(ri i = 1;i <= n;i ++)
		ans[i] = 999999;
	for(ri i = 1;i <= n;i ++){
		memset(vis,0,sizeof(vis));
		memset(last,0,sizeof(last));
		int temp = q[1];
		q[1] = i;
		top = 2;
		last[i] = i;
		vis[i] = 1;
		if(!dfs(i))
			q[1] = temp;
		if(check())
			break;
	}
	for(ri i = 1;i <= n;i ++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
