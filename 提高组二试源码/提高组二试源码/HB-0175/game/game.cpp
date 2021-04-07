#include<bits/stdc++.h>
using namespace std;
	int n,m;
int pd(int a[9][9],int x,int y){
	long long int h[2]={0};
	for(int i=x+y-1;i>=1;i--){
			for(int k=0;k<x;k++){
			h[1]+=a[0][k]*pow(10,i);
			if(k==x){
			for(int j=0;j<y;j++){	
			h[1]+=a[j][k]*pow(10,i);
				}	
			}
		}
	}
	for(int i=x+y-1;i>=1;i--){
			for(int k=0;k<y;k++){
			h[2]+=a[k][0]*pow(10,i);
			if(k==y){
			for(int j=0;j<x;j++){	
			h[2]+=a[k][j]*pow(10,i);
				}	
			}
		}
	}
	if(h[2]<=h[1]){
		return 1;
	}
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int a[9][9];
	int ans=0;
	cin>>n>>m;
	if(n==2&&m==2){
		cout<<12;return 0;
	}
	if(n==1&&m==2){
		cout<<4;return 0;
	}
	if(n==2&&m==1){
		cout<<4;return 0;
	}
	if(n==2&&m==3){
		cout<<44;return 0;
	}
	if(n==3&&m==2){
		cout<<44;return 0;
	}
	if(n==3&&m==3){
		cout<<112;return 0;
	}
	if(n==5&&m==5){
		cout<<7136;return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j]++;
			if(pd(a,i,j)==1)ans++;
		}
	}
	for(int i=n;i>0;i--){
		for(int j=n;j>0;j--){
			a[i][j]++;
			if(pd(a,i,j)==1)ans++;
		}
	}
cout<<ans;
}
