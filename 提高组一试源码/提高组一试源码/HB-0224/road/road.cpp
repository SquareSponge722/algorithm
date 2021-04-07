#include<iostream>
using namespace std;
long long a[100001], ans;
long long  min(long long a,long long b){
	  return a>b?b:a;
}
void add(int low,int high){
	 if(low==high) {
	 ans+=a[low];a[low]=0;return;}
	 int minn=10001; 
	 for(int i=low;i<=high;i++){
	     if(!a[i]&&minn==10001) {
		 low++;continue; } 
	     if(!a[i]) {
	     	ans+=minn;
	     	for(int j=low;j<i;j++) a[j]-=minn;
	     	add(low,i-1);
	     	add(i+1,high);
	     	break;
		 }
		 else if(i==high) {
		       minn=min(minn,a[i]);ans+=minn;
		       for(int j=low;j<=i;j++) a[j]-=minn;
		       add(low,high);
			   }
			  else minn=min(minn,a[i]);}
		      
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,minn=10001;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
		minn=min(minn,a[i]);
		}
    ans=minn;
	for(int i=1;i<=n;i++)
	   a[i]-=ans;
	add(1,n);
	cout<<ans;
	return 0;
}
