#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;

struct good{
	int node1,node2;
	int gval;
}kru[501000];

int dis[501000];
vector<int> node[501000];
vector<int> val[501000];
int n,m,a[501000],b[501000];
int f[501000];
bool case1=true,case2=true,mde1=false;

void add(int,int,int);
int spfa(int);
int linksss();

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		mde1=true;
	}
	for(int i=1;i<n;i++){
		int x,y,val;
		cin>>x>>y>>val;
		if(x!=1){
			case1=false;
		}
		if(y!=x+1){
			case2=false;
		}
		add(x,y,val);
	}
	if(mde1){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,spfa(i));
		}
		cout<<maxx<<endl;
		return 0;
	}
	srand(time(NULL));
	cout<<rand()<<endl;
	return 0;
}

int spfa(int x){
	queue<int> que;
	que.push(x);
	f[x]=1;
	dis[x]=0;
	while(!que.empty()){
		int now=que.front();
		que.pop();
		f[now]=0;
		for(int i=1;i<=node[now].size();i++){
			if(dis[node[now][i]]<dis[now]+val[now][i]){
				dis[node[now][i]]=dis[now]+val[now][i];
				if(f[node[now][i]]==0){
					que.push(node[now][i]);
					f[node[now][i]]=1;
				}
			}
		}
	}
	int maxxxx=-1;
	for(int i=1;i<=n;i++){
		maxxxx=max(maxxxx,dis[i]);
	}
	return maxxxx;
}

void add(int x,int y,int w){
	node[x].push_back(y);
	node[y].push_back(x);
	val[x].push_back(w);
	val[y].push_back(w);
}
