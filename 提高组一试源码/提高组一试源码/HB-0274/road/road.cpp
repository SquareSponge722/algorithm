#include<bits/stdc++.h>
using namespace std;
int ans=0;
void key(int a[],int h){
	int z,y;
	for (int i=h;i>=1;i--){
		for (int j=h;j>=1;j--){
			if (a[i]>a[j])	break;
			if (a[i]<=a[j]){
				if (j=1) y=a[i];break;
			}
		}	 
	}
	ans+=y;
	z=y;
	for (int m=1;m<=h;m++){
		if (a[m]=0)
			a[m]=0;
		else a[m]=a[m]-z;
		}
}
void best(int c[],int high){
	for (int i=1;i<=high;i++){
		if (c[i]=0){
			if (i=1){
				for (int j=1;j<=high;j++){
					c[j]=c[j+1];
					high=high-1;
				}	
			}
			if (i!=1){
				return key(c,i);break;
			}
		}	
		if (i=high & c[high]!=0 & high!=1) 
		return key(c,high); 
		if (high=1){
		 ans+=c[high]; break;
		}
		i=1;
	}
}
int N=100005;
int M=10005;
int main(){
	freopen ("D.road.in","r",stdin);
	freopen ("D.road.out","w",stdout);
	int n;
	int b[N];
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>b[i];
	} 
   	best(b,n);
	cout<<ans<<endl;	
	return 0;
}
