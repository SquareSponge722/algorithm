#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

const int N = 2e6  + 10;

int n;
char str[N];

int tot;
int tr[N][26];
int fail[N];

int indx;
int idx[N],cnt[N];

int all;
int to[N],nxt[N],head[N];

void insert();
void build();
void query();
void dfs(int);

inline void addEdge(int u,int v){
	to[++all] = v;
	nxt[all] = head[u];
	head[u] = all;
}

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%s",str);
		insert();
	}
	build();
	scanf("%s",str);
	query();

	for(int i = 1;i <= tot;i++)
		addEdge(fail[i],i);
	dfs(0);

	for(int i = 1;i <= n;i++)
		printf("%d\n",cnt[idx[i]]);
	return 0;
}

void insert(){ //建trie树
	int u = 0;
	for(int i = 0;str[i];i++){
		if(tr[u][str[i] - 'a'] == 0) tr[u][str[i] - 'a'] = ++tot;
		u = tr[u][str[i] - 'a'];
	}
	idx[++indx] = u;
}
void build(){ //处理fail指针
	queue <int> q;
	for(int i = 0;i < 26;i++)
		if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0;i < 26;i++){
			if(tr[u][i]){
				fail[tr[u][i]] = tr[fail[u]][i];
				q.push(tr[u][i]);
			}else{
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
}
void query(){
	int u = 0;
	for(int i = 0;str[i];i++){
		u = tr[u][str[i] - 'a'];
		cnt[u]++;
	}
}
void dfs(int id){ //对fail树处理求和
	for(int cur = head[id];cur;cur = nxt[cur]){
		dfs(to[cur]);
		cnt[id] += cnt[to[cur]];
	}
}

//ac自动机 洛谷 P5357
//2021-6-9