#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
using namespace std;
const int N = 5010;
int m,n;
int edge[N],tot = 0,Next[N],head[N],ver[N],v[N];
void add(int x,int y){ 
	ver[++tot] = y;
	edge[tot] = 1;
	Next[tot] = head[x];
	head[x] = tot;
}
queue <int> q;
struct node{
	int num,val;
}d[N];
bool cmp(const node &a,const node &b) {
	return a.val < b.val;
}
int minn;
void spfa() {
	memset(v,0,sizeof(v));
	for(int i = 1;i <= n;i++) d[i].num = i,d[i].val = 0x3f;
	d[1].val = 0;
	v[1] = 1;
	q.push(1);
	while(q.size()) {
		int x = q.front();
		q.pop();
		for(int i = head[x];i;i = Next[i]) {
			int y = ver[i], z = edge[i];
			if(d[y].val > d[x].val + z) {
				d[y].val = d[x].val + z;
				if(!v[y]) {
					v[y] = 1;
					q.push(y);
				}
			}
		}
	}
}
int main() {
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	spfa();
	sort(d+1,d+n+1,cmp);
	for(int i = 1;i <= n;i++) 
		cout << d[i].num << " ";
	return 0;
}
