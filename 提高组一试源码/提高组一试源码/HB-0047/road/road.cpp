#include<bits/stdc++.h>
using namespace std;
long long n,d[100001],ans;
void make(int lef,int rig)
{
	int flag=1,flagg=1;
	for(int i=lef;i<=rig-1;i++) 
	{
		if(d[i+1]!=d[i]+1) flag=0;
		if(d[i+1]!=d[i]-1) flagg=0;
		if(flag+flagg==0) break;
	}
	if(flag) {ans+=d[rig];return ;}
	if(flagg) {ans+=d[lef];return ;}
	int p=0,minn=9999999,ss=0;
	if(lef==rig) {ans+=d[lef];return ;}
	for(int i=lef;i<=rig;i++)
		if(d[i]<minn) 
		{minn=d[i];p=i;}
	ans+=minn;
	for(int i=lef;i<=rig;i++)
	{
		if(d[i]==minn) ss++;
		d[i]-=minn;
	}
	int bb[ss+1];ss=0;
	for(int i=lef;i<=rig;i++)
		if(d[i]==0)
		{ss++;bb[ss]=i;}
	if(ss==1)
	{
		if(p>lef&&p<rig) {make(lef,p-1);make(p+1,rig);}
		if(p==lef) make(lef+1,rig);
		if(p==rig) make(lef,rig-1);
	}
	if(ss!=1)
	{
		if(bb[1]!=lef) make(lef,bb[1]-1);
		if(bb[ss]!=rig) make(bb[ss]+1,rig);
		for(int i=1;i<=ss-1;i++)
		{
			if(bb[i]+1==bb[i+1]) continue;
			make(bb[i]+1,bb[i+1]-1);
		
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>d[i];
	make(1,n);
	cout<<ans;
	return 0;
}
