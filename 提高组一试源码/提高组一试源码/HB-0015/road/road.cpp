#include<bits/stdc++.h>
using namespace std;
const int N=100500;
long long ans=0;
int n,a[N];
int jc[20];
int st[N][20];
void work(int x,int y,int z) {
	if(x>y)return;
	int len=y-x+1,pos1;
	int m=log(y-x+1)/log(2);
	int minn=min(st[x][m],st[y-jc[m]+1][m]);
	for(int i=x; i<=y; i++) {
		if(minn==a[i])
			pos1=i;
	}
	ans+=(minn-z);
		work(x,pos1-1,minn);
		work(pos1+1,y,minn);
//	else if(pos==x&&pos!=y)work(x+1,y,minn);
//	else if(pos==y&&pos!=x)work(x,y-1,minn) 
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	memset(st,0x3f,sizeof(st));
	memset(jc,0,sizeof(jc));
	cin>>n;
//	int minn1=0x7fffffff,pos;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		st[i][0]=a[i];
		//	minn1=min(minn1,a[i]);
	}
	int t=log(n)/log(2)+1;
	jc[0]=1;
	for(int i=1; i<=t; i++)
		jc[i]=jc[i-1]*2;
	for(int i=1; i<=t; i++)
		for(int j=1; j<=n&&(j+jc[i-1]-1<=n); j++) {
			st[j][i]=min(st[j][i-1],st[j+jc[i-1]][i-1]);
			//	cout<<j<<" "<<i<<" "<<st[j][i]<<endl;
		}
	work(1,n,0);
	cout<<ans<<endl;
	return 0;
}
