//混分就是了 
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define N 110000
#define LL long long
using namespace std;
LL a[N],n,m,b[N];
LL f[N][2];
string s;
inline LL read(){
	LL sum=0,fu=-1;char a=getchar();
	while(a>'9'||a<'0'){
		if(a=='-')fu=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		sum=(sum<<3)+(sum<<1)+a-'0';
		a=getchar();
	}
	return sum*fu;
}
void dp(){
	for(int i=1;i<=n;++i){
		f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
		f[i][0]=f[i-1][1];
	}
//	cout<<min(f[n][1],f[n][0])<<endl;
}
long long ans;
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	cin>>n>>m>>s;
	int s1,s2;
	for(int i=1;i<=n;++i){
		a[i]=read();b[i]=a[i];
	}
	for(int i=1;i<n;++i){
		s1=read();s2=read();
	}
	int s3,s4;
	while(m--){
		memset(f,0,sizeof(f));
		s1=read();s2=read();s3=read();s4=read();
		if(s1==s3-1||s3==s1-1){
			if(s2==0&&s4==0){
				cout<<-1<<endl;continue;
			}
		}
		if(s2==0)a[s1]+=1e11;
		if(s2==1)a[s1]-=1e11;
		if(s4==0)a[s3]+=1e11;
		if(s4==1)a[s3]-=1e11;
		dp();
		ans=min(f[n][1],f[n][0]);
		if(s2)ans+=1e11;
		if(s4)ans+=1e11;
		cout<<ans<<endl;
		a[s1]=b[s1];
		a[s3]=b[s3];
	}
	return 0;
}
