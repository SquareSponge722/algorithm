#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long a[100001],n;
freopen ("road.in","r",stdin);
freopen("road.ans","w",stdout);
	cin>>n;
	for (long long i=1;i<=n;i++)
	cin>>a[i];
fclose(stdin);
long long day=a[1];
for (long long i=1;i<=n;i++)
{
if (a[i]<a[i+1])
day=day+a[i+1]-a[i];
}
cout <<day;
fclose(stdout);
	return 0;
}
