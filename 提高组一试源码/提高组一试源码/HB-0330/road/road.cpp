#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

inline int read(){
	int x=(0),f=(1);char c=getchar(); 
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;	c=getchar();}
	while(c>='0'&&c<='9')	{x=x*10+c-'0';	c=getchar();}
	return x*f;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;n=read();
	long totaldays(0);
	int d[100001];d[0]=-1;
	int p(1),q(1),fpointer(1),bpointer(1);
	for(register int i=1;i<=n;++i)
		d[i]=read();
	int donenum(0),lastnotzero(1),flag(0);
	while(donenum!=n){
		donenum=0; 
		fpointer=1,bpointer=1;
		fpointer=1;
		while(d[fpointer]==0)	++fpointer;
		p=fpointer;
		for(register int i=1;i<=n;++i){
			if(d[i]==0){
				flag=1;
				++donenum;
				if(donenum==n)	break;
				q=lastnotzero;
				register int j;
				for(j=p;j<=q;j++)
					if(d[j]==0)	break;
				q=j-1;
				if(q-p>bpointer-fpointer)
					bpointer=q,fpointer=p; 
				continue;
			}
			else{
				lastnotzero=i;
				if(d[i-1]==0)	p=i;
			}
		}
		if(!flag)
			bpointer=n,fpointer=1;
		for(register int i=fpointer;i<=bpointer;i++)
			--d[i];
		++totaldays;
	}
	cout<<--totaldays;
	return 0;
}
