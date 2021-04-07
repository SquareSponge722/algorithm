#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <ctime>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int n,m;
struct edge{
	int from,to,w,next;
	edge(int a=0,int b=0,int c=0,int d=0){
		from=a,to=b,w=c,next=d;
	}
};
edge edges[100021];int cnt=-1;
bool taken[100021];
int headers[50021];
int dis[50021];
vector<int> result;
vector<int> result2;
void init(){
	rep(i,1,n)headers[i]=-1;
}
int addEdge(int a,int b,int c){
	cnt++;
	edges[cnt]=edge(a,b,c,headers[a]);
	headers[a]=cnt;
	cnt++;
	edges[cnt]=edge(b,a,c,headers[b]);
	headers[b]=cnt;
}
int read(){
	char ch=getchar();int f=1,x=0;
	while(ch<'0' || ch>'9'){ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
void SPFA(int start){
	int t;
	queue<int> q;
	bool inQueue[50021];
	memset(inQueue,0,sizeof(inQueue));
	q.push(start);
	while(!q.empty()){
		t=q.front();
		q.pop();
	//	printf("[SPFA]current:%d\n",t);
		inQueue[t]=false;
		for(int i=headers[t];i!=-1;i=edges[i].next){
			if(dis[edges[i].to]>dis[edges[i].from]+edges[i].w){
				dis[edges[i].to]=dis[edges[i].from]+edges[i].w;
				if(!inQueue[edges[i].to]){
					q.push(edges[i].to);
					inQueue[edges[i].to]=true;
				}
			}
		}
	}
	//for(int i=1;i<=n;i++)printf("dis[%d]=%d  ",i,dis[i]);
	//printf("\n");
}
int getTreeDialema(){
	srand((unsigned)time(NULL));
	int start=rand()%n+1;
	rep(i,1,n)dis[i]=0x3f3f3f3f;
	dis[start]=0;
	SPFA(start);
	int logDisMax=0,logDisTar=0;
	rep(i,1,n){
		if(logDisMax<dis[i]){
			logDisMax=dis[i];
			logDisTar=i;
		}
	}
	start=logDisTar;
	rep(i,1,n)dis[i]=0x3f3f3f3f;
	dis[start]=0;
	SPFA(start);
	logDisMax=0;
	rep(i,1,n){
		if(dis[i]==0x3f3f3f3f)continue;
		logDisMax=max(logDisMax,dis[i]);
	}
	return logDisMax;
}
int binaryVerification(int target){
	//printf("Verifying %d\n",target);
	vector<int> segments;
	int cur=0,seg=1;
	for(int i=1;i<=n;i++){
		for(int j=headers[i];j!=-1;j=edges[j].next){
			if(edges[j].to==i+1){
				if(cur+edges[j].w>target){
					seg++;
					segments.push_back(cur);
					cur=0;
				}
				cur+=edges[j].w;
				if(seg>m)return -1;
			}
		}
	}
	if(cur!=0){
		segments.push_back(cur);
		seg++;
		cur=0;
	}
	if(segments.size()<m)return -2;
	else {
		int minn=0x3f3f3f3f;
		for(int i=0;i<segments.size();i++){
			minn=min(minn,segments[i]);
		}
	//	printf("[ver]target->%d get:%d\n",target,minn);
		result2.push_back(minn);
		return minn;
	}
}
/*
int binaryVerification2(int target,int cu,int cuLength,int cuTrack){
	for(int i=headers[cu];i!=-1;i=edges[i].next){
		if(!taken[i]){
			taken[i]=true;
			taken[i|1]=true;
			if(cuLength+edges[i].w<target)binaryVerification2(target,edges[i].to,cuLength+edges[i].w,cuTrack);
			else binaryVerification2(target,edges[i].to,cuLength+edges[i].w,cuTrack);
		}
	}
}
void binaryCheck2(int l,int r){
	int mid=(l+r)>>1;int res;
	while(l<=r){
		mid=(l+r)>>1;
	//	printf("check [%d %d]\n",l,r);
		res=binaryVerification(mid);
	//	printf("check response %d\n",res);
		if(res==-1)l=mid+1;
		else if(res==-2)r=mid-1;
		else{
			result.push_back(mid);
			binaryCheck(l,mid-1);
			binaryCheck(mid+1,r);
			return;
		}
	}
	result.push_back(mid);
}*/
void binaryCheck(int l,int r){
	int mid=(l+r)>>1;int res;
	while(l<=r){
		mid=(l+r)>>1;
	//	printf("check [%d %d]\n",l,r);
		res=binaryVerification(mid);
	//	printf("check response %d\n",res);
		if(res==-1)l=mid+1;
		else if(res==-2)r=mid-1;
		else{
			result.push_back(mid);
			binaryCheck(l,mid-1);
			binaryCheck(mid+1,r);
			return;
		}
	}
	result.push_back(mid);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	bool methodFlag2=true;
	int total=0;int minEdge=0x3f3f3f3f;
	n=read(),m=read();
	init();
	int a,b,c;
	rep(i,2,n){
		a=read(),b=read(),c=read();
		addEdge(a,b,c);
		total+=c;
		minEdge=min(minEdge,c);
		if(b!=a+1)methodFlag2=false;
	}
	if(m==1){
		printf("%d",getTreeDialema());
		return 0;
	}
	else if(m==n-1){
		printf("%d",c);
		return 0;
	}
	else if(methodFlag2){
		binaryCheck(1,total);
		int g=0;
		for(int i=0;i<result2.size();i++){
			g=max(g,result2[i]);
		}
		printf("%d",g);
		return 0;
	}
	else printf("%d",total/m);
	return 0;
}
