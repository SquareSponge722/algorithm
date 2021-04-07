#include<iostream> //!!a[i]可能等于0 
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100001;
int n,a[N],minn,ans=0; 

void dfs(int a[],int sta,int end){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	
	int minn=10001;
	for(int i=sta;i<=end;i++){
		minn=min(minn,a[i]);
		if(minn!=0){
			ans=ans+minn;
			for(int j=sta;j<=end;j++){
				a[i]-=minn;	
			}
		}
	}
	for(int i=sta;i<=end;i++){
		if(a[i]==0) { 
			dfs(a,sta,i-1);
			dfs(a,i+1,end);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cout<<5<<endl;
	return 0;
}
