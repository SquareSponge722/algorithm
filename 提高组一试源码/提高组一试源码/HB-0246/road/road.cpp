#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
long long a[100010],b[100010];//a是本来长度，b是求最小
long long n,ans;
long long x;
void meg(long long left,long long right) {
	while((!a[left])&&(left<=right-1)) left++;
	while((!a[right])&&(left<=right-1)) right--;
	if(left==right) {
		ans+=a[left];
		return ;
	}
	for(long long i=left; i<=right; i++) b[i]=a[i];
	sort(b+left,b+right+1);
	ans+=b[left];
	for(long long i=left; i<=right; i++) a[i]-=b[left];
	for(long long i=left; i<=right+1; i++)
		if(!a[i]) {
			meg(x,i);
			x=i;
		}
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) cin>>a[i];
	meg(1,n);
	cout<<ans;
	return 0;
}
