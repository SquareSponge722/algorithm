#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

int t, a[110], if_prime[26000], prime[26000], tot;
bool book[110], fff[26000];

void read(int &x)
{
	int h = 1; x = 0; char s = getchar();
	while (s<'0' || s>'9') {if(s == '-') h = -1; s = getchar();}
	while (s>='0' && s<='9') {x = x*10 + s - '0'; s = getchar();}
	x *= h; return; 
}

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

void init()
{
	if_prime[1] = 1;
	for (int i=2; i<=25000; i++)
	{
		if(if_prime[i] == 0) prime[++tot] = i;
		for (int j=1; j<=tot && i*prime[j] <= 25000; j++)
		{
			if_prime[i*prime[j]] = 1;
			if(i%prime[j] == 0) continue;
 		} 
	}
}

bool cmp(int a, int b) {return a < b; }

int main()
{
	//ios::sync_with_stdio(0);
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    read(t);
    //init();
    for (int tt=1; tt<=t; tt++)
    {
    	int n; read(n); int ans = n;
    	memset(book, 0, sizeof(book));
    	memset(a, 0, sizeof(a));
    	bool ff = 0;
    	for (int i=1; i<=n; i++)
    	{
    		read(a[i]);
    		fff[a[i]] = 1;
    //		if(if_prime[a[i]] == 1) ff = 1;
		}
	//	if(ff == 0) {printf("%d", n); continue;}
		for (int i=1; i<=n; i++)
		    for (int j=1; j<i; j++)
		    {
		    	int k = gcd(max(a[i], a[j]), min(a[i], a[j]));
		    	if(k == min(a[i], a[j])) {
		    		fff[max(a[i], a[j])] = 0;
		    		if(book[max(a[i], a[j])] == 0) ans --;
		    		book[max(a[i], a[j])] = 1;
				}
			}
		sort(a+1, a+n+1, cmp);
		int k = (a[n] / a[1]) + 1;
		for (int i=1; i<=n; i++)
		{
			if(book[a[i]] == 0)
			{
				for (int j=i; j<=n; j++)
				{
					if(book[a[j]] == 0)
					{
						for(int aa=1; aa<=k; aa++)
						    for (int bb=1; bb<=k; bb++)
						    {
						    	book[aa*a[i] + bb*a[j]] == 1;
						    	if(fff[aa*a[i] + bb*a[j]] == 1) ans --; 
						    	fff[aa*a[i] + bb*a[j]] = 0;
						    	if(k <= 50)
						        {
							        for (int c=j; c<=n; c++)
						            {
							            if(book[a[c]] == 0)
							            for (int cc=1; cc<=k; cc++)
							            {
							            	book[aa*a[i] + bb*a[j] + cc*a[c]] == 1;
						    	            if(fff[aa*a[i] + bb*a[j] + cc*a[c]] == 1) ans --; 
						    	            fff[aa*a[i] + bb*a[j] + cc*a[c]] = 0;
										}
							        }
						        } 
							}
					    
						
					}
				}
			} 
		} 
		printf("%d\n", ans);
	}
    return 0;
}




































