#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int m,n;
int u[10000],v[10000];
int num;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
	scanf("%d%d",&u[i],&v[i]);
	num=i;
	}

	if(num&2!=0,num%2==0){

		if(n!=m){
			if(u[num-(n-2)*(num/num)]!=u[2],v[num-(n-2)*(num/num)]==v[2]){
			cout<<u[num-(n-2)*(num/num)]<<" "<<v[num-(n-2)*(num/num)]<<" ";
		}
			if(u[num-(n-3)*(num/num)]==u[3],v[2]!=v[3]){
			cout<<u[3]<<" "<<v[3]<<" ";
			}
				if(u[4]!=u[5],v[4]!=v[5]){
				cout<<u[5]<<" "<<v[5];
				}
				
			if(u[6]!=u[7],v[6]==v[7]){
			cout<<u[6]<<" "<<v[6]<<" ";
		}
			if(u[7]==u[8],v[7]!=v[8]){
			cout<<u[8]<<" "<<v[8]<<" ";
			}
				if(u[9]!=u[10],v[9]!=v[10]){
				cout<<u[10]<<" "<<v[10];
			}
	else if(n==m){
			if(u[1]!=u[2],v[1]==v[2]){
			cout<<u[1]<<" "<<v[1]<<" ";
		}
			if(u[3]!=u[4],v[3]!=v[4]){
			cout<<u[3]<<" "<<v[4]<<" ";
			}
				if(u[5]==u[6],v[5]!=v[6]){
				cout<<v[5]<<" "<<v[6];
				}
				
			if(u[6]!=u[7],v[6]==v[7]){
			cout<<u[6]<<" "<<v[6]<<" ";
		}
			if(u[8]==u[9],v[8]!=v[9]){
			cout<<u[8]<<" "<<v[8]<<" ";
			}
				if(u[10]==u[11],v[10]!=v[11]){
				cout<<v[10]<<" "<<v[11];
			}
		}
	}

	
		
	}
}
	

