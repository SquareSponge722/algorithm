#include<iostream>
#include<cstdio>
using namespace std;
int a[5005],b[5005],q[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n,min1,min2;
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i];
	cout<<1<<" ";
	for(int j=1;j<n;j++){
	int k=1,d=1;
	q[1]=1000,q[2]=1000;
		for(int i=1;i<=m;i++){
			if(a[i]==d&&a[i]!=1000&&b[i]!=1000&&d!=1000)q[1]=b[i];
			if(b[i]==d&&a[i]!=1000&&b[i]!=1000&&d!=1000)q[2]=a[i];
		if(q[1]>q[2]){d=q[2];a[i]=1000;
		}
		else {d=q[1];b[i]=1000;
		}if(d==1000)return 0;
		cout<<d<<" ";
		q[1]=1000;
		q[2]=1000;}
	}
	
	return 0;
}
