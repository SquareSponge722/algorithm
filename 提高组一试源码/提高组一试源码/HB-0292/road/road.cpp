#include<cstdio>
#include<iostream>
char buff[100010],*PA(buff),*PB(buff);
#define gc PA==PB&&(PA=buff,PB=fread(buff,1,100000,stdin)+buff,PA==PB)?EOF:*PA++
using namespace std;
const int N=150000;
int getint(){
	char ch__=gc;
	int s__=0,f__=1;
	while(ch__<'0'||ch__>'9')
		f__=(ch__=='-')?-1:1,ch__=gc;
	while(ch__<='9'&&ch__>='0')
		s__=s__*10+ch__-48,ch__=gc;
	return s__*f__;
}
int n,ans,h[N],now;
int max(int x,int y){return x>y?x:y;}
void input(){
	n=getint();
	for(int i=1;i<=n;i++)
		h[i]=getint();
}
void work(){
	for(int i=1;i<=n;i++)
		ans+=max(h[i]-now,0),now=h[i];
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	input();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
