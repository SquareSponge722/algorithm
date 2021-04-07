#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<vector>
#include<string>
#include<queue>
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

const int N=100005;
int n,m,p[N],amy[N];
string s;
bool vis[N],inq[N];

vector<int> v[N];

long long bfs(int a,int x,int b,int y){
	
	queue<int> q;
	q.push(a);
	q.push(b);
	amy[a]=x;
	amy[b]=y;
	vis[a]=1;
	vis[b]=1;
	inq[a]=1;
	inq[b]=1;
	long long ans=0;
	while(!q.empty() ){
		int pos=q.front() ;
		q.pop() ;
		inq[pos]=0;
		vis[pos]=1;
		if(amy[pos]) ans+=p[pos];
		for(int i=0;i<v[pos].size() ;i++){
			int c=v[pos][i];
			if(!vis[c]){
				if(!inq[c]) {
					q.push(c);
				inq[c]=1;
				}
				if(amy[pos]) amy[c]=0;
				else amy[c]=1; 
			}
		}
	}
	return ans;
}

int main(){
	
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<n;i++){
		int a,b;
		a=read(),b=read();
		v[a].push_back(b);
		v[b].push_back(a);  
	}
	while(m--){
		
		int a,x,b,y;
		a=read(),x=read(),b=read(),y=read();
		int flag=0;
		for(int i=0;i<v[a].size() ;i++) if(v[a][i]==b) flag=1;
		if(flag&&!x&&!y){
			cout<<-1<<endl;
			break;
		}
		fill(amy,amy+N+1,2);
		fill(vis,vis+N+1,0);
		cout<<bfs(a,x,b,y)<<endl;
		
	}
	
}
