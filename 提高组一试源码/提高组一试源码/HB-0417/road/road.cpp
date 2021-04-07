#include<bits/stdc++.h>
struct node {
	long long ld,rd,to,hi;
	node() {
		ld=rd=to=hi=0;
	}
};
using namespace std;
const long long MAXN=100010;
inline char nc() {
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
long long read() {
	long long x=0;
	char c=nc();
	while(!isdigit(c))c=nc();
	while(isdigit(c))x=x*10+c-48,c=nc();
	return x;
}
long long head,ans;
node f[MAXN];
long long a[MAXN],cnt;
bool up,down;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n=read();
	up=true;
	for(long long i=1; i<=n; i++) {
		a[i]=read();
		if(a[i]<a[i-1]) {
			down=true;
			if(up) {
				f[++cnt].hi=a[i-1];
				f[cnt].to=head;
				f[cnt].ld=f[head].rd;
				head=cnt;
				up=false;
			}
		} else if(a[i]>a[i-1]) {
			up=true;
			if(down)f[cnt].rd=a[i-1];
		} else i--,n--;
	}
	if(!head) {
		puts("1");
		return 0;
	}
	if(f[cnt].rd) {
		f[++cnt].hi=a[n];
		f[cnt].to=head;
		f[cnt].ld=f[head].rd;
		head=cnt;
	}
	for(long long i=head; i; i=f[i].to) {
		if(f[i].ld>f[i].rd) {
			ans+=f[i].hi-f[i].ld;
			f[f[i].to].rd=f[i].rd;
		} else ans+=f[i].hi-f[i].rd;
	}
	cout<<ans;
	return 0;
}
