#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 100001;
int n,m,en(0),p[N],head[N],fa[N];
string s;
struct Edge{
	int u,v;
}edge[N];

int find(int x){
	if(x==fa[x]) return fa[x];
	else  return fa[x]=find(fa[x]);
}

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	fill(head,head+N,-1);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		edge[i].u= u;
		edge[i].v= v;
	}
	for(int i=1,a,x,b,y;i<=m;i++){
		int k1=find(edge[i].u),k2=find(edge[i].v);
		if(s[0]=='A'&&s[1]=='2'){  // neighbour 
			if(k1==k2) {
				if(x==0&&y==0) puts("-1");
			}
//			else {
//				
//			}
		}
		
	}
	return 0;
}
