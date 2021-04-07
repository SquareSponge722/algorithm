#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T,n[T],a[n[T]][T],m1,m2;
	scanf("%d",&T);
	for(m2=0;m2<T;m2++){
		scanf("%d",n[m2]);
		for(m1=0;m1<T;m1++)
		  scanf("%d",a[m1][m2]);
	}
	
	return 0;
}
