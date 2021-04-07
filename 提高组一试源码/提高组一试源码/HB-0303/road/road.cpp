#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>

const int MAXN = 100000+200;
int dep[MAXN];

int Solve(const int &fr,const int &to,const int &fixed){
	if(fr>to)return 0;
	if(fr==to) return dep[fr]-fixed;
	
	int min = INT_MAX, pos;
	for(int i=fr;i<=to;i++)
		if(dep[i]<min){
			min = dep[i]; pos = i;
		}
	min-=fixed;
		
	return Solve(fr,pos-1,fixed+min)+Solve(pos+1,to,fixed+min)+min;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int len;
	
	scanf("%d",&len);
	for(int i=0;i<len;i++)scanf("%d",dep+i);
	
	printf("%d\n",(Solve(0,len-1,0)));
	
	return 0;
}