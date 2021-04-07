#include<bits/stdc++.h>
using namespace std;
int n,mn=10005,l=1,cnt=0,cnt1=1,cnt2,cnt3;
long long ans=0;
int d[100005];
int zero[100005]={0};bool mmm=1;

inline int read(){
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') k=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*k;
}

void dfs(int left,int right){
	if(left==right){
		ans+=d[left];
		return;
	}
	
	bool aaaa=1;
	for(int i=left;i<=right;i++)
		if(d[i]) aaaa=0;
	if(aaaa) return ;
	
	int minn=10005;
	for(int i=left;i<=right;i++)
		minn=min(d[i],minn);
	ans+=minn;
	
	for(int i=left;i<=right;i++){
		d[i]-=minn;
		if(!d[i]) zero[cnt2++]=i;
	}	
	for(int i=left;i<=right;i++){
		if(d[left]) {
			dfs(left,zero[cnt3]-1);
			dfs(zero[cnt3]+1,zero[cnt3+1]-1);
			cnt3++;
		}
		else cnt3++,left++;
	}	
}

void query(){
	for(int i=1;i<=n;i++){
		if(cnt==1){
			if(d[1]==0) dfs(2,n);
			else if(d[n]==0) dfs(1,n-1);
			else{
				dfs(1,i-1);
				dfs(i+1,n);
			}
		}
		else{
			if(cnt1<cnt&&zero[cnt1+1]!=0){
				if(zero[cnt1]==1){
					dfs(2,zero[cnt1]-1);
					dfs(zero[cnt1]+1,zero[cnt1+1]-1);
				}
				else if(mmm){
					dfs(1,zero[cnt1]-1);
					dfs(zero[cnt1]+1,zero[cnt1+1]-1);
					cnt1++;mmm=0;
				}
				else{
					dfs(zero[cnt1-1]+1,zero[cnt1]-1);
					dfs(zero[cnt1]+1,zero[cnt1+1]-1);
					cnt1++;
				}
			}
			else{
				dfs(zero[cnt1]+1,n);
			}			
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		d[i]=read(),mn=min(mn,d[i]);
	ans+=mn;
	for(int i=1;i<=n;i++){
		d[i]-=mn;
		if(d[i]==0){
			zero[++cnt]=i;
			cnt2=cnt+1,cnt3=cnt+1;
		}
	}
	query();
	printf("%lld",ans);
	return 0;
}
