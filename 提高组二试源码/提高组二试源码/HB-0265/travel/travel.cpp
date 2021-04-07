#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int vis[N],rn[N]={0},n,m,cnt=0;
bool r[N][N]={0},visd[N]={0};

void travel(int now){
	for (int i=1;i<=n;i++)
		if (r[now][i] && !visd[i]){
			vis[++cnt] = i;
			visd[i] = 1;
			printf("%d ",i);
			travel(i);
		}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int p1,p2;
		scanf("%d%d",&p1,&p2);
		r[p1][p2] = 1;
		r[p2][p1] = 1;
	}
	printf("1 ");
	visd[1] = 1;
	travel(1);
	printf("\n");
	return 0;
}
