#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define ri register int

using namespace std;

int n,m;
string type;
int c[15];
bool vis[15];

int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> type;
	int a,x,b,y;
	for(ri i = 1;i <= n;i ++)
		scanf("%d",&c[i]);
	for(ri i = 1;i < n;i ++)
		scanf("%d%d",&a,&b);
	while(m --){
		int ans = 0;
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if(abs(a-b) == 1 && x == 0 && y == 0){
			printf("-1\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		if(x == 1)
			ans += c[a];
		if(y == 1)
			ans += c[b];
		vis[a] = x;
		vis[b] = y;
		for(ri i = 1;i <= n;i ++){
			if(!vis[i] && !vis[i+1] && i+1 != a && i+1 != b){
				vis[i] = 1;
				vis[i+1] = 1;
				ans += c[i+1];
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
