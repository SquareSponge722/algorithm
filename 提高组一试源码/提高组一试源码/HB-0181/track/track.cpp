#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,sum=0,mi=0;
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		sum+=w;
		mi=max(mi,w);
	}
	if(m==1){
		printf("%d\n",sum);
		return 0;
	}
	else if(m==n-1){
		printf("%d\n",mi);
		return 0;
	}
	else{
		printf("%d\n",sum/m+1);
		return 0;
	}
}
