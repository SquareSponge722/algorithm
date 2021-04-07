#include<stream>
using namespace std
int main(){
	int n,i,a[n],m,q;
	cin>>n
	for(i=1;i<=n;i++){
		cin>>a[i]
	}
	do{
		int q=1
		for(i=1;i<=n;i++){
			if(a[i]<a[i+1]){
				m=a[i]
				a[i]=a[i+1]
				a[i+1]=m
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]<a[i+1]){
				q++
			}
		}
	}while(q==n)
	
}
