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

const int N = 512;
const int M = 1024;

int n,ans;
char str[M];

int tot;
int nxt[M][5];
bool isLoop[M];

struct state{
	int pos,id;
	state(int pos,int id) : pos(pos),id(id) {}
};
bool vis[M][N];

char dna[5] = {'A','T','C','G'};
inline int getId(char ch){
	for(int i = 0;i < 4;i++)
		if(dna[i] == ch) return i;
	return -1;
}

bool bfs();

int main(){
	memset(nxt,-1,sizeof(nxt));
	scanf("%s",str);
	for(int i = 0;str[i];i++){
		if(str[i] == '?'){
			++tot;
			for(int i = 0;i < 4;i++)
				nxt[tot][i] = tot + 1;
		}else if(str[i] == '*'){
			isLoop[tot + 1] = true;
		}else{
			++tot;
			nxt[tot][getId(str[i])] = tot + 1;
		}
	}
	
	scanf("%d",&n);
	ans = n;
	while(n--){
		scanf("%s",str);
		ans -= bfs();
	}
	printf("%d\n",ans);
	return 0;
}

bool bfs(){
	int len = strlen(str);

	memset(vis,0,sizeof(vis));
	queue <state> q;
	q.push(state(0,1));
	vis[0][1] = true;
	while(!q.empty()){
		state cur = q.front();
		q.pop();

		int tmp = getId(str[cur.pos]);
		int to = nxt[cur.id][tmp];
		if(to != -1){
			if(cur.pos == len - 1 && to == tot + 1) return true;
			if(cur.pos < len - 1){
				if(!vis[cur.pos + 1][to]) q.push(state(cur.pos + 1,to));
				vis[cur.pos + 1][to] = true;
			}
		}
		if(isLoop[cur.id]){
			if(cur.pos == len - 1 && cur.id == tot + 1) return true;
			if(cur.pos < len - 1){
				if(!vis[cur.pos + 1][cur.id]) q.push(state(cur.pos + 1,cur.id));
				vis[cur.pos + 1][cur.id] = true;
			}
		}
	}
	return false;
}

//字符串上的bfs
//虽然我看着又像trie又像ac自动机
//但我是bfs哒，草
//2021-6-10