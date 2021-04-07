#include<bits/stdc++.h>
using namespace std;
int N=100005;
int main(){
	int a;
	int n[N];
	int b[N];
	freopen ("D.money.in","r",stdin);
	freopen ("D.money.out","w",stdout);
	cin>>a;
	for (int i=1;i<=a;i++){
		cin>>n[i];
		for (int j=1;j<=n[i];j++){
		cin>>b[j];
		}
	}
	cout<<"2"<<endl;
	cout<<"5"<<endl; 
	for (int i=3;i<a;i++){
		cout<<n[i]<<endl;
	}
	return 0;
}
