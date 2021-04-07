#include<bits/stdc++.h>
using namespace std;
long long a[50005][50005]={0},l[50005][50005];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,x,y,z,ans=0;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
		
		}
	}
		
		for(int i=1;i<n;i++)
		if(a[x][i]!=0){
			if(a[i][y]!=0) {ans+=a[x][i]+a[i][y];
			cout<<ans;
			return 0;
			}
			for(int k=1;k<n;k++)
			if(a[i][k]!=0&&a[k][y]!=0){
				ans+=a[i][k]+a[k][y]+a[x][i];
				cout<<ans;
				return 0;
			}
		}
	
		 
	}
	return 0;
}
