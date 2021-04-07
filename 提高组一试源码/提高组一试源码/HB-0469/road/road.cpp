#include<bits/stdc++.h>
using namespace std;
int n,d[10001],o,p,t=0;
int main(){
//	freopen("road.in.txt","r",stdin);
//	freopen("road.out.txt","w",stdout);
	cin>>n;
	int min;
	for(int i=0;i<n;i++){
	cin>>d[i];
	min=d[0];
	}
		for(int a=0;a<n;a++){
			
		if(min>d[a]) min=d[a];
	}for(int i=0;i<n;i++){
		for(int a=1;a<n;a++){
			if((d[i]>d[i+a])&&(d[i]>d[i-a])){
				//p=i+a;
				if(d[i+a]<d[i-a]){	
			o=d[i]-d[i+a];
				}
				else{
				o=d[i]-d[i-a];		
				} 
			}
			else break;
		}//if(p<=n)i=p+1;
		t+=o;	
		}
		t+=min;
		cout<<t<<endl;
	return 0;	
}
