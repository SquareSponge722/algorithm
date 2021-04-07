#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
const int N=5010;
int n,m;
bool map[N][N],vis[N];
int  ans[N],step[N];
queue <int> q,book[N];
int a[N];
void bfs(int qidian){
	int t=1;
	q.push(qidian);
	vis[qidian]=true;
	ans[t++]=qidian;
	step[qidian]++;
	int  head=1,tail=1;
	while(!q.empty()){
		bool flag=true;
		int cur=q.front();
		q.pop();
		int len=book[cur].size();
		for(int i=1;i<=len;i++){
			int nxt=book[cur].front();
			book[cur].pop();
			if(!vis[nxt]){
				vis[nxt]=true;
				q.push(nxt);
			}
		}
		int d=953944;
		for(int i=1;i<=n;i++){
			if(vis[i] && step[i]==0){
				d=min(d,i);
				ans[t]=d;
				step[d]++;
			}	
		}
		t++;
		for(int i=1;i<=n;i++)
			if(step[i]==0) flag=false;
		if(flag) break;
	}
	return;
}
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		map[x][y]=map[y][x]=true;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(map[i][j])	book[i].push(j);	
	bfs(1);
	for(int i=1;i<=n;i++)
	printf("%d ",ans[i]);
	return 0;
}
