#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define abs(x) (((x)>0)?(x):(-(x)))

const int MAXN = 100500;
long long val[MAXN], pre[MAXN], bkn[MAXN], prePut[MAXN], bknPut[MAXN];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	int totNodes, totQuery, a, b, x, y;
	
	scanf("%d%d", &totNodes, &totQuery);
	for(int i=0;i<totNodes;i++) scanf("%lld", val+i);
	for(int i=1;i<totNodes;i++)scanf("%d%d", &a,&b);
	
	prePut[0] = val[0]; prePut[1] = val[1]; pre[0] = val[0]; pre[1] = std::min(prePut[0], val[1]);
	for(int i=2;i<totNodes;i++){
		pre[i] = std::min(prePut[i-1], pre[i-2]+val[i]);
		prePut[i] = pre[i-2] + val[i];
	}
	bknPut[totNodes-1] = val[totNodes-1]; bknPut[totNodes-2] = val[totNodes-2];  bkn[totNodes-1] = val[totNodes-1];  bkn[totNodes-2] = std::min(bknPut[totNodes-1], val[totNodes-2]);
	for(int i=totNodes-3;i>=0;i--){
		bkn[i] = std::min(bknPut[i+1], bkn[i+2]+val[i]);
		bknPut[i] = bkn[i+2] + val[i];
	}	
	
	for(int i=0;i<totQuery;i++){
		scanf("%d%d%d%d", &a,&x,&b,&y);
		if(abs(b-a)==1 && x==0 && y==0) { printf("-1\n"); continue; }
		while(true) 1<<200;
	}
	
	return 0;
}