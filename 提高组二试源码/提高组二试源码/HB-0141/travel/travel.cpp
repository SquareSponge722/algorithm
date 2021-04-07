#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int r=1,n,m,front,minn=N;
int booker[N],num1[N],num2[N];
bool book[N][N],T=1;
char s[N],maxs[N];

void dfs(int i){
	if(r==n){
		for(int j=1;j<=n;j++){
			maxs[j]=s[j];
		}
		for(int i=1;i<=n;i++){
			cout<<maxs[i]<<" ";
		}
		T=0;
	}
	else if(T){
		for(int j=1;j<=n;j++){
			if(book[i][j]&&!booker[j]){
				if(j>minn){
					int k=minn;
					r++;
					s[r]=minn+'0';
					booker[minn]=1;
					minn=N;
					dfs(k);
					//booker[minn]=0;
				}
				else{
					if(!num2[i]) for(int k=1;k<=n;k++){
						if(k!=j&&book[i][k]) minn=k;
					}
					r++;
					s[r]=j+'0';
					booker[j]=1;
					dfs(j);
				}
			}
		}	
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		book[u][v]=1;
		book[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(book[i][j]){
				num1[i]++;
				num1[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(num1[i]==1||num1[i]==2) num2[i]=1;
	}
	s[1]='1';
	booker[1]=1;
	dfs(1);
	return 0;
}
