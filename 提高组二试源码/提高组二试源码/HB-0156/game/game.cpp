#include<bits/stdc++.h>
using namespace std;
const int k=1000000007;


int main(){
	ifstream cin("game.in");
	ofstream cout("game.out");
	long long ans;
	long long n,m;
	cin>>n>>m;
	n=n%k;
	m=m%k;
	cout<<6*m%k<<endl;
	return 0;
}
