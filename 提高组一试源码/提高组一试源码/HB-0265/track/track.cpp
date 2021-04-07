#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int sst[N],rd[N],rdn[N]={0},n,m,now=0,ck,stop=0;

struct Edge{
	int from,to,wei;
	bool used=false;
}e[N];

void sch(int i){
	for (int i=1;i<=rdn[i];i++){
		if (!e[rd[i]].used){
			now += e[rd[i]].wei;
			e[rd[i]].used = true;
			int had=0;
			for (int j=1;j<=rdn[e[rd[i]].to];j++)
				if (!e[rd[j]].used) had=1;
			if (!had){
				sst[ck] = max(sst[ck],now);
				stop = 0;
				return;
			}
			sch(e[rd[i]].to);
			if (stop) return;
			now -= e[rd[i]].wei;
			e[rd[i]].used = false;
		}
	}
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(sst,0,sizeof(sst));
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].wei);
		rdn[e[i].from]++;
		rd[rdn[e[i].from]] = i;
		rdn[e[i].to]++;
		rd[rdn[e[i].to]] = i;
	}
	for (int i=1;i<=n;i++){
		ck = i;
		sch(i);
		now = 0;
		stop = 0;
	}
	int sstst=0x7fffffff;
	for (int i=1;i<=n;i++)
		sstst = min(sstst,sst[i]);
	printf("%d\n",sstst);
	return 0;
}
