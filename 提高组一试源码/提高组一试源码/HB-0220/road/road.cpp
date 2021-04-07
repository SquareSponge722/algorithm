#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int d[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,day=0,sum1=0,sum2=0,min=100000,l,r;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>d[i];
		sum2+=d[i];
	}
	for (int r=n,l=1;l<=r;r--,l++)
		for (int j;j>=l && j<=r;j++){
			if (d[j]>0){
				if (sum2==0) break;
				sum2-=r-l;
    	        day++;
			}
			else return false;
			sum1+=day;
		}
	if (sum1<min) min=sum1;
    cout<<min<<endl;
    return 0; 
}
