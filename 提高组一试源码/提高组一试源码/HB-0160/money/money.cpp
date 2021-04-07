#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int read(){
	int re = 0,ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) re = (re<<1) + (re<<3) + ch - '0',ch = getchar();
	return re;
}
int n,w[105],t;
bool vis[105];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	t = read();
	while(t--){
		memset(vis,1,sizeof(vis));
		n = read();
		for(int i = 1;i <= n;i++)
			w[i] = read();
		sort(w + 1,w + n + 1);
		if(n == 2){
			if(!(w[2] % w[1]))printf("1\n");
			else printf("2\n");
		}
		if(n == 3){
			int ans = 0;
			if(!(w[2] % w[1])) vis[2] = 0;
			if(!(w[3] % w[1])) vis[3] = 0;
			if(!(w[3] % w[2])) vis[3] = 0;
			if(vis[2] && vis[3]){
				for(int i = 1;i * w[1] <= w[3];i++)
					for(int j = 1;j * w[2] <= w[3];j++)
						if(i * w[1] + j * w[2] == w[3]) 
							vis[3] = 0;
			}
			for(int i = 1; i <= 3;i++)
				if(vis[i]) ans++;
			printf("%d\n",ans);
 		}
	}
	return 0;
}
