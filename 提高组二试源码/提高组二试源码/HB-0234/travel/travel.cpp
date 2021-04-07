#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include  <stack>
#define inf 5001
using namespace std;
int n,m,u,v,mm[inf],j=1,kk[inf];
bool flag[inf],a[inf][inf],f[inf],mmm;
void dfs1(int k){
	//	cout<<k<<" ";
		for(int i=1;i<=n;i++){
			if(flag[i]==0&&(a[i][k]!=0||a[k][i]!=0)&&i!=k)
			{	flag[i]=1;
				mm[j]=i;
				j++;
			//	cout<<j<<" ";
				if(j==n) break;
				dfs1(i);
				j--;
				flag[i]=0;
			}
		}
		if(j==n){
			for(int i=1;i<=n;i++){
				if(kk[i]<mm[i]) {
					mmm=0;
				//cout<<mmm<<" ";
				break;
				}
				if(kk[i]>mm[i]){
				mmm=1;
			//	cout<<mmm<<" ";
				break;
					}
			}
			if(mmm==1){
				for(int i=1;i<=n;i++){
					kk[i]=mm[i];
				}
			//	fill(mm+1,mm+n+1,0);
			}
			else {
				j=0;
			return ;
			}
			
		}
}            
	void dfs(int k){          
		 for(int i=1;i<=n;i++){
			if(flag[i]==0&&(a[i][k]!=0||a[k][i]!=0)&&k!=i)
			{	flag[i]=1;
				mm[j]=i;
				j++;
				if(j==n) break;
				dfs(i);
				flag[i]=0;
		if(k==n){
			return;
		}
}
}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=m;i++){
 	cin>>u>>v;
 	a[u][v]=1;
 	a[v][u]=1;
 }
 if(n>m){
	 flag[1]=1;
 	mm[0]=1;
 dfs(1);
 	for(int i=0;i<n;i++){
 		cout<<mm[i]<<" ";
	 }
}
	 else{
	 	fill(kk,kk+n+1,inf);

 	flag[1]=1;

	 mm[0]=1;
	 kk[0]=1;
	 dfs1(1);
 	for(int i=0;i<n;i++){
 		cout<<kk[i]<<" ";
	 }
	 }
	return 0;
}
