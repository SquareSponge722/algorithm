#include <bits/stdc++.h>
using namespace std;
vector <int> graph[100005];
int point_val[100005];
string s;
int m,n;
inline void add(int from,int to) {
	if(from>to)
		swap(from,to);
	graph[from].push_back(to);
//	graph[to].push_back(from);
}
long long f[100005];
long long g[100005];
bool ifuse[100005];
int canuse[100005];
inline void dfs(int fa) {
	bool ok=1;
	ifuse[fa]=1;
	for(int i=0; i<graph[fa].size(); i++) {
		//	ifuse[i]=1;
		if(!ifuse[graph[fa][i]]&&graph[fa][i]!=fa) {
			dfs(graph[fa][i]);
			ifuse[graph[fa][i]]=1;
			ok=0;
		}
		//	cout<<fa<<' '<<graph[fa][i]<<endl;
		if(canuse[graph[fa][i]]==0) {
			f[fa]+=min(f[graph[fa][i]],g[graph[fa][i]]);
			g[fa]+=f[graph[fa][i]];
		}
		if(canuse[graph[fa][i]]==1) {
			f[fa]+=f[graph[fa][i]];
			g[fa]+=f[graph[fa][i]];
			//		cout<<"baka"<<' ';
			//g[fa]=0;
		}
		if(canuse[graph[fa][i]]==-1) {
			f[fa]+=g[graph[fa][i]];
			//		cout<<"baka"<<' ';
			//f[fa]=g[fa];
			//f[fa]=point_val[fa];
		}
//		for(int i=1; i<=n; i++)
//			cout<<f[i]<<' '<<g[i]<<' '<<i<<endl;
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++) {
		scanf("%d",&point_val[i]);
		f[i]=point_val[i];
	}
//	Cout<<point_val[2];
	for(int i=1; i<=n-1; i++) {
		int from,to;
		scanf("%d%d",&from,&to);
		add(from,to);
	}
	for(int i=1; i<=m; i++) {
		int a,b,x,y;
		for(int j=1; j<=n; j++)
			f[j]=point_val[j];
		memset(g,0,sizeof(g));
		memset(canuse,0,sizeof(canuse));
		memset(ifuse,0,sizeof(ifuse));
		cin>>a>>x>>b>>y;
		if(x==0)
			canuse[a]=-1;
		else
			canuse[a]=1;
		if(y==0)
			canuse[b]=-1;
		else
			canuse[b]=1;
		bool ok=1;
		for(int i=0; i<graph[min(a,b)].size(); i++) {
			if(y==0&&x==0&&graph[min(a,b)][i]==max(a,b)) {
				ok=0;
				break;
			}
		}
		if(!ok) {
			cout<<-1<<endl;
			continue;
		}
			dfs(1);
//		for(int i=1; i<=n; i++)
//			cout<<f[i]<<' '<<g[i]<<' '<<endl;
		//cout<<canuse[5];
//cout<<graph[5][0]<<canuse[2];
		if(canuse[1]==0) {
			if(f[1]!=0||g[1]!=0) {
				cout<<min(f[1],g[1])<<endl;
				continue;
			} else {
				cout<<-1<<endl;
				continue;
			}
		}
		if(canuse[1]==1) {
			if(f[1]!=0) {
				cout<<f[1]<<endl;
				continue;
			} else {
				cout<<-1<<endl;
				continue;
			}
		}
		if(canuse[1]==-1) {
			if(g[1]!=0) {
				cout<<g[1]<<endl;
				continue;
			} else {
				cout<<-1<<endl;
				continue;
			}
		}
	}
//	dfs(1);
//	cout<<graph[2][0];
//	for(int i=1; i<=n; i++)
//		cout<<f[i]<<' '<<g[i]<<' '<<endl;
	return 0;
}
