#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int a[N]={0};
int n,t(0);
bool pp=false;
bool yep(){
	for (int i=1;i<=n;i++)
		if (a[i]!=0) return true;
		return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	while (yep()){
		for (int i=0;i<=n;i++){
		if (a[i]!=0)
		{
		a[i]--;
		pp=false;
		}
		else{
		    if(!pp) t++;
		    pp=true;
		}
		}
	}
	cout<<t<<endl;
	return 0;
}
