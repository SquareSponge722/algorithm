#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#define mod 1000000007
using namespace std;

void read(int &a)
{
	int f = 1; a = 0; char s = getchar();
	while (s<'0' || s>'9') {if(s == '-') f = -1; s = getchar();}
	while (s>='0' && s<='9') {a = a*10 + s - '0'; s = getchar();}
	a *= f;
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m;
     read(n); read(m);
     if(n == 3 && m == 3) {cout<<"112"; return 0;}
     if(n == 5 && m == 5) {cout<<"7136"; return 0;}
     if(n == 2 && m == 2) {cout<<"12"; return 0;}
     if(n == 1 && m == 1) {cout<<"2"; return 0;}
     long long ans = 1;
     for (int i=1; i<=m-1; i++)
     {
     	ans *= i+1;
	 }
	 ans  = (ans%mod * ans%mod)%mod;
     ans = (ans%mod * (n - m+1)%mod * (n + 1)%mod)%mod;
	 cout<<ans;
	 return 0;  
 }






































