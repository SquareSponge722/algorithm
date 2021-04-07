#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <queue>
#define maxn 100001
#define ll long long
using namespace std;
inline int read(){
	char ch;
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
int n,m,cnt,costa[maxn],head[maxn],sumodd,sumeve;
ll ans;
struct edge{
	int to,nxt;
}edges[maxn<<1];
void add(int u,int v){
	cnt++;
	edges[cnt].to=v;
	edges[cnt].nxt=head[u];
	head[u]=cnt;
}
void work1(){
	for(int i=1;i<=m;i++){
		int a=read(),x=read(),b=read(),y=read();
		if(!x && !y && a%2!=b%2){
			printf("-1\n");
		}
		else if(!x && !y && a%2==b%2){
			if(a%2){
				printf("%d\n",sumodd);
			}
			else{
				printf("%d\n",sumeve);
			}
		}
		else if(!x && y){
			if(a%2){
				if(b%2){
					printf("%d\n",sumeve+costa[b]);
				}
				else{
					printf("%d\n",sumeve);
				}
			}
			else{
				if(b%2){
					printf("%d\n",sumodd);
				}
				else{
					printf("%d\n",sumodd+costa[b]);
				}
			}
		}
		else if(!y && x){
			if(b%2){
				if(a%2){
					printf("%d\n",sumeve+costa[a]);
				}
				else{
					printf("%d\n",sumeve);
				}
			}
			else{
				if(a%2){
					printf("%d\n",sumodd);
				}
				else{
					printf("%d\n",sumodd+costa[a]);
				}
			}
		}
		else if(a%2==b%2){
			if(a%2){
				printf("%d\n",sumodd);
			}
			else{
				printf("%d\n",sumeve);
			}
		}
		else{
			if(a%2==1 && b%2==0){
				swap(a,b);
			}
			if(sumodd>=sumeve){
				printf("%d\n",sumeve+costa[b]);
			}
			else{
				printf("%d\n",sumodd+costa[a]);
			}
		}
	}
}
void work2(){
	for(int i=1;i<=m;i++){
		int dp[maxn][2]={0};
		int a=read(),x=read(),b=read(),y=read();
		if(x){
			dp[a][0]=-1;
		}
		else{
			dp[a][1]=-1;
		}
		if(y){
			dp[b][0]=-1;
		}
		else{
			dp[b][1]=-1;
		}
		for(int i=1;i<=n;i++){
			if(dp[i][1]!=-1){
				if(dp[i-1][1]!=-1 && dp[i-1][0]!=-1)
					dp[i][1]=min(dp[i-1][1],dp[i-1][0])+costa[i];
				else if(dp[i-1][1]==-1 && dp[i-1][0]!=-1){
					dp[i][1]=dp[i-1][0]+costa[i];
				}
				else if(dp[i-1][1]!=-1 && dp[i-1][0]==-1){
					dp[i][1]=dp[i-1][1]+costa[i];
				}
			}
			if(dp[i][0]!=-1 && dp[i-1][1]!=-1){
				dp[i][0]=dp[i-1][1]+costa[i];
			}
		}
		printf("%d\n",min(dp[n][1],dp[n][2]));
	}
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=read();
	m=read();
	string str;
	cin>>str;
	for(int i=1;i<=n;i++){
		costa[i]=read();
		if(i%2){
			sumodd+=costa[i];
		}
		else{
			sumeve+=costa[i];
		}
	}
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	work1();
	return 0;
}
