#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch;
	int f=1;
	int num=0;
	ch=getchar();
	if(ch=='-'){
		f=-1;
		ch='0';
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}
int n,m;
bool visit[5001];
int finish=1;
int now=1;
int edge[5001][2];
bool cg[5001];
int last[5001];
void setcg(){
	for(int i=0;i<=n;i++){
		cg[i]=0;
	}
}
deque<int>q;
int cango(int x,int y){
	setcg();
	deque<int>qq;
	qq.push_back(x);
	while(!qq.empty()){
		int p=qq.front();
		for(int i=0;i<n;i++){
			if(edge[i][0]==p){
				if(visit[edge[i][1]]==1&&cg[edge[i][1]]==0){
					qq.push_back(edge[i][1]);
					cg[edge[i][1]]=1;	
				}
				if(edge[i][1]==y){
					return edge[i][0];
				}
			}
			else if(edge[i][1]==p){
				if(visit[edge[i][0]]==1&&cg[edge[i][0]]==0){
					qq.push_back(edge[i][0]);
					cg[edge[i][1]]=1;
				}
				if(edge[i][0]==y){
					return edge[i][1];
				}
			}
		}
		qq.pop_front();
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	visit[1]=1;
	q.push_back(1);
	n=read();
	m=read();
	int u,v;
	for(int i=0;i<n;i++){
		u=read();
		v=read();
		edge[i][0]=min(u,v);
		edge[i][1]=max(u,v);
	}
	while(finish!=n){
		int mi=99999;
		int guo;
		for(int i=1;i<=n;i++){
			int cgg=cango(now,i);
			if(cgg&&visit[i]==0){
				mi=min(mi,i);
				guo=cgg;
			}
		}
		visit[mi]=1;
		q.push_back(mi);
		finish++;
		last[mi]=guo;
		for(int i=0;i<n;i++){
			if((edge[i][0]==guo&&edge[i][1]!=mi&&edge[i][1]!=last[guo]&&edge[i][1]!=last[mi]&&visit[edge[i][1]]==1)||(edge[i][1]==guo&&edge[i][0]!=mi&&edge[i][0]!=last[guo]&&edge[i][1]!=last[mi]&&visit[edge[i][0]]==1)){
				edge[i][0]=0;
				edge[i][1]=0;
			}
		}
		now=mi;
	}
	while(!q.empty()){
		cout<<q.front()<<' ';
		q.pop_front();
	}
	return 0;
}
