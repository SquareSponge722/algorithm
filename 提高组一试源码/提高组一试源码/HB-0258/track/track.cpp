#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int n,m,en=0;
struct Edge{
	int to,w,next;
}edge[N];
int ans=0;
int head[N];

void add(int a,int b,int c){
	edge[en].to=b;
	edge[en].w=c;
	edge[en].next=head[a];
	head[a]=en++;
	
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int a,b,l;
		add(a,b,l);
	}
	cout<<ans<<endl;
	return 0;
}

