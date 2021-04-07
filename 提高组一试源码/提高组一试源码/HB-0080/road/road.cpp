#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
const int MAXN = 100010;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	int ans=0;
	scanf("%d",&n);
	int tmax=0;
	//int tmin=0x7fffffff;
	//int gmin=-1;
	int last_max=0;
	int temp=0;
	int flag=0;//0 waiting;1 ->;2 <-
	int o_flag=0;//0 unknown
	int last=0x7fffffff;
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(!temp)temp=tmp;
		if(last!=0x7fffffff){
			if(flag==0){
				if(tmp>last){//1
					flag=1;
					tmax=tmp;
					//tmin=tmp;
				}else if(tmp<last){//2
					flag=2;
				}
			}else if(flag==1){
				if(tmp>=last){
					tmax=tmp;
				}else{
					ans+=tmax;
					last_max=tmax;
					//if(gmin==-1)gmin=tmin;
					tmax=tmp;
					//tmin=tmp;
					o_flag=1;
					flag=0;
					//cout<<i<<endl;
				}
			}else{
				if(tmp>last){
					if(o_flag!=1)ans+=tmax;
					else if(last>last_max)ans+=last-last_max;
					//if(gmin==-1)gmin=tmin;
					tmax=tmp;
					o_flag=2;
					flag=0;
					//cout<<i<<endl;
				}else{
					//tmin=tmp;
				}
			}
		}else{
			tmax=tmp;
			//tmin=tmp;
		}
		last=tmp;
	}
	ans+=tmax;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
