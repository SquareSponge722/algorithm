#include<bits/stdc++.h>
using namespace std;
int n,over,r=0;
unsigned long long day;
int d[100010],book[100010];
bool T;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	d[r]=10000000;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if(!d[i]){
			book[i]=1;
			over++;
		}
		if(d[i]<d[r]) r=i;
	}
	if(!d[r]){
		for(int i=1;i<=n;i++){
			if(d[i]>d[r]) d[i]-=d[r];
			else{
				d[i]=0;
				book[i]=1;
				over++;
			}
		}
	}
	while(over<n){
		for(int i=1;i<=n;i++){
			if(d[i]){
				d[i]--;
				T=1;
				if(!d[i]){
					book[i]=1;
					over++;
				}
			}
			else{
				if(!T){
					T=0;
					continue;
				}
				else{
					T=0;
					day=day+1;
					continue;
				}
			}
		}
		if(T) day++;
		T=0;
	}
	cout<<day;
	return 0;
}
