#include<cstdio>
#include<algorithm>
using namespace std;
int a[1000];
int main(){
    freopen("money.in","r",stdin);
    freopen("money.out", "w", stdout);
    int c, b, t;
    scanf("%d", &c);
    for(int k = 0; k < c; k++){
	scanf("%d", &b);
	for(int i = 0; i < b; i++)scanf("%d", &a[i]);
	for(int i = 0; i < b - 1; i++)for(int j = i + 1; i < b; i++)if(a[j] %a[i] ==0)a[j] = -1;
	int ans = 0;
	for(int i = 0; i < b; i++)if(a[i] == -1)ans ++;
	if(b == 2){
	    int s = max(a[0], a[1]);
	    int n = min(a[0], a[1]);
	    int t = s - n;
	    if(t == n) printf("1\n");
	    else printf("2\n");
	    continue;
	}
	printf("%d\n", b - ans);
    }
    return 0;
}
