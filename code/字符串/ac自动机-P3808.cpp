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

const int N = 1e6  + 10;

int n;
char str[N];

int tot;
int tr[N][26];
int e[N],fail[N];

void insert();
void build();
int query();

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%s",str);
		insert();
	}
	build();
	scanf("%s",str);
	printf("%d\n",query());
	return 0;
}

void insert(){ //建trie树
	int u = 0;
	for(int i = 0;str[i];i++){
		if(tr[u][str[i] - 'a'] == 0) tr[u][str[i] - 'a'] = ++tot;
		u = tr[u][str[i] - 'a'];
	}
	e[u]++;
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
int query(){
	int res = 0,u = 0;
	for(int i = 0;str[i];i++){
		u = tr[u][str[i] - 'a'];
		for(int j = u;j && e[j] != -1;j = fail[j]){
			res += e[j];
			e[j] = -1;
		}
	}
	return res;
}

//ac自动机 洛谷 P3808
//2021-6-4