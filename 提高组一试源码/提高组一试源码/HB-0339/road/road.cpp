#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <stack>
#define N 101000
using namespace std;

int a[N], n, f[N][21], m[N][21];
long long day;

void read(int &x)
{
	int h = 1; x = 0; char s = getchar();
	while (s<'0' || s>'9') {if(s == '-') h = -1; s = getchar();}
	while (s>='0' && s<='9') {x = x*10 + s - '0'; s = getchar();}
	x *= h; return; 
}

int askmax(int x, int y)
{
	int k = log2(y - x + 1);
 	if(a[f[x][k]] >= a[f[y-(1<<k)+1][k]]) return f[x][k];
	else return f[y-(1<<k)+1][k];
}

int askmin(int x, int y)
{
	int k = log2(y - x + 1);
	if(a[m[x][k]] <= a[m[y-(1<<k)+1][k]]) return m[x][k];
	else return m[y-(1<<k)+1][k];
	
	//return max(f[x][k], f[y-(1<<k)+1]);
}

void dfs(int x, int y, int pasadd)
{
	if(x == y) {day += (a[x] - pasadd); return;}
	int maxi = askmax(x, y);
	int mini = askmin(x, y);
    if(a[maxi] - pasadd == 0) return;
	day += a[mini] - pasadd; 
	if(mini > x) dfs(x, mini-1, a[mini]);
	if(mini < y) dfs(mini+1, y, a[mini]);
	
}

int main()
{
	//ios::sync_with_stdio(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    read(n);
    for (int i=1; i<=n; i++)
	{
		read(a[i]);
		f[i][0] = i;
		m[i][0] = i;
	} 
	for (int j=1; j<20; j++)
	    for (int i=1; i+(1<<j-1)<=n; i++)
	    {
	    	if(a[f[i][j-1]] >= a[f[i+(1<<j-1)][j-1]]) f[i][j] = f[i][j-1];
	    	else f[i][j] = f[i+(1<<j-1)][j-1];
	    	//f[i][j] = max(a[f[i][j-1]], a[f[i+(1<<j-1)][j-1]]);
	    	if(a[m[i][j-1]] <= a[m[i+(1<<j-1)][j-1]]) m[i][j] = m[i][j-1];
	    	else m[i][j] = m[i+(1<<j-1)][j-1];
	    	//cout<<m[i][j]<<endl;
		}
    dfs(1, n, 0);
	printf("%lld", day);
    return 0;
}




































