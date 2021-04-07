#include<bits/stdc++.h>
using namespace std;
int t;
int n,ans,m;
int xx,yy,ww;
vector<int>head[10001];
int f[500][500];
bool ok,jk;
int anss[100001],asa;
struct node{
	friend bool operator < (node aa,node bb){
		return aa.nw>bb.nw;
	}
	int nx,ny,nw;
}a[100001];
void qzs(){
	void floyd();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)ans=max(ans,f[i][j]);
	printf("%d",ans);
}
void floyd(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(!f[j][i]&&j!=i)f[j][i]=100000005;
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
int main(){  
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	ok=1;jk=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&xx,&yy,&ww);
		head[xx].push_back(yy);
		head[yy].push_back(xx);
	f[xx][yy]=ww;
	f[yy][xx]=ww;
	if(xx+1!=yy)ok=0;
	if(xx!=1)jk=0;
	a[i].nx=xx;
	a[i].ny=yy;
	a[i].nw=ww;
	}
		if(m==1){
		//dfs();
	if(n<=10){
	floyd();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)ans=max(ans,f[i][j]);
	printf("%d",ans);
	return 0;
	}
	
	
	}
	else {
		if(jk){
			sort(a+1,a+n);
			//
			if(m==1)
			{cout<<a[1].nw+a[2].nw;return 0;}
		// 
		else {asa=10000011;
			for(int i=1;i<=m;i++){
		anss[i]=a[i].nw+a[2*m-i+1].nw;
		asa=min(asa,anss[i]);		
			}
			cout<<asa;return 0;
		}
		//
		}
	}
	qzs();
	return 0;
	
	}
