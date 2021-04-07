#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
queue <int> q[N];
int sta[N],end[N];
const  int N=50000; 
int n,m;
struct INF{
	int a,b,l;
};
struct INF inf[N]; 
bool vis[N][N];
int  cnt[N];
int step[N][N];
void bfs(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int kaishi=sta[i];
			int jieshu=end[j];
			if(kaishi==jieshu)	continue;	
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(vis[i][j])	q[i].push(j);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=q[i].size();j++){
			int cur=
		}
}
int main (){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++){
		int a,b,l;
		scanf("%d %d %d",&a,&b,&l);
		inf[i].a=a,inf[i].b=b,inf[i].l=l;
		vis[a][b]=vis[b][a]=true;	
		cnt[a]++,cnt[b]++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==1)
			sta[i]=i,end[i]=i;
	for(int i=1;i<=m;i++){
		
	}
	return 0;
}
