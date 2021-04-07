#include<bits/stdc++.h>
using namespace std;
int d[200000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	int n,ans,i,count=0,zong=0,t;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>d[i];
		zong+=d[i];
	}
		
	
	for(ans=1;count<zong;ans++){
	int temp0=0,temp1=0;
		for(i=1;i<=n;i++){
		if(d[i]){			
			temp1++;
			d[i]-=1;
			count++;
									
		}	
		else{
			temp0++;
			i=temp0;
			if(temp1&&temp0)
			break;
		}
	}
}
	cout<<ans-1;
} 
