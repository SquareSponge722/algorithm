#include<iostream>
#include<cstdio>
#define N 51000
using namespace std;
int a[N],n,m;
inline int read(){
	int sum=0,fu=1;char a=getchar();
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
bool work(int x){
	int sum=0,now=0;
	for(int i=1;i<n;++i){
		now+=a[i];
		if(now>x){
			now=0;sum++; 
		}
	}
	return sum>=m;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	int s1,s2,s3;
	for(int i=1;i<n;++i){
		s1=read();s2=read();s3=read();
		s1=min(s1,s2);
		a[s1]=s3;
	}
	int l=0,r=1e9;int mid=(l+r)>>1;
	int c=work(mid);
	while(l<=r){
		if(c){
			l=mid+1;
			mid=(l+r)>>1;
		}
		else{
			r=mid-1;
			mid=(l+r)>>1;
		}
		c=work(mid);
	}
	cout<<l<<endl;
} 
