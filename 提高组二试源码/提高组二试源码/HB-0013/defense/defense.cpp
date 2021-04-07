#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int n=0,m=0;
string type;
int p[2001]={0};
int book[2001]={0};
int able[2001]={0};
int ans[2001];
int rc,amir;
int require[5][2001]={0};//1=a 2=x 3=b 4=y
	
void dfs(int sp,int requirenumber){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=sum+able[i];
	}
	if(sum==n){
		if(sp<=ans[requirenumber]){
			ans[requirenumber]=sp;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0){
			book[i]=1;
			able[i]=1;
			able[i+1]=1;
			able[i-1]=1;
			dfs(sp+p[i],requirenumber);
			book[i]=0;
			if((((i!=require[1][requirenumber]-1||i!=require[1][requirenumber]+1)&&require[2][requirenumber]==1)||(require[2][requirenumber]==0))||
				(((i!=require[3][requirenumber]-1||i!=require[3][requirenumber]+1)&&require[4][requirenumber]==1)||(require[4][requirenumber]==0)))
			able[i]=0;
			if(require[2][requirenumber]!=1){
				able[require[1][i]+1]=0;
				able[require[1][i]-1]=0;
			}
			if(require[4][requirenumber]!=1){
				able[require[3][i]+1]=0;
				able[require[3][i]-1]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>type;
	for(int i=1;i<=2000;i++){
		ans[i]=999999999;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<n;i++){
		cin>>rc>>amir;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=4;j++){
			cin>>require[j][i];
		}
	}
	if(type=="A3"){
		for(int i=1;i<=m;i++){
			int requireprice=0;
			if(require[2][i]==1){
				requireprice+=p[require[1][i]];
				book[require[1][i]]=1;
				able[require[1][i]]=1;
				able[require[1][i]+1]=1;
				able[require[1][i]-1]=1;
			}
			if(require[4][i]==1){
				requireprice+=p[require[3][i]];
				book[require[3][i]]=1;
				able[require[3][i]]=1;
				able[require[3][i]+1]=1;
				able[require[3][i]-1]=1;
			}
			dfs(requireprice,i);
			cout<<ans[i]<<endl;
			for(int i=0;i<=2000;i++){
		 		book[i]=0;
				able[i]=0;
			}

		}
	}
	else{
		for(int i=1;i<=m;i++) cout<<-1<<endl;
	}
	return 0;
}
