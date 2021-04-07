#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 50001
#define maxai1 16
#define ll long long
using namespace std;
inline int read(){
	char ch=getchar();
	int ans=0,cf=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			cf=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*cf;
}
int n,m,cnt,head[maxn];

/************************************************************************************/

struct edge{
	int to,nxt,w;
}edges[maxn<<1];
void add(int u,int v,int w){
	cnt++;
	edges[cnt].to=v;
	edges[cnt].nxt=head[u];
	edges[cnt].w=w;
	head[u]=cnt;
}

/************************************************************************************/
bool vis1[maxn]={0};
int ans=0,marka=0;
void dfs1(int now,int sum){
	if(sum>ans){
		ans=sum;
		marka=now;
	}
	for(int i=head[now];i;i=edges[i].nxt){
		int v=edges[i].to;
		int w=edges[i].w;
		if(!vis1[v]){
			vis1[v]=1;
			dfs1(v,sum+w);
			vis1[v]=0;
		}
	}
}
void work1(){
	dfs1(1,0);
	ans=0;
	memset(vis1,0,sizeof(vis1));
	dfs1(marka,0);
	printf("%d\n",ans);
}

/************************************************************************************/
int b[maxn];
bool judge2(int myans){
	int sum=0,cntp=0;
	for(int i=1;i<=n;i++){
		if(sum+b[i]<myans){
			sum+=b[i];
		}
		else{
			sum=0;
			cntp++;
		}
	}
	if(cntp>=m){
		return true;
	}
	return false;
}
void work2(){
	for(int i=1;i<n;i++){
		b[i]=edges[head[i]].w;
	}
	ll l=0,r=100000000;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(judge2(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d\n",r);
}
/************************************************************************************/

void work3(){
	bool used[maxai1]={0};
	int max3=0,mark31=0,mark32=0;
	int sum[maxai1][maxai1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum[i][j]=edges[head[i]].w+edges[head[j]].w;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(used[i]){
					break;
				}
				if(used[j]){
					continue;
				}
				if(sum[i][j]>max3){
					max3=sum[i][j];
					mark31=i;
					mark32=j;
				}
			}
		}
		used[mark31]=1;
		used[mark32]=1;
	}
	printf("%d\n",max3);
}
//qwq
/************************************************************************************/

bool cmp(edge a,edge b){
	return a.w<b.w;
}

/************************************************************************************/
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();
	m=read();
	int cntuv1=0,cntai1=0;
	for(int i=1;i<n;i++){
		int u,v,w;
		u=read();
		v=read();
		w=read();
		if(u==v-1){
			cntuv1++;
		}
		if(u==1){
			cntai1++;
		}
		add(u,v,w);
		add(v,u,w);
	}
	if(m==1){
		work1();
	}
	else if(cntuv1==n-1){
		work2();
	}
	else if(cntai1==n-1 && n<=15){
		work3();
	}
	else{
		sort(edges+1,edges+1+cnt,cmp);
		printf("%d\n",edges[cnt-(m>>1)].w);
	}
	return 0;
}

