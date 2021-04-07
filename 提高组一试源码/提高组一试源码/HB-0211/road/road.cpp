#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int x[100001]={0};
void ssq(int minxx,int wz)
{
	wz++;
	if(x[wz]==0) return;
	else{
		x[wz]=x[wz]-minxx;
		ssq(minxx,wz);
	}
}
void ssh(int minxx,int wz)
{
	wz--;
	if(x[wz]==0) return;
	else{
		x[wz]=x[wz]-minxx;
		ssh(minxx,wz);
	}
}
int main()
{
	int t=0;
	int n,i,minxx=10001,jc=0;
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	
	while(1)
	{
		
		for(i=1;i<=n;i++)
		{
			if(x[i]==0) continue;
			if(minxx>x[i]) minxx=x[i];
		}
		t=t+minxx;
		//printf("%d %d",minxx,t);
		for(i=1;i<=n;i++)
		{
			//printf(" %d %d",minxx,t);
			
			if(x[i]==minxx)
			{
				//printf(" %d %d",minxx,t);
				x[i]=0;
				ssq(minxx,i);
				ssh(minxx,i);
				minxx=10001;
				break;
			}
			
		}
		//for(i=1;i<=n;i++)
		//{
		//	printf("%d",x[i]);
		//}
		for(i=1;i<=n;i++)
		{
			if(jc<x[i]) jc=x[i];
		}
		if(jc==0) break;
		else jc=0;
	}
	printf("%d",t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
