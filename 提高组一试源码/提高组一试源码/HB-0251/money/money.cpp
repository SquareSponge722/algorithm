#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxa 1001
#define maxviolent 25001
#define maxn 101
using namespace std;
int n,t,maxx,num[maxn];
inline int read(){
	char ch=getchar();
	int ans=0,cf=1;
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			cf=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*cf;
}
void work1(){
	int vis[maxa]={0},ans=n;
	for(int i=1;i<=n;i++){
		int tmp=num[i];
		for(int j=1;j<=maxx;j++){
			if(vis[j]){
				int tmp=num[i];
				while(tmp<=maxx){
					vis[j+tmp]++;
					tmp+=num[i];
				}
			}
		}
		while(tmp<=maxx){
			vis[tmp]++;
			tmp+=num[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[num[i]]>1){
			ans--;
		}
	}
	printf("%d\n",ans);
	return;
}
void work2(){
	if((num[1]%num[2]==0) || (num[2]%num[1]==0)){
		printf("1\n");
	}
	else{
		printf("2\n");
	}
	return;
}
void work3(){
	int vis[maxviolent]={0},ans=n;
	for(int i=1;i<=n;i++){
		int tmp=num[i];
		for(int j=1;j<=maxx;j++){
			if(vis[j]){
				int tmp=num[i];
				while(tmp<=maxx){
					vis[j+tmp]++;
					tmp+=num[i];
				}
			}
		}
		while(tmp<=maxx){
			vis[tmp]++;
			tmp+=num[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[num[i]]>1){
			ans--;
		}
	}
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		n=read();
		bool sign=0;
		for(int i=1;i<=n;i++){
			num[i]=read();
			if(num[i]==1){
				sign=1;
			}
			maxx=max(num[i],maxx);
		}
		if(sign){
			printf("1\n");
		}
		else if(n==2){
			work2();
		}
		else if(maxx<=1000){
			work1();
		}
		else{
			work3();
		}
	}
	return 0;
}

