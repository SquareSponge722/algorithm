#include <iostream>
#include <stdio.h>
using namespace std;

int n=0;
int d[100001]={0};
int book[100001]={1};
int ans=999999999;

int min(int a,int b){
	if(a>b) return b;
	else return a;
}
int max(int a,int b){
	if(a<b) return b;
	else return a;
}
void dfs(int step){
	int sum=0;
	int marrrk=-1;
	int nz=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		sum=sum+d[i];
		marrrk=max(marrrk,d[i]);
	}
	if(sum==0){
		if(step<=ans){
			ans=step;
		}
		return;
	}
	if(step+marrrk>=ans) return;
	
	for(int l=1;l<=n;l++){
		if(l>=n-nz) nz=0;
		for(int r=l;r<=n-nz;r++){
			bool flag=true;
			int mark=10001;
			for(int i=l;i<=r;i++){
				if(d[i]==0) {
					flag=false;
					nz=n-i;
					break;
				}
				mark=min(mark,d[i]);
			}
			if(flag){
				for(int i=l;i<=r;i++){
					d[i]=d[i]-mark;
			    }
			    dfs(step+mark);
			    for(int i=l;i<=r;i++){
					d[i]=d[i]+mark;
			    }
			}
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
