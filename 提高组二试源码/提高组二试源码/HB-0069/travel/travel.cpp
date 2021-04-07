#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<vector>
#include<string>
using namespace std;

inline int read(){
	
	int x=0,y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
	
}

const int N=5005;
int n,m,ans[N],cnt;
bool vis[N];
vector<int> v[N];

inline void dfs(int pos){
	
	cnt++;
	ans[cnt]=pos;
	if(cnt==n) return;
	vis[pos]=1;
	int l=v[pos].size() ;
	int go[N];
	for(int i=0;i<l;i++)
		go[i]=v[pos][i];
	sort(go,go+l);
	for(int i=0;i<l;i++)
		if(!vis[go[i]])
			dfs(go[i]);
	
}

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int a,b;
		a=read(),b=read();
		v[a].push_back(b);
		v[b].push_back(a);  
	}
	
	dfs(1);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
	
}
