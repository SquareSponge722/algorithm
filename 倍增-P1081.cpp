#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
const int M = 25;
const int K = 16;
const int INF = 0x7f7f7f7f;

struct city
{
	int abh,height;
	bool operator < (const city & ot)const{
		if(abh == ot.abh) return height < ot.height;
		return abh < ot.abh;
	}
}cit[8];


int n,m,t;
int h[N];
int adis[N][M],bdis[N][M],a[N],b[N];
int fa[N],fb[N],f[N][M];

set <int> s;
map <int,int> mapp;

double fin1(int,int);

int main(){

	s.insert(INF),s.insert(INF - 1);
	s.insert(-INF),s.insert(-INF + 1);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&h[i]);
		mapp[h[i]] = i;
	}

	for(int i = n;i > 0;i--){
		s.insert(h[i]);

		cit[1].height = *--s.lower_bound(h[i]);
		cit[2].height = *--s.lower_bound(cit[1].height);
		cit[3].height = *s.upper_bound(h[i]);
		cit[4].height = *s.upper_bound(cit[3].height);
		for(int j = 1;j <= 4;j++) cit[j].abh = abs(h[i] - cit[j].height);
		sort(cit + 1,cit + 5);

		a[i] = cit[2].abh;
		b[i] = cit[1].abh;
		fa[i] = mapp[cit[2].height];
		fb[i] = mapp[cit[1].height];

		if(fa[i]){
			adis[i][0] = a[i];
			f[i][0] = fa[i];
		}
		if(fb[fa[i]]){
			bdis[i][1] = b[fa[i]];
			adis[i][1] = a[i];
			f[i][1] = fb[fa[i]];
		}

		for(int j = 2;j <= K;j++)
			if(f[f[i][j - 1]][j - 1]){
				f[i][j] = f[f[i][j - 1]][j - 1];
				adis[i][j] = adis[i][j - 1] + adis[f[i][j - 1]][j - 1];
				bdis[i][j] = bdis[i][j - 1] + bdis[f[i][j - 1]][j - 1];
			}else break;
	}

	double ans = INF;
	int ansp = 0;
	scanf("%d",&t);
	for(int i = 1;i <= n;i++){
		double tmp = fin1(i,t);
		if(tmp < ans){
			ans = tmp;
			ansp = i;
		}
	}
	printf("%d\n",ansp);

	scanf("%d",&t);
	while(t--){
		int s,x;
		scanf("%d %d",&s,&x);

		int asum = 0,bsum = 0;
		for(int i = K;i >= 0;i--){
			if(f[s][i] && asum + bsum + adis[s][i] + bdis[s][i] <= x){
				asum += adis[s][i];
				bsum += bdis[s][i];
				s = f[s][i];
			}
		}

		printf("%d %d\n",asum,bsum);
	}

	return 0;
}
double fin1(int k,int lim){
	int asum = 0,bsum = 0;
	for(int i = K;i >= 0;i--){
		if(f[k][i] && asum + bsum + adis[k][i] + bdis[k][i] <= lim){
			asum += adis[k][i];
			bsum += bdis[k][i];
			k = f[k][i];
		}
	}
	if(bsum) return (double) asum / bsum;
	return INF;
}
