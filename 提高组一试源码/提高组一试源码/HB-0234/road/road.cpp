//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;
const int inf=100101;
long long n,a[inf];
bool flag[inf];
long long ans;
bool f=1;
long long z,y;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++) {
scanf("%d ",&a[i]);
if(a[i]) flag[i]=1;
//cout<<flag[i]<<endl;
}
	z=1;
	y=z+1;
while(f!=0){
	z=1;
	y=z+1;
//	cout<<f<<" ";
	while(flag[z]==0){
		z++;
		if(z==n+1) {
		f=0;
		break;
		}
	}
	if(f==0) break;
	y=z+1;
	while(flag[y]==1){
		y++;
		//cout<<y;
		//if(y==n) break;
	}
	y--;
	for(long long i=z;i<=y;i++){
		--a[i];
		if(a[i]==0) flag[i]=0;
	//	cout<<flag[i]<<endl;
		//cout<<a[i]<<endl;
	}
	ans++;
//	cout<<y<<endl;
//	cout<<z<<endl;
}
printf("%lld",ans);
	return 0;
}
