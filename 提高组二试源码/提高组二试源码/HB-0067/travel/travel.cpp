# include <cstdio>
# include <iostream>
# include <cstring>
# include <queue>
# define N 15000
using namespace std;
int n,m,cnt;
struct edge{
	int v,next;
}e[N]; int head[N];
int vis[N],book[N],ru[N];
void add(int u,int v){
	e[++cnt].v =v ;
	e[cnt].next =head[u];
	head[u]=cnt;
}
inline int read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int res=ch-48;
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-48;
	return res;
}
struct vd{
	int to;
	bool operator<(const vd &a)const{
		return to>a.to;
	}
};
void dfs(int s){
	priority_queue<vd>q;
	printf("%d ",s);
	vd temp;
	int to;
	for(int i=head[s];i;i=e[i].next ){
		int to=e[i].v ;
		if(!vis[to]){
			vis[to]=1;
			temp.to =to;
			q.push(temp);
		}
	}
	while(!q.empty()){
		temp=q.top(),q.pop();
		to=temp.to ;
		dfs(to);
	}
}
struct node{
	priority_queue<vd>q;
}t[N];
void dfs1(int s,int fa){
	printf("%d ",s);
	vd temp;
	int to;
	for(int i=head[s];i;i=e[i].next ){
		int to=e[i].v ;
		if(!vis[to]){
			vis[to]=1;
			temp.to =to;
			t[s].q.push(temp); 
		}
	}
	if(!book[fa]&&!t[s].q.empty() && !t[fa].q.empty()){
		vd temp1,temp2;
		int to1,to2;
		while( !t[s].q.empty() && !t[fa].q.empty()){
			temp1=t[s].q.top() ;
			temp2=t[fa].q.top() ;
			to1=temp1.to ;
			to2=temp2.to ;
			if(to1<=to2){
				t[s].q.pop();
				dfs1(to1,s);
			}
			else {
				t[fa].q.pop();
				dfs1(to2,s);
			}
		}
	}
	while(!t[s].q.empty()){
			temp=t[s].q.top() ;
			t[s].q.pop();
			to=temp.to ;
			dfs1(to,s);	
	}
}
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),m=read();
	int u,v;
	for(int i=1;i<=m;++i){
		u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	vis[1]=1;
	if(m==n-1) dfs(1);
	else if(m==n){
		queue<int>q;
		for(int i=1;i<=2*cnt;++i){
			ru[e[i].v ]++;
		}
		for(int i=1;i<=n;++i){
			if(ru[i]==1){
				q.push(i); 
			}
		}
		int temp;
		while(!q.empty()){
			temp=q.front() ;
			q.pop();
			book[temp]=1;
			for(int i=head[temp];i;i=e[i].next ){
				int to=e[i].v ;
				ru[to]--;
				if(ru[to]==1&&!book[to]){
					q.push(to); 
				}
			}
		}
		dfs1(1,0);
	}//อุฦห 
	return 0;
}
