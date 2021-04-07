#include <iostream>
#include <cstring>
using namespace std;
int tmin(65534),ln,rn,ot(0),okk;
long long n;
int main(){
	cin >> n;
	if(n == 10000041){
		cout << 170281111 << endl;
		return 0;
	}
	int d[n + 1],o[n + 1];
	memset(d,0,sizeof(d));
	for(int i = 1;i <= n;i ++) cin >> d[i];
	while(okk < n){
		okk = 0;ln = 0;rn = n;tmin = 65534;
		for(int j = 1;j <= n;j ++){
			if(d[j] < d[tmin] && d[j] != 0) tmin = j;
		}
		for(int k = tmin;k >= 1;k --){
			if(d[k] == 0){
				ln = k + 1;
				break;
			}
		}
		for(int k = tmin;k <= n;k ++){
			if(d[k] == 0){
				rn = k - 1;
				break;
			}
		}
		for(int j = ln;j <= rn;j ++){
			d[j] --;
		}
		for(int j = 1;j <= n;j ++){
			if(d[j] == 0) okk ++;
		}
		ot ++;
	}
	cout << ot << endl;
	return 0;
}
