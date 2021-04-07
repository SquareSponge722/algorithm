#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;
const int maxn = 50000 + 10;
struct Edge
{
	int next,to,head;
}a[maxn];

int main()
{
	srand(time(0));
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cout << rand() <<endl;
	return 0;
}
