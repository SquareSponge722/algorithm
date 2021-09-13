#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <complex>
#include <ctime>

using namespace std;

typedef complex<double> Complex;
const int N = 50100;
const double PI = acos(-1.0);

char numa[N],numb[N];
Complex fa[N * 4],fb[N * 4],fc[N * 4];
int rev[N * 4],ans[N * 4];

void change(Complex f[],int len);
void FFT(Complex f[],int n,int inv);

int main(){
    while(~scanf("%s%s",numa,numb)){
        int bitl = 1;
        int lena = strlen(numa),lenb = strlen(numb);
        while(bitl < (lena << 1) || bitl < (lenb << 1)) bitl <<= 1;

        for(int i = 0;i < bitl;i++){
            if(i < lena) fa[i] = Complex(numa[lena - i - 1] - '0',0);
            else fa[i] = Complex(0,0);
            if(i < lenb) fb[i] = Complex(numb[lenb - i - 1] - '0',0);
            else fb[i] = Complex(0,0);
        }
        FFT(fa,bitl,1);
        FFT(fb,bitl,1);
        for(int i = 0;i < bitl;i++) fc[i] = fa[i] * fb[i];
        FFT(fc,bitl,-1);

        for(int i = 0;i < bitl;i++){
            ans[i] = int(fc[i].real() + 0.5);
            if(i != 0){
                ans[i] += ans[i - 1] / 10;
                ans[i - 1] %= 10;
            }
        }
        bool isPrint = false;
        for(int i = bitl - 1;i >= 0;i--){
            if(ans[i]){
                printf("%d",ans[i]);
                isPrint = true;
            }else if(isPrint || i == 0){
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}

void change(Complex f[],int len){
    for(int i = 0;i < len;i++){
        rev[i] = rev[i >> 1] >> 1;
        if(i & 1) rev[i] |= (len >> 1);
    }
    for(int i = 0;i < len;i++){
        if(i < rev[i]) swap(f[i],f[rev[i]]);
    }
}
void FFT(Complex f[],int n,int inv){
    change(f,n); //模拟递归后的数组
    for(int st = 2;st <= n;st <<= 1){ //模拟递归的数组区间大小
        Complex wn(cos(2 * PI / st),sin(inv * 2 * PI / st)); //当前单位复根
        for(int h = 0;h < n;h += st){
            Complex w(1,0);
            for(int k = h;k < h + st / 2;k++){
                Complex x = f[k],y = w * f[k + st / 2];
                f[k] = x + y;
                f[k + st / 2] = x - y;
                w *= wn;
            }
        }
    }
    if(inv == -1){ //IDFT
        for(int i = 0;i < n;i++) f[i] /= n;
    }
}

//FFT的解决的是如何快速地在多项式的系数表示与点值表示之间转换的问题
//其核心思想是分治法，通过取特殊点值（一对相反数且上一对相反数与下一对相反数的平方依然互为相反数）与递归解决子问题来加速

//hdu1402

//2021-9-10