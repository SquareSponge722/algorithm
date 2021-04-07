//
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=100010;
int n;
int deep[maxn];
int lef,righ;
long long ans;
void read()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&deep[i]);
	return;
}
void find_max()
{
	int pos=1,lenth=0,len=0;
	for(int i=1;i<=n+1;i++){
		if(deep[i]==0){
			if(lenth<len){
				lenth=len;
				pos=i-1;
				len=0;
			}
			else len=0;
		}
		else len++;
	}
	righ=pos;
	lef=pos-lenth+1;
	return;
}
void work()
{
	read();
	int t=0;
	while(*max_element(deep+1,deep+n+1)){
		t++;
		find_max();
		int dep=0x3f3f3f3f;
		for(int i=lef;i<=righ;i++)
				dep=min(dep,deep[i]);
		ans+=dep;
		for(int i=lef;i<=righ;i++)
			deep[i]-=dep;
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	work();
	return 0;
}
/*
6
4 3 2 5 3 5
noip2018rp++
*/
