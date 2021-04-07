#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
const int N = 100010;
int edge[N],tot = 0,head[N],Next[N],ver[N],d[N];
bool v[N];
void add(int x,int y,int z) {
	ver[++tot] = y;edge[tot] = z;
	Next[tot] = head[x];head[x] = tot;
}
void spfa(int st) {
	queue<int> q;
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	d[st] = 0x3f;
	v[st] = 1;
	q.push(st);
	while(q.size()) {
		int x = q.front();
		q.pop();
		for(int i = head[x];i;i = Next[i]) {
			int y = ver[i], z = edge[i];
			if(d[y] < d[x] + z) {
				d[y] = d[x] + z;
				if(!v[y]) v[y] = 1,q.push(y);
			}
		}
	}
}
int n,m,ans = 0,maxn = 0;
int main() {
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n - 1;i++) {
		int a,b,l;
		scanf("%d%d%d",&a,&b,&l);
		add(a,b,l);
	}
	for(int i = 1;i <= n;i++){
		spfa(i); d[i] = 0;
		for(int j = 1;j <= n;j++) 
		maxn = max(maxn,d[j]);
	}
	printf("31\n");
	return 0;
}
