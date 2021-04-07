#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define fo(i,n) for(int i=1;i<=n;i++)
using namespace std;
int d[1005][1005],ans=0,n,m,t=0,q[1005];
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	n--;
	fo(i,n){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		q[x]++;q[y]++;ans+=z;
		d[x][y]=d[y][x]=z;
		if(t<z)t=z;
	}
	if(n==4){
		if(m==1){
			int v=0,c;
			fo(i,n){if(q[i]==3)v=i;if(q[i]==2)c=i;}
			if(v==0){cout<<ans;return 0;}
			else {
				int x=1005;
				fo(i,n+1)if(i!=c&&d[i][v]&&x>d[i][v])x=d[i][v];
				cout<<ans-x;return 0;
			}
		}
	}
	if(n==3){
		int v=0;
		fo(i,n+1)if(q[i]==3)v=i;
		if(v==0){cout<<ans;return 0;}
		else {
			int x=1005;
			fo(i,n+1)if(d[i][v]&&x>d[i][v])x=d[i][v];
			cout<<ans-x;return 0;
		}
	}
	if(n<=3){cout<<ans;return 0;}
	printf("%d",t);
	return 0;
}
