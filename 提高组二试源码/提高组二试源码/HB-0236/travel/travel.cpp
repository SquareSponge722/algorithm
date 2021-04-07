#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,u,v;
bool k[N],h[N][N],f[N][N];
string s="99",s0;
inline int len(int a) {
	int k=a,ans=0;
	while(k) {
		k/=10;
		ans++;
	}
	return ans;
}
inline string str(int a) {
	int k=a;
	string s1,s2;
	while(k) {
		s1+=char(k%10+'0');
		k/=10;
	}
	for(int i=0; i<s1.size(); i++)s2+=s1[s1.size()-i-1];
	return s2;
}
inline void start(int a) {
	if(!k[a])s0+=str(a);
	k[a]=true;
	if(s0>s)return;
	for(int i=1; i<=n; i++)
		if(k[i]==false)break;
		else if(i==n) {
			s=s0;
			return;
		}
	for(int i=1; i<=n; i++)
		if(f[a][i])
			if(!k[i]) {
				k[i]=true;
				s0+=str(i);
				start(i);
			} else if(h[a][i]) {
				h[a][i]=true;
				h[i][a]=true;
				s0.erase(s0.size()-len(a),s0.size());
				start(i);
			}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>u>>v;
		f[u][v]=true;
		f[v][u]=true;
	}
	for(int i=1; i<=n; i++) {
		start(i);
		fill(k,k+n+1,0);
		fill(h[0],h[0]+(n+1)*(n+1),0);
	}
	for(int i=0; i<s.size(); i++)cout<<s[i]<<" ";
	return 0;
}
