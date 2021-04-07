#include <cstdio>
#include <cstring>
using namespace std;

int road[100005];
int n;
int ans=0;
int ssstart;
int eeend;
int zeronum=0;

void dfs(int left,int right,int deep){
	if(left==right){
		ans=ans+road[left];
		road[left]=0;
		zeronum++;
		return;
	}
	if(road[left]==0){
		dfs(left+1,right,deep);
		return;
	}
	if(road[right]==0){
		dfs(left,right-1,deep);
		return;
	}
	bool b=false;
	for(int i=left;i<=right;i++){
		if (road[i]==0){
			zeronum++;
			eeend=i-1;
			ssstart=i+1;
			b=true;
			break;
		}
		if (deep>road[i]){
			deep=road[i];
		}
	}
	
	if(b==false) {
		for (int i=left;i<=right;i++){
		road[i]=road[i]-deep;
	}
	ans=ans+deep;
	}	
	if (b==true){
	dfs(left,eeend,10001);
	dfs(ssstart,right,10001);	
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
	scanf("%d",&road[i]);
	}
	while(zeronum!=n){
		dfs(1,n,10001);	
	}
	printf("%d",ans);
	return 0;
}


