#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100100],temp,ans;

inline int read ()
{
	int s=0;
	char ch=getchar ();
	while (ch<'0'||ch>'9') ch=getchar ();
	while (ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar ();}
	return s;
}

int main ()
{
	int t,l,r,s,nmin;
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) 
		a[i]=read ();
	for (int i=1;i<=n;i++) {
		if (a[i]) {
			l=i;nmin=99999999;temp=0;s=0;
			for (int j=l;j<=n;j++) {
				if (!a[j]) break;
				if (nmin>a[j]) nmin=a[j];
				r=j;
			}
			for (int j=l+1;j<=r;j++) {
				if (a[j]<a[j-1]) {
					s=j-1;temp++;break;
				}
			}
			if (s==0) {
				ans+=a[r];
				for (int j=l;j<=r;j++) a[j]=0;
			}
			else {
				for (int j=s;j<=r;j++) {
					if (a[j]<a[j-1]) {
						s=j;temp++;break;
					}
				}
				if (temp==1) {
					ans+=a[s];
					for (int j=1;j<=r;j++) a[j]=0;
				}
				else {
					ans+=nmin;
				for (int j=l;j<=r;j++) a[j]-=nmin;
				if (a[l]) i--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
