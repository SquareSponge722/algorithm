#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1;
	int num=0;
	char ch;
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
int n;
int a[100001];
int mi=99999;
int cnt;
int empty;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++){
		a[i]=read();
		if(a[i]<mi){
			mi=a[i];
		}
	}
	cnt+=mi;
	for(int i=0;i<n;i++){
		a[i]-=mi;
		if(a[i]==0){
			empty++;
		}
	}
	while(empty<n){
		int now=0;
		int first=0;
		while(now<n){
			if(a[now]==0){
				while(a[now++]==0){}
				now--;
			}
			first=now;
			int mm=99999;
			while(a[now]!=0){
				if(a[now]<mm){
					mm=a[now];
				}
				now++;
			}
			for(int i=first;i<now;i++){
				a[i]-=mm;
				if(a[i]==0){
					empty++;
				}
			}
			cnt+=mm;
			if(empty==n){
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

