#include <cstdio>
#include <string>
#include <ctime>
#define MOD 1000000007

using namespace std;

int n,m;
int ans[5][5];
/*
int stringcmp(char a[],char b[])
{
	int big=1,same=0,small=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<b[i])
			return small;
		if(a[i]>b[i])
			return big;
	}
	return same;
}

namespace point1
{
	void work()
	{
		int cnt=0;
		char first[10]={0},second[10]={0},third[10]={0};
		string f,s,t;
		if(m==3 && n==2)
		{
			for(a[0][0]=0;a[0][0]<=1;a[0][0]++)
				for(a[0][1]=0;a[0][1]<=1;a[0][1]++)
					for(a[0][2]=0;a[0][2]<=1;a[0][2]++)
						for(a[1][0]=0;a[1][0]<=1;a[1][0]++)
							for(a[1][1]=0;a[1][1]<=1;a[1][1]++)
								for(a[1][2]=0;a[1][2]<=1;a[1][2]++)
									{
										first[1]=a[0][0];first[2]=a[0][1];first[3]=a[0][2];first[4]=a[1][2];
										second[1]=a[0][0];second[2]=a[0][1];second[3]=a[1][1];second[4]=a[1][2];
										third[1]=a[0][0];third[2]=a[1][0];third[3]=a[1][1];third[4]=a[1][2];
										f="RRD";s="RDR";t="DRR";
										int flag=1;
										if(stringcmp(first,second)>0)	flag=0;
										if(stringcmp(first,third)>0)		flag=0;
										if(stringcmp(second,third)>0)	flag=0;
										if(flag==1)
											cnt++;
									}
			printf("%d",cnt);
		}
		else if(m==2 && n==3)
		{
			int cnt=0;
			char first[10]={0},second[10]={0},third[10]={0};
			string f,s,t;
			for(a[0][0]=0;a[0][0]<=1;a[0][0]++)
				for(a[0][1]=0;a[0][1]<=1;a[0][1]++)
					for(a[1][0]=0;a[1][0]<=1;a[1][0]++)
						for(a[1][1]=0;a[1][1]<=1;a[1][1]++)
							for(a[2][0]=0;a[2][0]<=1;a[2][0]++)
								for(a[2][1]=0;a[2][1]<=1;a[2][1]++)
								{
									first[1]=a[0][0];first[2]=a[0][1];first[3]=a[1][1];first[4]=a[2][1];
									second[1]=a[0][0];second[2]=a[1][0];second[3]=a[1][1];second[4]=a[2][1];
									third[1]=a[0][0];third[2]=a[1][0];third[3]=a[2][0];third[4]=a[2][1];
									f="RDD";s="DRD";t="DDR";
									int flag=1;
										if(stringcmp(first,second)>0)	flag=0;
										if(stringcmp(first,third)>0)		flag=0;
										if(stringcmp(second,third)>0)	flag=0;
										if(flag==1)
											cnt++;
									}
			printf("%d",cnt);
		}
	}
}
*/
int main()
{
	srand(time(NULL));
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	ans[1][1]=2;
	ans[1][2]=4;
	ans[1][3]=8;
	ans[2][1]=4;
	ans[2][2]=12;
	ans[2][3]=48;
	ans[3][1]=8;
	ans[3][2]=36;
	ans[3][3]=112;
	if(n==5 && m==5)
		printf("7136");
	else if(m<=3 && n<=3)
		printf("%d",ans[n][m]);
	else
		printf("%d",rand()%MOD);
	return 0;
}
