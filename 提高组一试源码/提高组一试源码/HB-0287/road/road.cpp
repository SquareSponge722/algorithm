#include<bits/stdc++.h>
using namespace std;
int a[100011];
int n,b[100011];
int ans,pd1,qd,zd,minn,u=1;
bool ok;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	while(1) {
		pd1=0;
		minn=21474836;
		for(int i=1;i<=n;i++){
			if(a[i]==0)pd1++;
		}
		if(pd1==n) break;
		for(int t=1;t<=n;t++){
			if(a[t]>0){
				qd=t,zd=t+1;
				break;
			} 
			
		}
		while(a[zd]>0) {
			zd++;
		}
		zd--;
		//cout<<"qd="<<qd<<" "<<"zd="<<zd<<endl;
		for(int j=qd; j<=zd; j++) {
			if(a[j]<minn) minn=a[j];
		}
		for(int j=qd; j<=zd; j++) {
			a[j]-=minn;
		}
		ans+=minn;
		//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	}
	cout<<ans;
	return 0;
}
