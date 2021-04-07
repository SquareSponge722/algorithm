#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,m;
struct trees
{
	int father;
	int son[5];
}tree[5050];
int pan[5010][5010];
void build_tree(int root)
{
		for(int j=1;j<=n;j++){
			if((pan[root][j]==1)&&(tree[j].father==0)){
				tree[j].father=root;
				tree[root].son[0]++;
				tree[root].son[tree[root].son[0]]=j;
				pan[j][root]=0;
			}
		}	
		for(int j=1;j<=tree[root].son[0];++j){
			build_tree(tree[root].son[j]);
		}	
	return;
}
void dfs(int c)
{
	printf("%d ",c);
	for(int i=1;i<=tree[c].son[0];i++){
		dfs(tree[c].son[i]);
	}
	return;
}
void bfs()
{
	int leftn=0,rightn=1;
	int line[5010]={1};
	bool yes[5010]={true,true};
	for(int i=1;i<=5010;++i){
		line[i]=0;
	}
	for(int i=2;i<=n;i++){
		yes[i]=false;
	}
	while(leftn!=rightn){
		for(int i=1;i<=n;i++){
			if((pan[line[leftn]][i]==1)&&(!yes[i])){
				line[rightn]=i;
				yes[i]=true;
				rightn++;
			}
		}
		printf("%d ",line[leftn]);
		leftn++;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(m==n-1){
		int a,b;
		for(int i=1;i<=m;++i){
			scanf("%d %d",&a,&b);
			pan[a][b]=1;
			pan[b][a]=1;
		}
		build_tree(1);
		dfs(1);
	}
	else{
		int a,b;
		for(int i=1;i<=m;++i){
			scanf("%d %d",&a,&b);
			pan[a][b]=1;
			pan[b][a]=1;
		}
		bfs();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
