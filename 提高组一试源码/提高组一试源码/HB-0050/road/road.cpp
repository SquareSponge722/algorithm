#include<bits/stdc++.h>
using namespace std;
int a[100005]={1};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	cin>>n;
	
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]++;
	}
		
	for (int j=1;j<=a[i];j++){
		if (a[i]<a[i-1]) a[j]=a[i-1];
		if (a[i]>a[i-1]) a[j]=a[i];
	}
	cout<<a[i]<<endl;
	return 0;
}
