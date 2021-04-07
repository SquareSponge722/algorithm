#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	freopen("moeny.in","r",stdin);
	freopen("moeny.out","w",stdout);
	int T=0;
	int a[21][101]={0};
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=T;i++){
		cout<<a[i][0]<<endl;
	}
	return 0;
}
