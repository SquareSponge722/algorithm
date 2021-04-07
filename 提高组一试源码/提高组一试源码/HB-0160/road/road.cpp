#include<cstdio>
#include<cctype>
#include<iostream>
using namespace std;
int n,cnt;
long long ans;
int d[100005];
//bool vis[100005];
int read(){
	int re = 0,ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) re = (re<<1) + (re<<3) + ch - '0',ch = getchar();
	return re;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++){
		d[i] = read();
		if(d[i] > d[i - 1])
		ans += (long long)(d[i] - d[i - 1]);
		//if(d[i]) cnt++;
	}
	/*while(cnt){
		bool flag = 0;
		for(int i = 1;i <= n;i++){
			if(!flag && d[i]) flag = 1,ans++;
			if(!d[i]) flag = 0;
			else{
				d[i]--;
				if(!d[i]) cnt--;
			}
		}
	}*/
	cout << ans << endl;
	return 0;
}
