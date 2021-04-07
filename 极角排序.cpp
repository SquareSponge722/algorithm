#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
struct point{
	long long x,y;
	point(){};
	point(long long X,long long Y){
		x = X,y = Y;
	}
	bool operator < (const point ot)const{
		return x * ot.y > y * ot.x;
	}
	point operator - (const point ot)const{
		return point(x - ot.x,y - ot.y); 
	}
	long long operator ^ (const point ot)const{
		return x * ot.y - y * ot.x;
	}
}poi[N],vec[N];
int n;
double ans = 0x3f3f3f3f;
int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%lld %lld",&poi[i].x,&poi[i].y);
	for(int i = 0;i < n;i++){
		int tot = 0;
		for(int j = 0;j < n;j++){
			if(i == j) continue;
			vec[tot++] = poi[j] - poi[i];
		}
		sort(vec,vec + tot);
		

		for(int i = 0;i < tot - 1;i++)
			ans = min(ans,(double)(vec[i] ^ vec[i + 1]) * 0.5);
	}
	printf("%.3lf\n",ans);
	return 0;
}
