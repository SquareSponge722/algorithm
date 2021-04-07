#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;


int n,m,sum;
string A;
int a,x,b,y;
int pzh[7777777],f[7777][7777],to[7777][7777],k[777777],flag[777777],num[777777];
struct node{
	int p;
	int z;
}t[777777];
void fa(int x){
	for(register int i=1;i<=k[x];i++){
		int e=to[x][i];
		flag[e]=1;
	}
}
void work(){
	for(register int i=1;i<=n;i++){
		if(flag[t[i].z]==0){
			sum+=t[i].p;
			flag[i]=1;
			fa(t[i].z);
		}
	}
}
bool cmp(node a,node b){
	return a.p<b.p;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>A;
	for(register int i=1;i<=n;i++){
		scanf("%d",&pzh[i]);
		t[i].p=pzh[i];
		t[i].z=i;
	}
	sort(t+1,t+1+n,cmp);
	for(register int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		to[u][++k[u]]=v;
		to[v][++k[v]]=u;
		f[u][v]=1;
		f[v][u]=1;
	}
	for(register int i=1;i<=m;i++){
		sum=0;
		int lp=0,lq=0;
		memset(flag,0,sizeof(flag));
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(x==0&&y==0&&f[a][b]==1){
			printf("-1\n");
			continue;
		}
		if(x==1){
			sum+=pzh[a];
			flag[a]=1;
			fa(a);
		}
		if(x==0){
			int kk=77777777,kkk=0;
			for(register int i=1;i<=k[a];i++){
				int e=to[a][i];
				if(kk>pzh[e]){
					kk=pzh[e];
					kkk=e;
				}
			}
			sum+=kk;
			flag[kkk]=1;fa(kkk);
		}
		if(y==1){
			sum+=pzh[b];
			flag[b]=1;
			fa(b);
		}
		if(y==0&&flag[b]==0){
			int kk=0,kkk=0;
			for(register int i=1;i<=k[b];i++){
				int e=to[b][i];
				if(kk<=pzh[e]){
					kk=pzh[e];
					kkk=e;
				}
			}
			sum+=kk;
			flag[kkk]=1;fa(kkk);
		}
		work();
		printf("%d\n",sum);
	}
	return 0;
}
