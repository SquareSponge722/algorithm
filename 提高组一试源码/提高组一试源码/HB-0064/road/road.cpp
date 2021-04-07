//First
#include<cstdio>
const int INF = 0x7fffffff;

int a[1234567];
int ans;
int N;

/*void  moni(int l, int r){
    if(l == r && a[l] == a[r] == 0) return;
    if(l == r && a[l] != 0){
	ans++;
	a[l]--;
	moni(l, r);
	return;
    }
    int last = l;
    printf("l:%d\tr:%d\n", l, r);
    for(int i = l ; i < r; i++){
	a[i] --;
	if(a[i] == 0){
	    moni(last, i);
	    last = i + 1;
	}
    }
    ans++;
}*/

/*void moni(int l, int r){
    if(l == r && a[l] > 0){
	a[l]--;
	//printf("#####:%d", a[l]);
	ans++;
	moni(l, r);
	//printf("F?");
	return;
    }
    if(l == r && a[l] == 0) return;
    //printf("l:%d\tr:%d\n", l, r);
    for(int i = l; i <= r; i++){
	a[i]--;
    }
    ans++;
    for(int i = l; i <= r; i++){
	if(a[i - 1] == 0 && a[i] != 0){
	    int last = i;
	    for(; a[i + 1] != 0 && i < r; i++);
	    //printf("%d->%d\n", last, i);
	    moni(last, i);
	}
    }
}*/

void moni2(int l, int r){
    //for(int i = 1; i < N; i++)printf("%d ", a[i]);
    //printf("%d->%d ans:%d\n", l, r, ans);
    if(l == r && a[l] > 0){
	ans += a[l];
	a[l] = 0;
	return;
    }
    if(l == r && a[l] == 0)return;
    int mn = INF;
    for(int i = l; i <= r; i++){
	if(a[i] < mn)mn = a[i];
    }
    //printf("mn:%dans:%d\n",mn,ans);
    ans += mn;
    for(int i = l; i <= r; i++){
	a[i] -= mn;
    }
    for(int i = l; i <= r; i++){
	if(a[i - 1] == 0 && a[i] != 0){
	    int last = i;
	    for(; a[i + 1] != 0 && i < r; i++);
	    //printf("Will%d->%d\n", last, i);
	    moni2(last, i);
	}
    }
}
	

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out", "w", stdout);
    scanf("%d", &N);
    ans = 0;
    for(int i = 1; i <= N; i++){
	scanf("%d", &a[i]);
    }
    a[0] = 0;
    a[N + 1] = 0;
    moni2(1, N);
    printf("%d\n", ans);
    return 0;
}
