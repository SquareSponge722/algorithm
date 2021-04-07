#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int route1[14]; //0-D 1-R
int countd1[14];
int countr1[14];
int same=0;
int diff=0;
int countd2[14];
int countr2[14];
unsigned long long ans;
int main(){
	cin>>n>>m;
	
}

void dfs1(int stage){
	if (stage==2*n-3){
		if (countd>countr){
			route1[stage]=1;
		}else{
			route1[stage]=0;
		}
		dfs2(0);
		
	}
}

void dfs2(int stage){
	if (stage==2*n-3){
		unsigned long long ct=1;
		for (int i=1;i<=diff*2;i++){
			ct*=2;
			ct%=1000000007;
		}
		ans=ct;
		ct=1;
		for (int i=1;i<=diff;i++){
			ct*=2;
			ct%=1000000007;
		}
		ans+=1000000007;
		ans-=ct;
		ans%=1000000007;
		ans/=2;
		ct=1;
		for (int i=1;i<=same;i++){
			ct*=2;
			ct%=1000000007;
		}
		ans*=ct;
		ans%=1000000007;
		return;
	}else{
		if (countr2[stage]==countr1[stage] && countd2[stage]==countd1[stage]){
			if (route1[stage]==1 || countd2[stage]==n-1){
				same++;
				countr2[stage+1]=countr2[stage]+1;
				countd2[stage+1]=countd2[stage]
				dfs2(stage+1);
				return;
			}else {
				if (countr2[stage]==m-1){
					same++;
					countd2[stage+1]=countd2[stage]+1;
					countr2[stage+1]=countr2[stage];
					dfs2(stage+1);
					return;
				}else{ //同一点但往下走 
					diff++;
					countd2[stage+1]=countd2[stage];
					countr2[stage+1]=countr2[stage]+1;
					dfs2(stage+1);
					diff--;
					same++;
					countr2[stage+1]=countr2[stage];
					countd2[stage+1]=countd2[stage]+1;
					dfs2(stage+1);
					return;
				}
			}
		}else if(countr2[stage]==m-1){
			if (countd2[stage]+1==countd1[stage+1]){
				same++;
				countd2[stage+1]=countd2[stage]+1;
				countr2[stage+1]=countr2[stage];
				dfs2(stage+1);
			}else{
				diff++
				countd2[stage+1]=countd2[stage]+1;
				countr2[stage+1]=countr2[stage];
				dfs2(stage+1);
			}
		}else if(countd2[stage]==n-1){
			if (countr2[stage]+1==countr1[stage+1]){
				same++;
				countr2[stage+1]=countr2[stage]+1;
				countd2[stage+1]=countd2[stage];
				dfs2(stage+1);
			}else{
				diff++
				countr2[stage+1]=countr2[stage]+1;
				countd2[stage+1]=countd2[stage];
				dfs2(stage+1);
			}
		}else if (countr2[stage]+1==countr1[stage+1] && countd2[stage]==countd1[stage]){
			same++;
			countd2[stage+1]=countd2[stage];
			countr2[stage+1]=countr2[stage]+1;
			dfs2(stage+1);
			same--;
			diff++;
			countr2[stage+1]=countr2[stage];
			countd2[stage+1]=countd2[stage]+1;
			dfs2(stage+1);
			return;
		}
	}
}
