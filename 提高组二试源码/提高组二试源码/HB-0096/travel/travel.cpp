#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

void reads(int &x){
	int fx=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fx=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	x=x*fx; //正负号 
}

//int find_fa(int x){ return (fa[x]==x)?x:find_fa(fa[x]); }

const int N=5019; int only_[N],xx[N],y[N],leftt[N],rightt[N]; 

int n,m,okk=0; priority_queue<int> v[5019],onl; //从大到小 

int minn,tt,vis[N];

int mins(int &a,int b){
	if(a>-v[b].top()) a=-v[b].top(),tt=b;
}

void did(int kk){
	if(leftt[kk]>-v[kk].top()&&rightt[kk]>-v[kk].top()) return;
	minn=-v[kk].top(),tt=kk;
	if(leftt[kk]>rightt[kk]){
		vis[rightt[kk]]=1; cout<<" "<<rightt[kk]; 
		int now=rightt[rightt[kk]];
		if(!vis[-v[rightt[kk]].top()]) minn=mins(minn,rightt[kk]);
		while(leftt[kk]>now){ if(now>minn) return;
			vis[now]=1,cout<<" "<<now; now=rightt[now]; 
			if(!vis[-v[now].top()]) minn=mins(minn,now);
		} if(leftt[kk]>minn) return; 
		if(!vis[-v[leftt[kk]].top()]) minn=mins(minn,leftt[kk]);
		vis[leftt[kk]]=1,cout<<" "<<leftt[kk]; int now2=leftt[leftt[kk]];
		while(now2!=now){ if(now2>minn) return;
			if(!vis[-v[now2].top()]) minn=mins(minn,now2);
			cout<<" "<<now2; now2=leftt[now2]; }
	} else{
		cout<<" "<<leftt[kk]; int now=leftt[leftt[kk]];
		while(rightt[kk]>now){ cout<<" "<<now; now=leftt[now]; }
		cout<<" "<<rightt[kk]; int now2=rightt[rightt[kk]];
		while(now2!=now){ cout<<" "<<now2; now2=rightt[now2]; }
	}	
}

void dfs(int u,int fa_){
	while(!v[u].empty()){
		int x=-v[u].top(); v[u].pop(); //最小的 
		if(x==fa_) continue;
		if(only_[x]&&okk==0&&!vis[x]){ vis[x]=1,printf(" %d",x),did(x); dfs(tt,u); okk=1; } 
		else if(!vis[x]) vis[x]=1,printf(" %d",x); dfs(x,u);
	}
}

//树+一条边 ---> 缩点（只会有一个强联通）

int dfn_=0,dfn[N],low[N],stack_[N],ink[N],top=0;

void tarjan(int u,int fa_){
	dfn[u]=low[u]=++dfn_; ink[u]=1,stack_[++top]=u;
	while(!v[u].empty()){
		int x=-v[u].top(); v[u].pop(); //最小的 
		if(x==fa_) continue;
		if(!dfn[x]) tarjan(x,u),low[u]=min(low[u],low[x]);
		else if(ink[x]) low[u]=min(low[u],dfn[x]);
	} if(low[u]==dfn[u]){ //找到唯一的缩点
		//col[u]=1; 
		if(stack_[top]==u){ ink[u]=0; top--; }
		else{ only_[u]=1; int lastt=u; 
		  while(stack_[top]!=u){
			only_[stack_[top]]=1; rightt[lastt]=stack_[top],
			leftt[stack_[top]]=lastt,lastt=stack_[top]; 
			//cout<<stack_[top]<<" *** "<<leftt[stack_[top]]<<endl;
			ink[stack_[top]]=0,onl.push(-stack_[top]),top--;
		  } leftt[u]=lastt,top--;
		}
	}	
} 

void re_add(){
	for(int i=1;i<=m;i++)
		v[xx[i]].push(-y[i]),v[y[i]].push(-xx[i]);
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	reads(n),reads(m);
	for(int i=1;i<=m;i++) reads(xx[i]),reads(y[i]),
		v[xx[i]].push(-y[i]),v[y[i]].push(-xx[i]);
	if(m==n) tarjan(1,0),re_add(); 
	//for(int i=1;i<=n;i++) cout<<i<<" *** "<<only_[i]<<endl;
	printf("1"),dfs(1,0);
}
