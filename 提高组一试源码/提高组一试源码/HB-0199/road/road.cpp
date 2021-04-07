#include<bits/stdc++.h>
using namespace std;
int n,m,tot,uu;
int ans,num,ww;
int d[1000100];
bool ok;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	ans=-1;
	for(int i=1;i<=n;i++)
	{	scanf("%d",&d[i]);
//if(d[i]==0&&d[i+1]!=0)ww++;	
if(d[i]>ans)ans=d[i];
}//ww=1;
//cout<<ans<<endl;
for(int i=1;i<=ans;i++){
//for(int j=1;j<=n;j++)inq[j]=0;
	ok=0;
	uu=0;
	for(int j=1;j<=n;j++)
	{
if(d[j]-i>=0){
	if(ok!=1){
		uu++;ok=1;
	}
}
else {
	if(ok==1){
		uu++;ok=0;
	}
}
	}
	
	
/*	
if(d[1]-i<0&&d[n]-i>=0){//cout<<i<<"m";
	uu=uu/2;//continue;
}
if(d[1]-i<0&&d[n]-i<0){
	uu=uu/2-1;//continue;
}
if(d[1]-i>=0&&d[n]-i>=0){
	uu=uu/2+1;//continue;
}*/
if(uu%2==1){
	++uu;
if(d[1]-i<0&&d[n]-i<0){
	uu=uu/2-1;//continue;
}
else {
	uu=uu/2;//continue;
	//cout<<uu<<endl;
	//tot+=uu;
}
}
else {
	uu/=2;
}
tot+=uu;
}
cout<<tot;
	return 0;
}
