#include<bits/stdc++.h>
using namespace std;
const int N=10005;

struct edge {
	int from,to;
} e[N];

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m,ans;
	char ch[5];
	int w[N];
	cin>>n>>m>>ch;
	for(int i=1; i<=n; i++)   cin>>w[i];
	for(int i=1; i<=m; i++)  cin>>e[i].from>>e[i].to;
	for(int j=1; j<=m; j++) {
		int a,b,x,y;
		cin>>a>>x>>b>>y;
		for(int i=1; i<=m; i++) {
			if(e[i].from==a && e[i].to==b && x==0 && y==0) {
				ans=-1;
				cout<<ans<<endl;
			}

			else {
				for(int i=1; i<=n; i++) {
					if(w[e[i].from] >= w[e[i].to])  {
						ans+=w[e[i].to];
						w[e[i].to] = 0;
						w[e[i].from] = 0;
					}
					 else {
						ans+=w[e[i].from];
						w[e[i].to] = 0;
						w[e[i].from] = 0;
					}
				}

			}

		}
		cout<<ans<<endl;
	}
	return 0;
}
