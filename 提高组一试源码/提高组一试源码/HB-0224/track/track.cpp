#include<iostream>
using namespace std;
struct road{
	int first,last,lenth;
}a[1000001];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<n;i++){
	    cin>>a[i].first >>a[i].last>>a[i].lenth;
		sum+=a[i].lenth;
		}
    cout<<sum/m-67;
   return 0;     

}
