#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define INF 1000000
using namespace std;
const int maxn = 5000;

int vis[maxn];
int minn=INF;
int n,m;
int markv;
int marku;
int minv;
int minu;
int sqen[maxn];
int u[maxn];
int v[maxn];

typedef struct{
	int u;
	int v;
	int mark;
}Edge;

Edge edge[maxn];

int main(void)
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin >> n >>m;
    minv=INF;
    minu=INF;
    for(int i=1;i<=n;i++){
        cin >> edge[i].u >> edge[i].v;
		if(minu>edge[i].u) {
			minu=edge[i].u;
			marku=i;		
		} 
		if(minv>edge[i].v){
			minv=edge[i].v;
			markv=i;
		}
    }
    int cnt=0;
    for(int i=1;i<=n;i++){cout << i;}
    return 0;
}
