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
int n,t;
int a[101];
int f;
bool dfs(int value,int step){
	for(int i=0;i<f;i++){
		if((a[f]-value)%a[i]==0){
			return 1;
		}
	}
	if(step>=f&&value!=a[f]){
		return 0;
	}
	int o=value;
	while(o<=a[f]){
		if(dfs(o,step+1)==1)return 1;
		o+=a[step];
	}
	return 0;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		int ans=n;
		for(int i=0;i<n;i++){
			a[i]=read();
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			f=i;
			if(dfs(0,0)==1)ans--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

