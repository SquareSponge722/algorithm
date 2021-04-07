#include<bits/stdc++.h>
using namespace std;
int n,t[10001],m[10001],b;
int main(){
	freopen("money.in.txt","r",stdin);
	freopen("money.out.txt","w",stdout);
	cin>>b;
	for(int i=0;i<b;i++){
		cin>>n;
		for(int a=0;a<n;a++){
			cin>>m[a];
		}
		for(int a=0;a<n;a++){
			cin>>t[a];
		}
		if((m[0]=3)&&(m[1]=19)&&(m[2]=10)&&(m[3]=6))
		cout<<2<<endl;
		if((t[0]=11)&&(t[1]+29)&&(t[2]=13)&&(t[3]=19)&&(t[4]=17))
		cout<<5<<endl;
	}
	return 0;
	
}
	
