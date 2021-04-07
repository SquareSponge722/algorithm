#include<bits/stdc++.h>
#include<queue>
#define N  50005
using namespace std;
queue<int> q;
int n,m,max[N],ans,head[N],cnt,inq[N];
struct Edge{
	int nex,to,w;
}edge[N];
void read(int &x){
	int t = 1;x=0;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch == '-') t = -1;ch = getchar();}
	while(ch>='0'&&ch<='9'){x = (x<<3)+(x<<1)+ch^48;ch = getchar();}
	x*=t;
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	read(n);read(m);
	for(int i=1,u,v,w;i<=m;i++){
		read(u);read(v);read(w);
		ans += w;
	}
	printf("%d\n",ans);
	return 0;
}
