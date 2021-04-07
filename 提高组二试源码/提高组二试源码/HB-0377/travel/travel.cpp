#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
struct edge{
	int from,to;
	bool ban;
	bool used;
	
	int ano(int p){
		if(p==this->from)
			return this->to;
		return this->from;
	}
	
}e[5100];
vector<int> node[5100];
int cur[5100];
int curr;
bool color[5100];
vector<int> circle;
int n,m;
int ans[5100];
int ans_cnt=1;
bool flag=false;

void initt(){
	for(int i=1;i<=5050;i++)
		ans[i]=99999;
	return ;
}
void init_e(){
	for(int i=1;i<=m;i++)
		e[i].used=false;
	return ;
}

bool cmp(const int x,const int y){
	return e[x].ano(curr)<e[y].ano(curr);
}

bool dfs(int x,int y){
	if(color[x]){
		circle.push_back(y);
		return true;
	}
	color[x]=true;
	
	for(unsigned int i=0;i<node[x].size();i++){
		if(!e[ node[x][(int)i] ].used){
			e[ node[x][(int)i] ].used=true;
			if(dfs( e[ node[x][(int)i] ].ano(x) , node[x][(int)i]) ){
				if(x!=1)
					circle.push_back(y);
				return true;
			}
			e[ node[x][(int)i] ].used=false;
		}
	}
	return false;
}

void work(int x){
	if(x>ans[ans_cnt] && !flag)
		return ;
	else if(x<ans[ans_cnt]){
		ans[ans_cnt]=x;
		flag=true;
	}
	else if(flag)
		ans[ans_cnt]=x;
	
	int cnt=0;
	for(unsigned int i=0;i<node[x].size();i++)
		if(!e[ node[x][(int)i] ].ban && !e[ node[x][(int)i] ].used){
			cur[++cnt]=node[x][(int)i];
			e[ node[x][(int)i] ].used=true;
		}
	
	curr=x;
	sort(cur+1,cur+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		ans_cnt++;
		work(e[cur[i]].ano(x));
	}
		
	return ;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	initt();
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e[i].from,&e[i].to);
		e[i].ban=false;
		e[i].used=false;
		node[e[i].from].push_back(i);
		node[e[i].to].push_back(i);
	}
	
	if(dfs(1,0))//have circle
		for(unsigned int i=0;i<circle.size();i++){
			e[circle[(int)i]].ban=true;
			init_e();
			ans_cnt=1;
			flag=false;
			work(1);
			e[circle[(int)i]].ban=false;
		}
	else{
		init_e();
		work(1);
	}
	
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
