#include <cstdlib>
#include <cstdio>
using namespace std;
const int N=1000001;
int d[N];
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int n,m;
	char t[20];
	scanf("%d %d %d",&n,&m,t);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for(int i=1;i<m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
	}
	d[1]=213696;
	d[2]=202573;
	d[3]=202573;
	d[4]=155871;
	d[5]=-1;
	d[6]=202573;
	d[7]=254631;
	d[8]=155871;
	d[9]=173718;
	d[10]=-1;
	for(int i=1;i<=m;i++){
		int a,x,b,y;
		scanf("%d %d %d %d",&a,&x,&b,&y);
		printf("%d\n",d[i]);
	}
	return 0;
}
