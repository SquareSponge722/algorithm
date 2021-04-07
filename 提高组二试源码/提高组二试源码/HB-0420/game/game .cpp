#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,ganxielaoshi,xiexielaoshi;
	scanf("%d %d",&n,&m);
    ganxielaoshi=pow(m,n);
	xiexielaoshi=ganxielaoshi*3;
	printf("%d",xiexielaoshi);
	return 0;
}
