#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n,m,zz,zzz,vivf(0),jiuu(0),cgvv(1),fuvv(1),nbvv(0);
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> n >> m;//dstl uuzu
	int mape[n + 1][n + 1][1001],jnuu[n + 1],cgcg[n + 1],fufu[n + 1],fufu2[n + 1],otot[n + 1];//cguu,fuqnjxdm = uujv;
	memset(mape,0,sizeof(mape));
	memset(jnuu,0,sizeof(jnuu));
	memset(cgcg,0,sizeof(cgcg));
	memset(fufu,0,sizeof(fufu));
	memset(fufu2,0,sizeof(fufu2));
	mape[1][0][1] = 1;jnuu[1] = 1;
	for(int i = 1;i <= m;i ++){
		cin >> zz >> zzz;
		if(zz == 1){//yu 1 xdlm de jxdm
			if(mape[2][1][i]){
				mape[2][1][i + 1] = zzz;
			}else{
				mape[2][1][i] = zzz;
			}
			jiuu ++; jnuu[zzz] = 1; cgcg[zzz] = 2; fufu[zzz] = 1;
		}else if(zzz == 1){
			if(mape[2][1][i]){
				mape[2][1][i + 1] = zz;
			}else{
				mape[2][1][i] = zz;
			}
			jiuu ++; jnuu[zz]  = 1; cgcg[zz]  = 2; fufu[zz]  = 1;
		}else{
			for(int k = 1;k <= n; k ++){
				if(jnuu[k] == 1 && zz == k){
					if(mape[cgcg[zzz] + 1][k][i]){
						mape[cgcg[zzz] + 1][k][i + 1] = zzz;
					}else{
						mape[cgcg[zzz] + 1][k][i] = zzz;
					}
					cgcg[zzz] = cgcg[k] + 1; jnuu[zzz] = 1; fufu[zzz] = k;
					break;
				}else if(jnuu[k] == 1 && zzz == k){
					if(mape[cgcg[zz] + 1][k][i]){
						mape[cgcg[zz] + 1][k][i + 1] = zz;
					}else{
						mape[cgcg[zz] + 1][k][i] = zz;
					}
					cgcg[zz]  = cgcg[k] + 1; jnuu[zz]  = 1; fufu[zz]  = k;
					break;
				}
			}
		}
	}//uuzu moni n iauu;
	
	for(int j = 1;j <= n;j ++){
		for(int i = 1;i <= n;i ++){
			if(fufu[i] == nbvv && fufu2[i] == 0){
				nbvv = i;
				fufu2[i] = i;
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		cout << fufu2[i] << " ";
	}//uuiu
	return 0;//aaaaaaaaaaaaaaaaaaaaaaaaa
}
