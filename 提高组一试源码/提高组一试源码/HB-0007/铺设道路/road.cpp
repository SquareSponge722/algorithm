#include<iostream>
#include<cstdio>
using namespace std;
int d[100005];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	int n,ans=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>d[i];
	d[n+1]=0;
	for(int i=1;i<=n;i++){
		if(d[i]!=0){for(int f=i+1;f<=n+1;f++){
			if(d[f]==0){s++;
			for(int k=i;k<f;k++)
			d[k]--;
			}ans+=s;s=0;
		}
		}
	
	}cout<<ans+n-1;
	return 0;

	}

