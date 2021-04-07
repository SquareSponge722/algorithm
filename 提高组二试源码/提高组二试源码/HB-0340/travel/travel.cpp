#include <iostream>
#include <cstdio>
#include <cmath>
#include <list>
#include <cstring>

using namespace std;

//struct edge{
//	int to;
//	int next_edge;
//};
bool dfs(int n);
bool greater_than(list<int>* a,list<int>* b);

//edge edges[10005];
//int head[5000];
int n,m,u,v,p;
bool xcbook[5000];
//list<int> xcqueue;
list<int> xcseq;
list<int> xcmap[5000];
bool flag;
int xcfrom[5000];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		xcmap[u-1].push_back(v);
		xcmap[v-1].push_back(u);
		//edge[i*2+1].next_edge=head[u-1];
		//edge[i*2+1].to=v;
		//head[u-1]=i*2+1;
		//edge[i*2+2].next_edge=head[v-1];
		//edge[i*2+2].to=u;
		//head[v-1]=i*2+2;
	}
	for (int i=0;i<n;i++){
		xcmap[i].sort();
	}
	p=0;
	xcbook[0]=true;
	xcseq.push_back(1);
	dfs(1);
	while (0!=xcseq.size()){
		printf("%d ",xcseq.front());
		xcseq.pop_front();
	}
	return 0;
}


bool dfs(int kl){
	bool suc=false;
	p++;
	if (p==n){
		return true;
	}
	//int next_edge=head[n-1];
	//int min_l=5500
	for (int i=0;i<xcmap[kl-1].size();i++){
		int uyy=xcmap[kl-1].front();
		xcmap[kl-1].pop_front();
		if (not xcbook[uyy-1]){
			xcfrom[uyy-1]=kl;
			xcbook[uyy-1]=true;
			xcseq.push_back(uyy);
			suc=dfs(uyy);
			if (suc){
				return true;
			}
		}
		xcmap[kl-1].push_back(uyy);
	}
	return false;
}

bool greater_than(list<int>* a,list<int>* b){
	bool agb=false;
	bool jgd=false;
	for (int i=0;i<(*a).size();i++){
		if (jgd){
			int af=(*a).front();
			(*a).pop_front();
			int bf=(*b).front();
			(*b).pop_front();
			(*a).push_back(af);
			(*b).push_back(bf);
		}else{
			int af=(*a).front();
			(*a).pop_front();
			int bf=(*b).front();
			(*b).pop_front();
			if (af>bf){
				jgd=true;
				agb=true;
			}else if (af<bf){
				jgd=true;
				agb=false;
			}
			(*a).push_back(af);
			(*b).push_back(bf);
		}
	}
	return agb;
}
