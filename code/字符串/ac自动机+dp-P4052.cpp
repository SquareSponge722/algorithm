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

const int N = 1e4;
const int MOD = 10007;

int n,m;
char str[N];

int tot;
int tr[N][26];
int fail[N];

bool ile[N];
int dp[110][N];

void insert();
void build();

inline int qpow(int num,int bit){
	int ans = 1;
	while(bit){
		if(bit & 1) ans = ans * num % MOD;
		num = num * num % MOD;
		bit >>= 1;
	}
	return ans;
}

int main(){
	scanf("%d %d",&n,&m);
	while(n--){
		scanf("%s",str);
		insert();
	}
	build();

	int u = 0;
	dp[0][0] = 1;
	for(int i = 0;i <= m;i++)
		for(int j = 0;j <= tot;j++)
			for(int k = 0;k < 26;k++){
				if(!ile[tr[j][k]])
					dp[i + 1][tr[j][k]] = (dp[i + 1][tr[j][k]] + dp[i][j]) % MOD;
			}
	
	int ans = qpow(26,m);
	for(int i = 0;i <= tot;i++){
		ans = (ans - dp[m][i] + MOD) % MOD;
	}

	printf("%d\n",ans);
	return 0;
}

void insert(){ //建trie树
	int u = 0;
	for(int i = 0;str[i];i++){
		if(tr[u][str[i] - 'A'] == 0) tr[u][str[i] - 'A'] = ++tot;
		u = tr[u][str[i] - 'A'];
	}
	ile[u] = true;
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
				ile[tr[u][i]] |= ile[tr[fail[u]][i]];
				q.push(tr[u][i]);
			}else{
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
}

//ac自动机上 dp[i][j] 一般为
//在匹配串 i 位置  ac自动机 j 位置 状态
//视情况可以再加一维状态

//洛谷 ac自动机dp P4052
//2021-6-9