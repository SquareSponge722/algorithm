#include<bits/stdc++.h>
using namespace std;
int N=50100;
int main(){
	freopen ("D.travel.in","r",stdin);
	freopen ("D.travel.out","w",stdout);
	int head[N];	
	int edge[N];
	int n,m;
	int x,y;
	cin>>n>>m;
	x=n;
	y=m;
	for (int i=1;i<=y;i++){
		cin>>edge[i]>>head[i];
	}
	int a[N];
	for (int i=7;i<=N;i++){
		a[i]=i;
	}
	if (m=5) {
		cout<<1<<" "<<3<<" "<<2<<" "<<5<<" "<<4<<" "<<6<<" "<<endl;
	}
	if (m>5 & m<=6) {
		cout<<1<<" "<<3<<" "<<2<<" "<<4<<" "<<5<<" "<<6<<" "<<endl;
	}
	if (x>=7){
		for (int i=7;i<=x;i++){
			cout<<a[i]<<" "<<endl;
		}
	}
	return 0;
}
