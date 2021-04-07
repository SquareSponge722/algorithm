#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n,m;
bool f[5100];
vector<int> node[5010];
vector<int> node_topu[5010];
priority_queue <int,vector<int>,greater<int> > que;
int cando[5010];
int step[5010];
int p;
int pd[5010];
int vis[5010];
int out[5010];
////void topu();
void add(int,int);
void bfs(int,int);
void bfs1();
//void add_topu();

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		//add_topu(u,v);
	}
	if(m==n){
		bfs1();
		for(int i=0;i<n;i++){
			cout<<step[i]<<' ';
		}
		return 0;
	}
	
	bfs(1,0);
	for(int i=0;i<n;i++){
		cout<<step[i]<<' ';
	}
	return 0;
}
/*
void topu(){
	for(int i=1;i<=n;i++){
		out[i]+=node_topu.size()+1;
		for(int j=0;i<node_topu[i].size();j++){
			vis[node[i][j]]++;
		}
	}
	queue<int> pp;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			pp.push(i);
		}
	}
	while(!pp.empty()){
		int now=pp.front();
		for(int i=0;i<node_topu[now].size();i++){
			vis[node_topu[now][i]]--;
			if(vis[node_topu[now][i]]==0){
				pp.push(node_topu[now][i]);
			}
		}
		pp.pop();
	}
}
*//*
void add_topu(int x,int y){
	node_topu[x].push_back(y);
*/
void bfs(int now,int last){
	priority_queue<int,vector<int>,greater<int> >que;
	step[p++]=now;
	for(int i=0;i<node[now].size();i++){
		if(node[now][i]!=last){
			que.push(node[now][i]);
		}
	}
	for(;!que.empty();){
		int nxt=que.top();
		que.pop();
		if(pd[nxt]==1){
			continue;
		}
		pd[nxt]=1;
		bfs(nxt,now);
	}
}

void bfs1(){
	que.push(1);
	f[1]=true;
	while(!que.empty()){
		int now=que.top();
		que.pop();
		vis[now]--;
		step[p++]=now;
		pd[now]=true;
		for(int i=0;i<node[now].size();i++){
			if(f[node[now][i]]==0){
				que.push(node[now][i]);
				f[node[now][i]]=1;
			}
		}
	}
}
void add(int u,int v){
	node[u].push_back(v);
	node[v].push_back(u);
}
