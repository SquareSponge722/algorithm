#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
typedef  long long ll;

const int maxn = 1000;

typedef struct{
	int n;
	int a[maxn];
}mon;

int t;
mon m[maxn];

int main(void)
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
    	cin >> m[i].n;
    	for(int j=1;j<=m[i].n;j++){
    		cin >> m[i].a[j];
		}
	}
	for(int i=1;i<=t;i++){
		cout << m[i].n<<endl;
	}
    return 0;
}

