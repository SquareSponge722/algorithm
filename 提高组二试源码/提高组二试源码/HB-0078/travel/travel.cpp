#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a[100];
	int b[100];
	int c;
	int d;
	int n;
	cin>>n;
	int i=0;
	while(i<=n){
		cin>>c>>d;
		a[i]=c;
	    b[i]=d;
	    i++;
	}
	return 0;
}
