#include<stream>
using namespace std;
int main(){
	int n,i,a[i],k,x,m,b[m],p,q,sum;
    cin>>n;
	int sum=0
	int q=0
	int m=0
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	do for(q=1;q<=n;q++){
		if(a[q]==0){
			q++;
		}
	
	for(i=1;i<=n;i++){
		if(a[i]>=1){
			k++;
		}
		else m++;b[m]=i;
	}
	if(k==n){
		for(i=1;i<=n;i++){
			a[i]=a[i]-1;
			sum++;
		}
	}
	else sum=sum+2;for(i=1;i<m;i++){
		for(p=b[i]+1;p<=b[i+1]-1;p++){
			a[p]=a[p]-1;
		}
		for(p=b[m]+1;p<=n;p++){
			a[p]=a[p]-1;
		}
		for(p=1;p<=b[1];p++){
			a[p]=a[p]-1;
		}
		sum++;
	}
    }while(q==n);
    cout<<sum<<endl;
return 0;
}
