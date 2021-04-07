#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

inline int read(){
	int summ = 0;
	char e = getchar();
	while(!isdigit(e))
		e = getchar();
	while(isdigit(e)){
		summ = summ * 10 + e - '0';
		e = getchar();
	}
	return summ;
}

int n;
int a[105];
bool vis[25005];
int minn,maxx;

bool check(int x){
	if(vis[x])
		return true;
	for(ri i = minn;i <= maxx;++ i){
		if(!vis[i])
			continue;
		else{
			for(ri j = 1;j*i <= x;++ j)
				if(check(x - j*i))
					return true;
		}
	}
	return false;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T = read();
	while(T --){
		memset(vis,0,sizeof(vis));
		n = read();
		int m = 0;
		for(ri i = 1;i <= n;++ i)
			a[i] = read();
		sort(a+1,a+1+n);
		minn = a[1],maxx = a[n];
		for(ri i = 1;i <= n;++ i){
			int t = a[i];
			if(!vis[t]){
				if(!check(t))
					++ m;
				for(ri j = t;j <= maxx;j += t)
					vis[j] = 1;
			}
		}
		printf("%d\n",m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
