#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int m,n;
const int N=5001;
int d[N*N],h,t,x[N],r,s[N];
vector <int > g[N];
bool f[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		g[l].push_back(r);
		g[r].push_back(l);
	}
	r=n;
	d[t++]=1,x[++x[0]]=1,f[1]=true;
	while(h!=t && r){
		for(int i=0;i<g[d[h]].size();i++)
			d[t++]=g[d[h]][i];
		if(s[d[h]])
			d[t++]=s[d[h]];
		int min_loc,en=d[h];
		h++,r--;
		sort(d+h,d+t);
		for(min_loc=h;min_loc<t;min_loc++)
			if(!f[d[min_loc]])
				break;
			else
				h++;
		f[d[min_loc]]=true;
		x[++x[0]]=d[min_loc];
		s[d[min_loc]]=en;
	}
//	if(x[0]!=n)
//		printf("ERROR\n");
	for(int i=1;i<x[0];i++)
		printf("%d ",x[i]);
	return 0;
}
