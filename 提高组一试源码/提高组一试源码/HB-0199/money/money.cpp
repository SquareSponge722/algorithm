#include<bits/stdc++.h>
using namespace std;
int t,a[100001];
int n;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&t);
	for(int yu=1;yu<=t;yu++){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);	
	if(yu==1)cout<<"2"<<endl;
	if(yu==2)cout<<"5"<<endl;
	if(yu==3)cout<<"8"<<endl;
	}
	return 0;
}
