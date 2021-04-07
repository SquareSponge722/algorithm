#include<bits/stdc++.h>
using namespace std;
int n,m;
int ww[10001],xx,yy,d[6001],ans[10001];
int sum,tot,l;
int ll,inq[6000],aa,bb,num1,num2,dd[6000];
bool p[6001];
vector<int>head[10001];
string s;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
cin>>n>>m;
cin>>s;
//cout<<s[0];
for(int i=1;i<=n;i++){
	scanf("%d",&ww[i]);sum+=ww[i];
}
for(int i=1;i<n;i++){
	scanf("%d%d",&xx,&yy);
	head[xx].push_back(yy);
	head[yy].push_back(xx);
}
if(s[0]=='A'){
//
for(int uu=1;uu<=m;uu++){
	scanf("%d%d%d%d",&aa,&num1,&bb,&num2);

if(aa>bb)if(num1==0&&num2==0&&aa-1==bb){
	cout<<"-1"<<endl;continue;
}
if(aa<bb)if(num1==0&&num2==0&&aa==bb+1){
	cout<<"-1"<<endl;continue;
}
//
for(int i=1;i<=n;i+=2){
	tot+=ww[i];
}
//
if(tot>sum-tot){
if(aa%2==0&&num1==1&&bb%2==0&&num2==1){
	cout<<sum-tot<<endl;continue;
}	
if(aa%2==0&&num1==1&&bb%2==1&&num2==0){
	cout<<sum-tot<<endl;continue;
}	
if(aa%2==1&&num1==0&&bb%2==0&&num2==1){
	cout<<sum-tot<<endl;continue;
}	
if(aa%2==1&&num1==0&&bb%2==1&&num2==0){
	cout<<sum-tot<<endl;continue;
}	

}
//
}}
	return 0;
}
