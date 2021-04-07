//
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std;
const int maxn=110;
int t,n;
int value[maxn];
set<int> s;
bool p;
int min_can(int a,int b)
{
	return a*b-a-b;
}
int mod(int a,int b)
{ 
	int m=max(a,b);
	int k=min(a,b);
	return m-((m/k)*k);
}
bool judge(int x,int y,int c)
{
	int maxnum,minnum;
	if(min_can(x,y)<c) return true;
	maxnum=max(x,y);
	minnum=min(x,y);
	for(int i=1;i*maxnum<=c;i++)
		if(mod(mod(i*maxnum,c),minnum)==0)
			return true;
	return false;
}
void work()
{
	scanf("%d",&t);
	while(t--){
		s.clear();
		p=0;
		memset(value,0,sizeof(value));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>value[i];
			s.insert(value[i]);
			if(value[i]==1) p=1;
		}
		if(p) {cout<<1<<endl;continue;}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(value[i]!=0&&value[j]!=0)
					if(mod(value[i],value[j])==0){
						int del=max(value[i],value[j]);
						s.erase(del);
						if(del==value[j]) value[j]=0;
						else value[i]=0;
					}
		if(s.size()>2){
			for(int i=1;i<n;i++)
				for(int j=1+i;j<=n;j++)
					if(value[i]!=0&&value[j]!=0)
						for(int k=1;k<=n;k++)
							if(k!=j&&k!=i&&value[i]<value[k]&&value[j]<value[k])
								if(judge(value[i],value[j],value[k])){
									s.erase(value[k]);
									value[k]=0;
								}
		}
		cout<<s.size()<<endl;
	}
	return;
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	work();
	return 0;
}
/*
noip2018rp++
*/
