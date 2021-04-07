#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define N 120
using namespace std;
int a[N],t,n,a1,a2;
bool b[N];
set <int> ss;
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
inline bool kill(int a,int b,int c){
	int left;
	for(int i=0;a*i<=c;++i){
		left=c-a*i;
		if(left%b==0)return 1;
	}
	return 0;
}
inline void work1(){
	cin>>a1>>a2;
	if(a1>a2)swap(a1,a2);
	if(a2%a1==0){
		cout<<1<<endl;
	} 
	else cout<<2<<endl;
}
void work2(){
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;++i){
		if(b[i])continue;
		for(int j=i+1;j<=n;++j){
			if(b[j])continue;
			for(int k=1;k<=n;++k){
				if(b[k])continue;
				if(i==k||j==k)continue;
				b[k]=kill(a[i],a[j],a[k]);
				cout<<a[k]<<' '<<b[k]<<endl;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(!b[i])cnt++;
	}
	cout<<cnt<<endl;
}
void work3(){//把某些三个数的情况解决一下 
	ss.clear();
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;++i){
		for(int j=2;a[i]*j<=50;++j){
			ss.insert(a[i]*j);//筛去 
		}
	}
	ss.insert(0);
	bool ok=1;
	while(ok){
		ok=1;
		for(int i=1;i<=40;++i){
			if(ss.count(i)){
				for(int j=i+1;j<=40;++j){
					if(ss.count(j)){
						if(!ss.count(i+j)){
							ok=0;
							ss.insert(i+j);
						}
					}
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(ss.count(a[i])==0)cnt++;
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			work1();continue;
		}
		if(n==3||n==4||n==5){//
			for(int i=1;i<=n;++i){
				a[i]=read();
			}
			sort(a+1,a+n+1);
			work2();continue;//结束 
		}
		for(int i=1;i<=n;++i){//剩下的情况 
			a[i]=read();
		}
		sort(a+1,a+n+1);
		work3();
	}
	return 0;
} 
