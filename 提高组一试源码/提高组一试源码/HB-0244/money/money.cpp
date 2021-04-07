#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#define gc pa==pb&&(pb=(pa=buff)+fread(buff,1,100000,read),pa==pb)?EOF:*pa++
#define R register
#define FOR(i,a,b) for(R int i=a;i<=b;++i)
#define ROF(i,a,b) for(R int i=a;i>=b;--i)
#define vd void
#define long long ll
using namespace std;

FILE *read;
static char buff[100000],*pa,*pb;
int n;
int a[100020];
int ans;
int b[250020];
	
int in() {
	R int num(0);
	R char w(gc);
	while(!(w>='0'&&w<='9')) w=gc;
	while(w>='0'&&w<='9') {
		num=num*10+(w^48);
		w=gc;
	}
	return num;
}

ofstream fout;

void out() {
	cout<<ans<<endl;
}

void clear()
{
	for(int i=1;i<=a[n];++i) b[i]=0;
	ans=0;
	
}

namespace N2 {
	void work() {
		if(a[2]%a[1]==0) ans=1;
		else ans=2;
	}
}

namespace N3 {
	void work() {
		if(a[2]%a[1]==0) {
			if(a[3]%a[1]==0) ans=1;
			else ans=2;
		} else {
			int i=0;
			int j=0;
			ans=3;
			for(i=1; a[i]*i+a[j]*j<=a[3]; ++i) {
				for(j=1; a[i]*i+a[j]*j<=a[3]; ++j) {
					if(a[i]*i+a[j]*j==a[3]) {
						ans=2;
						goto S1;
					}
				}
				j=0;
			}
S1:
			return ;

		}
	}
}

namespace N{

	void work()
	{
		for(int i=1;i<=n;++i)
		{
			if(!b[a[i]])
			{
			ans++;
			b[a[i]]=a[i];
			for(int j=1;j+a[i]<=a[n];++j)
			{
				if(b[j]) b[j+a[i]]=j+a[i];
			}	
			}
		}
	}
}


void work() {
	if(n==2) N2::work();
	if(n==3) N3::work();
	else N::work();
//	out();
}

void scan() {
	read=fopen("money.in","r");
	int t;
	t=in();
	while(t--) {
		clear();
		n=in();
		FOR(i,1,n) a[i]=in();
		sort(a+1,a+1+n);
		work();
		out();
//		fclose(read);
	}
}



int main() {
	freopen("money.out","w",stdout);
	scan();
	return 0;
}
