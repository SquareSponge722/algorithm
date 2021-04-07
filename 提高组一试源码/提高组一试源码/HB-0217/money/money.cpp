# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;
int mon[25][120];
int xin[25][120];
int zushu[25];
int xinzushu[25];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>zushu[i];
		for(int j=1;j<=zushu[i];++j){
			cin>>mon[i][j];
		}
	}
	for(int i=1;i<=t;++i){
		sort(mon[i]+1,mon[i]+zushu[i]+1);
	}
	for(int i=1;i<=t;++i){
		xin[i][1]=mon[i][1];
		xinzushu[i]=1;
	}
	int dai,biao=0,ji;
	for(int i=1;i<=t;++i){
		for(int j=2;j<=zushu[i];++j){
			biao=0;
			dai=mon[i][j];
			int k=1;
			for(;k<=xinzushu[i];++k){
				if(dai%xin[i][k]==0) break;
			}
			if(k!=xinzushu[i]+1) continue;
			ji=1;
			for(int u=1;u<=xinzushu[i];++u){
				k=xinzushu[i];
				for(;k>=1;--k){
					if(dai%xin[i][k]%xin[i][ji]==0){
						biao=1;
						break;
					}						
				}				
				if(biao) break;
				ji++;
			}
			if(biao) continue;
			biao=0;
			for(int u=1;u<=xinzushu[i];++u){
				dai-=xin[i][u];
				k=1;
				for(;k<=xinzushu[i];++k){
					if(dai%xin[i][k]==0){
						biao=1;
						break;
					}
				}
				if(biao) break;
				dai+=xin[i][u];
			}
			if(biao) continue;
			xin[i][xinzushu[i]+1]=mon[i][j];
			xinzushu[i]++;
		}
	}
	for(int i=1;i<=t;++i){
		cout<<xinzushu[i]<<endl;
	}
	return 0;
}
