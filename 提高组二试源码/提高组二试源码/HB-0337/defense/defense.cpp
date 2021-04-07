#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch;
	int f=1;
	int num=0;
	ch=getchar();
	if(ch=='-'){
		f=-1;
		ch='0';
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*f;
}
int n,m;
char a[2];
int cost[100001];
long long ans1,ans2;
int u1,v1,u2,v2;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();
	m=read();
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>cost[i];
	}
	for(int i=0;i<n-1;i++){
		u1=read();
		v1=read();
	}
	for(int i=0;i<m;i++){
		ans1=ans2=0;
		u1=read();
		v1=read();
		u2=read();
		v2=read();
		if(v1+v2==0&&(u2-u1==-1||u2-u1==1)){
			cout<<-1<<'\n';
		}
		else{
			for(int i=0;i<n;i++){
				if(i%2==0||i==u1*v1||i==u2*v2){
					ans1+=cost[i];
				}
				if(i%2==1||i==u1*v1||i==u2*v2){
					ans2+=cost[i];
				}
			}
			cout<<min(ans1,ans2)<<'\n';
		}
	}
	return 0;
}
