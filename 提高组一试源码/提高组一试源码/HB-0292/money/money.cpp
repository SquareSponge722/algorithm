#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
char buff[100010],*PA(buff),*PB(buff);
#define gc PA==PB&&(PA=buff,PB=fread(buff,1,100000,stdin)+buff,PA==PB)?EOF:*PA++
using namespace std;
const int N=60001,INF=0x7fffffff;
int getint(){
	char ch__=gc;
	int s__=0,f__=1;
	while(ch__<'0'||ch__>'9')
		f__=(ch__=='-')?-1:1,ch__=gc;
	while(ch__<='9'&&ch__>='0')
		s__=s__*10+ch__-48,ch__=gc;
	return s__*f__;
}
int use[N],a[201];
int T,n;
void init(){
	memset(use,0,sizeof(use));
	use[0]=1;
}
void input(){
	n=getint();
	for(int i=1;i<=n;i++)
		a[i]=getint();
	sort(a+1,a+1+n);
}
void work(){
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!use[a[i]]&&(++ans))
			for(int j=0;j<=25010-a[i];j++)
				if(use[j])use[j+a[i]]=1;
	cout<<ans<<"\n";
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=getint();
	while(T--)init(),input(),work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
