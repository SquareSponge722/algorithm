#include <iostream>
#include <cstdio>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	preopen("money.in","r",stdin);
	preopen("money.out","w",stdout);
	int n,x;
    cin>>n;
    while(n--){
    int b,m;
    int g=0;
    int a[1000];
    int b[1000];
	cin>>m;
	int p=m;
	for(int i=1;i<=m;i++){
		cin>>b;
		a[i]=b;
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if (a[j]<a[j-1]){
			   x=a[j];
			   a[j]=a[j-1];
			   a[j-1]=x;	
			}
		}
	}
	for(int j=m;j>=1;j--){
	   for(int i=1;i<=j-1;i++){
		 if(a[i]%a[j]==0){
		 p--;
		 a[i]=0;
		
		 }
	   }	
	 }
	 for(int i=1;i<=m;i++){
	 	if(a[i])b[g++]=a[i];
	 }
	 m=p;
	 for(int i=1;i<=)
    }  
	return 0;
}
