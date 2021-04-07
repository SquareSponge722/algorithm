#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
//int max(int a,int b){
//	if(a>b) return a;
//	else return b;
//}
//int min(int a,int b){
//	if(a<b) return a;
//	else return b;
//}
bool book[101];
bool shu(int a,int b,int c){
	if(a*b==c) return 1;
	if(a%c==b) return 1;
	else return 0;
}
bool zhi(int a,int b){
	int f=0; 
		if(max(a,b)%min(a,b)==0) {
			f=1;
			
		}
//		c=a,b=d;
	
//		if(a==0||b==0) {
//			f=3;
//			break;
//		}
		

	if(f==1)
	return 1;
	if(f==0)
	return 0;
//	if(f==3)
//	return c*d;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
int m;
int q;
cin>>m;
for(int i=1;i<=m;i++){
	q=0;
	int n,a[101];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	q=n;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			
			if(zhi(a[i],a[j])==1) q--;
			for(int k=1;k<=n;k++){
				if(shu(a[i],a[j],a[k])==1&&book[k]==0){
					q--;
					book[k]=1;
				}
			}
		}
	}
	printf("%d\n",q);
}
	return 0;
}
