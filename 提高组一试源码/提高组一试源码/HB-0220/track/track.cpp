#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500005;
int a[N],b[N],l[N],e[N];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,min=10000000,max=0;
	cin>>n>>m;
	for (int i=1;i<=n-1;i++){
		cin>>a[i]>>b[i]>>l[i];
		
		if (l[i]<min) min=l[i]; 
	} 
	if (min>max) max = min;
	cout<<max<<endl;
	return 0;
}
