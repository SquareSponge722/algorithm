#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int head[50005],next[100005],ver[100005],value[100005];
int n,m,total,dis[50005];
queue<int> q;
inline void add(int f,int t,int v){
	ver[++total]=t;
	value[total]=v;
	next[total]=head[f];
	head[f]=total;
}
int spfa(int root){
	q.push(root);
	memset(dis,0,sizeof(dis));
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=head[now];i;i=next[i]){
			int t=ver[i],v=-value[i];
			if(dis[t]==0&&dis[t]>dis[now]+v){
				dis[t]=dis[now]+v;
				q.push(t);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=min(ans,dis[i]);
	return -ans;
}
bool cmp(int i,int j){return i>j;}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	int f,t,v;
	bool k1=true,k2=true;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&f,&t,&v);
		add(f,t,v);add(t,f,v);
		if(f!=1)k1=false;
		if(t!=f+1)k2=false;
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,spfa(i));
		printf("%d",ans);
	}
	else if(k1){
		sort(value+1,value+2*n-1,cmp);
		printf("%d",value[m*2]);
	}
	else printf("100");
	fclose(stdin);
	fclose(stdout);
	return 0;
}