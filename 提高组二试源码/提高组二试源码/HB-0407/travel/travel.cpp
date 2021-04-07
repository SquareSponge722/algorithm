#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define qDebug(i) if(debug)printf("%s",i);
using namespace std;
struct _graph{
	vector<int> edges[5006];
	int n,m;
	int root;
	int level[5011];
	_graph operator =(_graph t){
		n=t.n;m=t.m;
		root=t.root;
		rep(i,1,n){
			rep(j,0,t.edges[i].size()-1){
				edges[i][j]=t.edges[i][j];
			}
		}
	}
} graph;
vector<int> ans;
struct stk{
	int ser[5011];
	int cnt;
	void push(int x){
		cnt++;
		ser[cnt]=x;
	}
	void pop(){
		if(!empty()){
			cnt--;
		}
	}
	bool empty(){
		if(cnt==-1)return true;
		else return false;
	}
	int size(){
		return cnt+1;
	}
};
bool vis[5011];
int read(){
	char ch=getchar();int f=1,x=0;
	while(ch<'0' || ch>'9'){ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
void dfs(int cu,int last,_graph &g,bool directOutput=true,vector<int> &target=ans){
	//printf("[DFS]current:%d <- %d\n",cu,last);
	rep(i,0,g.edges[cu].size()-1){
	//	printf("[DFS]try GET %d->%d\n",cu,g.edges[cu][i]);
		if(vis[g.edges[cu][i]])continue;
		if(g.edges[cu][i]==0)continue;
		vis[g.edges[cu][i]]=true;
		if(directOutput)printf("%d ",g.edges[cu][i]);
		else target.push_back(g.edges[cu][i]);
		//printf("PUSHED %d\n",g.edges[cu][i]);
		dfs(g.edges[cu][i],cu,g,directOutput,target);
		vis[g.edges[cu][i]]=false;
	}
}
int bfs(_graph &g){
	queue<pair<int,int> >q;
	pair<int,int> t;
	rep(i,1,g.n)g.level[i]=-1;
	g.level[1]=1;
	int keyPoint;
	q.push(pair<int,int>(1,1));
	while(!q.empty()){
		t=q.front();
		q.pop();
		rep(i,0,g.edges[t.first].size()-1){
			if(g.level[g.edges[t.first][i]]==-1){
			//	printf("[BFS]pushed %d,%d from %d,%d\n",g.edges[t.first][i],t.second+1,t.first,t.second);
			//	printf("%d -> %d\n",t.first,g.edges[t.first][i]);
				q.push(pair<int,int>(g.edges[t.first][i],t.second+1));
				g.level[g.edges[t.first][i]]=t.second+1;
			}
			else if(g.level[g.edges[t.first][i]]<t.second)continue;
			else{
				keyPoint=g.edges[t.first][i];
			}
		}
	}
	return keyPoint;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	graph.n=read(),graph.m=read();
	int method=2;int a,b;
	if(graph.m==graph.n-1){
		//Tree
		graph.root=1;
		method=1;
	}
	rep(i,1,graph.m){
		a=read();b=read();
		graph.edges[a].push_back(b);
		graph.edges[b].push_back(a);
	}
	if(method==1){
		rep(i,1,graph.n){
			sort(graph.edges[i].begin(),graph.edges[i].end());
		}
		printf("1 ");
		vis[graph.root]=true;
		dfs(1,0,graph,true);
	}
	else{
		int target=bfs(graph);
		//rep(i,1,graph.n)printf("lev[%d]=%d ",i,graph.level[i]);
		//printf("\ntarget:%d",target);
		vector<int> parents;
		rep(i,0,graph.edges[target].size()-1){
			if(graph.level[graph.edges[target][i]]<graph.level[target])parents.push_back(graph.edges[target][i]);	
		}
		_graph graphb=graph;
		rep(i,0,graph.edges[target].size()-1){
			if(graph.edges[target][i]==parents[0])graph.edges[target][i]=0;	
		}
		rep(i,0,graph.edges[parents[1]].size()-1){
			if(graph.edges[parents[1]][i]==target)graph.edges[parents[1]][i]=0;	
		}
		rep(i,0,graphb.edges[parents[0]].size()-1){
			if(graphb.edges[parents[0]][i]==target)graphb.edges[parents[0]][i]=0;
		}
		rep(i,0,graph.edges[target].size()-1){
			if(graphb.edges[target][i]==parents[1])graphb.edges[target][i]=0;	
		}
		rep(i,1,graph.n){
			sort(graph.edges[i].begin(),graph.edges[i].end());
		}
		rep(i,1,graphb.n){
			sort(graphb.edges[i].begin(),graphb.edges[i].end());
		}
		/*printf("\ngot parents from target %d:",target);
		for(int i=0;i<parents.size();i++)printf("%d ",parents[i]);
		printf("\n");*/
		vector<int> ans2;
		vis[1]=true;
		dfs(1,0,graph,false,ans);
	/*	printf("search of graph 1 finished\n");
		printf("series:");
		for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);*/
		memset(vis,0,sizeof(vis));
		vis[1]=true;
		ans2.clear();
		dfs(1,0,graphb,false,ans2);
	/*	printf("\nsearch of graph 2 finished\n");
		printf("series:");
		for(int i=0;i<ans2.size();i++)printf("%d ",ans2[i]);*/
		int chosen=0;
		for(int i=0;i<graph.n;i++){
			if(ans[i]==ans2[i])continue;
			else if(ans[i]<ans2[i]){
				chosen=1;
				break;
			}
			else{
				chosen=2;
				break;
			}
		}
		//printf("\nchosen:%d\n",chosen);
		printf("1 ");
		if(chosen==1){
			for(int i=0;i<ans.size();i++){
				printf("%d ",ans[i]);
			}
		}
		if(chosen==2){
			for(int i=0;i<ans2.size();i++){
				printf("%d ",ans2[i]);
			}
		}
	}
	return 0;
}
