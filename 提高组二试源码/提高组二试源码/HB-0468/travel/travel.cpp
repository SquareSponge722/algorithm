#include<bits/stdc++.h>
using namespace std;
int have[5005][5005];
int n,m,minn=5005,maxn=0,a[5005],k=0;

void solve(int y){
	int s=0;
	for(int i=minn;i<=maxn;i++){
		if (have[y][i]==1) {//min>i
			have[y][i] = 0;
			have[i][y] = 2;
			a[k++]=i;
			for(int j=minn;j<=maxn;j++)
				if(j!=i && have[j][y]==1) have[j][y] = 0;
			if(k<n) solve(i);
			s=1;
			break;
		}
	}
	if(s==0 && k<n) 
		for(int i=minn;i<=maxn;i++)
			if (have[y][i]==2) solve(i);
	if(k==n)return;
} 

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(x<minn) minn = x;
		if(y<minn) minn = y;
		if(x>maxn) maxn = x;
		if(y>maxn) maxn = y;
		have[x][y] = 1;
		have[y][x] = 1; 
	}	
	a[k]=minn;
	k++;
	solve(minn);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
