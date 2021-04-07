#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
	ifstream in;
	ofstream out;
	in.open("money.in");
	out.open("money.out");
	int T;
	in>>T;
	while(T>0){
	int n,a[100]={};
	in>>n;
	for(int i = 0;i<n;i++) in>>a[i];
	sort(a,a+n);
	int m = n;
	for(int i = n-1;i>0;i--){
		int w = a[i];
		for(int j = i-1;j>=0;j--){
			w = w%a[j];
			if(w==0){
			m--;
			break;	
			}
		}
	}
	out<<m<<endl;
	T--;
	}

	in.close();
	out.close();
}
