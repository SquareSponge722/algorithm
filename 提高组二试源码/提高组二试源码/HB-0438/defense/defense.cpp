#include<bits/stdc++.h>
using namespace std;

#define maxn 100000
#define read(x) scanf("%d",&x)

int n,m;
vector<int> a[maxn+5];
int w[maxn+5];

int mp[maxn+5],cnt;
int mp2[maxn+5];

int f[maxn+5][2];

int main() {
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	read(n),read(m);
	char opr1,opr2;
	while((~scanf("%c",&opr1))&&(!isalpha(opr1)));
	while((~scanf("%c",&opr2))&&(opr2<'0'||opr2>'3'));
	
	for(int i=1;i<=n;i++) {
		read(w[i]);
	}
	
	for(int i=1;i<n;i++) {
		int x,y;
		read(x),read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	if(n<=2000&&opr1=='A') {
		int rt=0;
		for(int i=1;i<=n;i++) {
			if(a[i].size()==1) rt=i;
		}
		int frt=0,nxt=rt;
		mp[++cnt]=rt,mp2[rt]=cnt;
		do {
			for(int i=0;i<a[nxt].size();i++) {
				int x=a[nxt][i];
				if(x==frt) continue;
				else mp[++cnt]=x,mp2[x]=cnt,frt=nxt,nxt=x;
			}
		} while(a[nxt].size()!=1);
		for(int i=1;i<=m;i++) {
			int x,x0,y,y0;
			read(x),read(x0),read(y),read(y0);
			x=mp2[x],y=mp2[y];
			if((x==y+1||y==x+1)&&x0==0&&y0==0) {
				printf("-1\n");
				continue;
			}
			if(x==y&&x0!=y0) {
				printf("-1\n");
				continue;
			}
			for(int j=1;j<=n;j++) {
				f[j][0]=f[j][1]=1e9;
				if((x==j&&x0==1)||(y==j&&y0==1)) {
					f[j][1]=min(f[j-1][0]+w[mp[j]],f[j-1][1]+w[mp[j]]);
				} else if((x==j&&x0==0)||(y==j&&y0==0)) {
					f[j][0]=f[j-1][1];
				} else {
					f[j][1]=min(f[j-1][0]+w[mp[j]],f[j-1][1]+w[mp[j]]);
					f[j][0]=f[j-1][1];
				}
			}
			printf("%d\n",min(f[n][0],f[n][1]));
		}
	}
	
	return 0;
}
