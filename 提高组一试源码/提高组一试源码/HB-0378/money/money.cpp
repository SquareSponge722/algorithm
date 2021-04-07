#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int T, n, t1, t2, t3, t4, res, cash[6];

void work(){
	scanf("%d", &T);
	while (T --){
		bool flag; res = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &cash[i]);
		sort(cash + 1, cash + n + 1);
		if (n == 1) { printf("1\n"); continue ; }
		if (cash[2] % cash[1]) ++res;
		if (n >= 3){
			flag = 0;
			if (cash[3] % cash[1] and cash[3] % cash[2]){
				t1 = cash[3] / cash[1], t2 = cash[3] / cash[2];
				for (int i = 0; i <= t1; ++i){
					for (int j = 0; j <= t2; ++j)
						if (i * cash[1] + j * cash[2] == cash[3])
							{ flag = 1; break ; }
					if (flag) break ;
				}
				if (!flag) ++res;
			}
		}
		if (n >= 4){
			flag = 0;
			if (cash[4] % cash[1] and cash[4] % cash[2] and cash[4] % cash[3]){
				t1 = cash[4] / cash[1], t2 = cash[4] / cash[2], t3 = cash[4] / cash[3];
				for (int i = 0; i <= t1; ++i){
					for (int j = 0; j <= t2; ++j){
						for (int k = 0; k <= t3; ++k)
							if (i * cash[1] + j * cash[2] + k * cash[3] == cash[4])
								{ flag = 1; break ; }
						if (flag) break ;
					}
					if (flag) break ;
				}
				if (!flag) ++res;
			}
		}
		if (n >= 5){
			flag = 0;
			if (cash[5] % cash[1] and cash[5] % cash[2] and cash[5] % cash[3] and cash[5] % cash[4]){
				t1 = cash[5] / cash[1], t2 = cash[5] / cash[2], t3 = cash[5] / cash[3], t4 = cash[5] / cash[4];
				for (int i = 0; i <= t1; ++i){
					for (int j = 0; j <= t2; ++j){
						for (int k = 0; k <= t3; ++k){
							for (int l = 0; l <= t4; ++l)
								if (i * cash[1] + j * cash[2] + k * cash[3] + l * cash[4] == cash[5])
									{ flag = 1; break ; }
							if (flag) break ;
						}
						if (flag) break ;
					}
					if (flag) break ;
				}
				if (!flag) ++res;
			}
		}
		printf("%d\n", res);
	}
}

int main(){
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	work(); 
	return 0;
}
