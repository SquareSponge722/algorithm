#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int p[N],a,a1,b,b1,n,m;
vector <int> dian[N];
char ch[3];
long long f[N][2];
bool v[N];
void dp(int x) {
	v[x]=1;
//	if(dian[x].size()==1&&v[dian[x][0]]) {
//		f[x][1]=p[x];
//		f[x][0]=0;
//	}
	for(unsigned int i=0; i<dian[x].size(); i++) {
		int y=dian[x][i];
		if(v[y])continue;
		dp(y);
		f[x][0]+=f[y][1];
		f[x][1]+=min(f[y][0],f[y][1]);
	}
}
int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>ch;
	for(int i=1; i<=n; i++)
		cin>>p[i];
	for(int i=1; i<n; i++) {
		int x,y;
		cin>>x>>y;
		dian[x].push_back(y);
		dian[y].push_back(x);
	}
	for(int i=1; i<=m; i++) {
		memset(f,0x3f,sizeof(f));
		memset(v,0,sizeof(v));
		for(int x=1;x<=n;x++)
		{f[x][0]=0;
		f[x][1]=p[x];
		}
		cin>>a>>a1>>b>>b1;
		if(a1==1)a1=0;
		else if(a1==0)a1=1;
		if(b1==1)b1=0;
		else if(b1==0)b1=1;
		f[a][a1]=0x3fffffff;
		f[b][b1]=0x3fffffff;
		dp(1);
		if(min(f[1][0],f[1][1])>=0x3fffffff)cout<<"-1"<<endl;
		else cout<<min(f[1][0],f[1][1])<<endl;
	}
	return 0;
}
