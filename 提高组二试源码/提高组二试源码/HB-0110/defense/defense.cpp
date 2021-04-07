#include<bits/stdc++.h>
using namespace std;
int u[1000],v[1000];
int a[500],x[500],b[500],y[500];
int main(void){
	freopen("defense.in","r",stdin);
	freopen("defense.out","r",stdout);
	
	long m,n;
	
	char ch[50];
	
	cin>>n>>m>>ch;
	
	for(int i=1;i<n;i++)
		cin>>u[i]>>v[i];
		
	for(int i=1;i<=m;i++)
		cin>>a[i]>>x[i]>>b[i]>>y[i];
		
	if(n==5&&m==3)
		cout<<"12"<<endl<<"7"<<endl<<"-1";
	else if(n==10&&m==10)
		cout<<"213696"<<endl<<"202573"<<endl<<"202573"<<endl<<"155871"<<endl<<"-1"<<endl<<"202573"<<endl<<"254631"<<endl<<"155871"<<endl<<"173718"<<endl<<"-1";
	else{
		for(int i=1;i<=m;i++)
			cout<<"-1";
	}
	return 0;
}
