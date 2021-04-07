#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<vector>
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

const int N=50005;
int ans,n,m,go[N];
bool flag1,flag2,vis[N];
struct node{
	int from,to,wei;
}r[N*2];
vector<int> v[N];

int dis[N];
inline int dfs(int pos,int now){
	
	vis[pos]=1;
	int maxx=0;
	if(dis[N]) return dis[N];
	if(go[pos]==1&&now) return now;
	for(int i=0;i<v[pos].size() ;i++){
		int a=v[pos][i],b=r[a].to ,c=r[a].wei ;
		if(!vis[b]) maxx=max(maxx,dfs(b,now+c));
	}
	dis[pos]=maxx;
	return maxx;
	
}

inline int solve(){
	
	for(int i=1;i<=n;i++)
		if(go[i]==1){
			fill(dis,dis+n+1,0);
			fill(vis,vis+n,0);
			ans=max(ans,dfs(i,0));
		}
			
	return ans;
	
}

inline bool judge(int x){
	
	int cnt=0,now=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<v[i].size()  ;j++){
			int a=v[i][j],b=r[a].to ,c=r[a].wei ;
			if(b==(i+1)){
				now+=c;
				if(now>=x){
					cnt++;
					now=0;
				}
				break;
			}
		}
			
	}
	
	if(cnt>=m) return true;
	else return false;
}

inline int solve2(){
	
	int low=0,high=1e5,mid;
	while(low<high-1){
		mid=(low+high)>>1;
		if(judge(mid)) low=mid;
		else high=mid;
	}
	if(judge(high)) return high;
	else return low;
	
}

int main(){
	
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=(n-1)*2;i+=2){
		int a=read(),b=read(),c=read();
		go[a]++,go[b]++;
		if(b!=(a+1)) flag2=1;
		r[i].from =r[i+1].to =a;
		r[i].to =r[i+1].from =b;
		r[i].wei =r[i+1].wei =c;
		v[a].push_back(i);
		v[b].push_back(i+1);  
	}
	
	if(m==1){
		cout<<solve()<<endl;
		return 0;
	}
	else if(!flag2){//只有一条路 
		cout<<solve2()<<endl;
		return 0;
	}
	
}
