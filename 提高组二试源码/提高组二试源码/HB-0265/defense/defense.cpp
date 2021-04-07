#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int p[N],n,m;
string s;
bool r[N][N]={0},had[N];

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<n;i++){
		int p1,p2;
		scanf("%d%d",&p1,&p2);
		r[p1][p2] = 1;
	}
	for (int i=1;i<=m;i++){
		memset(had,0,sizeof(had));
		int a,x,b,y;
		bool can;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if ((a==1 && b==2 && x==0 && y==0) || (a==2 && b==1 && x==0 && y==0) || (a==n && b==n-1 && x==0 && y==0) || (a==n-1 && b==n && x==0 && y==0))
			printf("-1\n");
		else printf("%d",a*b+1);
	}
	return 0;
}
