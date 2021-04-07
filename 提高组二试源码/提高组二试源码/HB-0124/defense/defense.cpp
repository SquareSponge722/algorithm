#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
string good;
int val[101010];
int x,a,y,b;

void A1();
void A2();
void A3();
long long workA3();
long long workA2();
long long workA1();

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m;
	cin>>good;
	memset(val,0x3f,sizeof(val));
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<n;i++){
		int tmp1=0,tmp2=0;
		cin>>tmp1>>tmp2;
	}
	A3();
	return 0;
}

void A1(){
	for(int i=1;i<=m;i++){
		cin>>x>>a>>y>>b;
		if((x==y+1||y==x+1)&&(a==0&&b==0)){
			cout<<"-1"<<endl;
			continue;
		}else{
			cout<<workA1()<<endl;
		}
	}
}

long long workA1(){
	long long ans1=0;
	long long ans=0;
	ans+=val[1];
	for(int i=3;i<=n;i+=2){
	 	if(x==i||x==i+1){
	 		if(a==1){
	 			ans+=val[x];
			 }else{
			 	ans+=val[i]+val[i+1]-val[x];
			 }
			 continue;
		 }
		 if(y==i||y==i+1){
		 	if(b==1){
		 		ans+=val[y];
			 }else{
			 	ans+=val[i]+val[i+1]-val[y];
			 }
			 continue;
		 }
		 ans+=min(val[i],val[i+1]);
	 }
	 ans+=val[2];
	 for(int i=4;i<=n;i+=2){
	 	if(x==i||x==i+1){
	 		if(a==1){
	 			ans1+=val[x];
			 }else{
			 	ans1+=val[i]+val[i+1]-val[x];
			 }
			 continue;
		 }
		 if(y==i||y==i+1){
		 	if(b==1){
		 		ans1+=val[y];
			 }else{
			 	ans1+=val[i]+val[i+1]-val[y];
			 }
			 continue;
		 }
		 ans1+=min(val[i],val[i+1]);
	 }
	 return min(ans1,ans);
}

void A2(){
	for(int i=1;i<=m;i++){
		cin>>x>>a>>y>>b;
		if((x==y+1||y==x+1)&&(a==0&&b==0)){
			cout<<"-1"<<endl;
			continue;
		}else{
			cout<<workA2();
		}
	}
}

long long workA2(){
	long long ans1=0;
	long long ans=0;
	ans+=val[1];
	for(int i=3;i<=n;i+=2){
	 	if(x==i||x==i+1){
	 		if(a==1){
	 			ans+=val[x];
			 }else{
			 	ans+=val[i]+val[i+1]-val[x];
			 }
			 continue;
		 }
		 if(y==i||y==i+1){
		 	if(b==1){
		 		ans+=val[y];
			 }else{
			 	ans+=val[i]+val[i+1]-val[y];
			 }
			 continue;
		 }
		 ans+=min(val[i],val[i+1]);
	 }
	 ans+=val[2];
	 for(int i=4;i<=n;i+=2){
	 	if(x==i||x==i+1){
	 		if(a==1){
	 			ans1+=val[x];
			 }else{
			 	ans1+=val[i]+val[i+1]-val[x];
			 }
			 continue;
		 }
		 if(y==i||y==i+1){
		 	if(b==1){
		 		ans1+=val[y];
			 }else{
			 	ans1+=val[i]+val[i+1]-val[y];
			 }
			 continue;
		 }
		 ans1+=min(val[i],val[i+1]);
	 }
	 return min(ans1,ans);
}

void A3(){
	for(int i=1;i<=m;i++){
	//	cout<<x<<a<<y<<b<<endl;
		cin>>x>>a>>y>>b;
	//	cout<<x<<a<<y<<b<<endl;
		if((x==y+1||y==x+1)&&(a==0&&b==0)){
			cout<<"-1"<<endl;
			continue;
		}else{
			cout<<workA3()<<endl;;
		}
	}
	return;
}

long long workA3(){
	long long ans=0;
	 long long ans1=0;
	 ////////////////////
	 ans1+=val[2];
	 for(int i=4;i<=n;i+=2){
	 	bool pd=false;
	 	if(x==i||x==i+1){
	 		if(a==1){
	 			ans1+=val[x];
			 }else{
			 	if(x==i){
			 		ans1+=val[i+1];
				 }
				 else
			 	ans1+=val[i];
			 }
			 pd=true;
		 }
		 if(y==i||y==i+1){
		 	if(b==1){
		 		ans1+=val[y];
			 }else{
			 	if(y=i){
			 		ans1+=val[i+1];
				 }
				 else
			 		ans1+=val[i];
			 }
			 pd=true;
		 }
		 if(pd){
		 	continue;
		 }
		 ans1+=min(val[i],val[i+1]);
	 }
	 //////////////////////
	 ans+=val[1];
	 for(int i=3;i<=n;i+=2){
	 	if(x==i||x==i+1){
	 		if(a==1){
	 			ans+=val[x];
			 }else{
			 	if(x==i)
			 	ans+=val[i+1];
			 	else ans+=val[i];
			 }
			 continue;
		 }
		 if(y==i||y==i+1){
		 	if(b==1){
		 		ans+=val[y];
			 }else{
			 	if(y==i)
			 	ans+=val[i+1];
			 	else ans+=val[i];
			 }
			 continue;
		 }
		 ans+=min(val[i],val[i+1]);
	 }
	 return min(ans,ans1);
}
