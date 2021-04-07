#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define register R
using namespace std;

inline void read(int &x) {
	int w = 1;
	x = 0;
	char c = getchar();

	while(!isdigit(c)) {
		if(c == '-') w = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = x*10 + c - '0';
		c = getchar();
	}
	x *= w;
}
int ans = 0;
int n;
int d[100005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	//scanf("%d",&n);
	for(R int i=1; i<=n; i++)
		read(d[i]);

	d[n+1] = 0;

	int flag = 1;

	while(flag) {
		int minn = 0x3f3f3f3f;
		int l = 1;
		int r = 0;
		int num = 0;
		for(R int i=1; i<=n+1; i++) {
			if(d[i] == 0) {
				minn = 0x3f3f3f3f;
				r = i-1;
				
				if(r < l) 
				{
					l = i+1;
					continue;
				}
				
				if(l == r) {
					ans += d[l];
					d[l] = 0;
					l = i+1;
					continue;
				}

				for(R int j=l; j<=r; j++) 
					minn = min(d[j],minn);
					
				if(minn == 0x3f3f3f3f) continue;
				
				for(R int j=l; j<=r; j++)
					d[j] -= minn;
				
				ans+=minn;
				l = i+1;
			} 
		}
		for(R int i=1;i<=n;i++) if(d[i] == 0) num++;
		if(num == n) flag = 0;
	}
	printf("%d",ans);
	return 0;
}
