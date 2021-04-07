#include<iostream>
#include<cstring>
#include<cstdio>
int N[1000000];
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a; int count=1;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>N[i];
	}
	for(int d=1;d<=a;d++){
		if(N[d]!=0){
			for(int e=1;e<=d;e++){
				N[e]-=2;
			}
			count++;
		}
		else{
			for(int q=1;q<=d-1;q++){
				N[q]-=1;
			}
			count++;
		}
//		count++;
	}
	printf("%d",count+2);	
	return 0;
}
