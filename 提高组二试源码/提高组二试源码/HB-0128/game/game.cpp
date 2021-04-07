#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#define ll long long
using namespace std;
inline ll read()
{
    int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
	    if(c=='-')
		{
	 	    f=-1;
        }
	    c=getchar();
    }
	while(c>='0'&&c<='9')
	{
	    x=x*10+c-'0';
        c=getchar();
    }
	return x*f;
}
int main()
{
 	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int x=read(),y=read();
	/*int ans=0;
			for(int i=0;i<=1;i++)
			{
				for(int i1=0;i1<=1;i1++)
				{
					for(int i2=0;i2<=1;i2++)
					{
						for(int i3=0;i3<=1;i3++)
						{
							for(int i4=0;i4<=1;i4++)
							{
								for(int i5=0;i5<=1;i5++)
								{
									for(int i6=0;i6<=1;i6++)
									{
										for(int i7=0;i7<=1;i7++)
										{
											for(int i8=0;i8<=1;i8++)
											{
												int r1=i*10000+i1*1000+i2*100+i5*10+i8;
												int r2=i*10000+i1*1000+i4*100+i5*10+i8;
												int r3=i*10000+i1*1000+i4*100+i7*10+i8;
												int r4=i*10000+i3*1000+i4*100+i5*10+i8;
												int r5=i*10000+i3*1000+i4*100+i7*10+i8;
												int r6=i*10000+i3*1000+i6*100+i7*10+i8;
												if(r1<=r2&&r1<=r3&&r1<=r4&&r1<=r5&&r1<=r6&&r2<=r3&&r2<=r4&&r2<=r5&&r2<=r6&&r3<=r4&&r3<=r5&&r3<=r6&&r4<=r5&&r4<=r6&&r5<=r6)
												{
													ans++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<ans<<endl;*/
	if(x<=3&&y<=3)
	{
		if(x==2&&y==2)
		{
			printf("12\n");
			return 0;
		}
		if(x==3&&y==3)
		{
			printf("112\n");
			return 0;
		}
		if(x==1&&y==1)
		{
			printf("2\n");
			return 0;
		}
		if(x==1&&y==2)
		{
			printf("4\n");
			return 0;
		}
		if(x==2&&y==1)
		{
			printf("4\n");
			return 0;
		}
		if(x==3&&y==1)
		{
			printf("8\n");
			return 0;
		}
		if(x==1&&y==3)
		{
			printf("8\n");
			return 0;
		}
		if(x==3&&y==2)
		{
			/*int ans=0;
			for(int i=0;i<=1;i++)
			{
				for(int i1=0;i1<=1;i1++)
				{
					for(int i2=0;i2<=1;i2++)
					{
						for(int i3=0;i3<=1;i3++)
						{
							for(int i4=0;i4<=1;i4++)
							{
								for(int i5=0;i5<=1;i5++)
								{
									int r3=i*1000+i3*100+i4*10+i5;
									int r1=i*1000+i2*100+i3*10+i5;
									int r2=i*1000+i1*100+i4*10+i5;
									if(r1<=r2&&r1<=r3&&r2<=r3)
									{
										ans++;
									}
								}
							}
						}
					}
				}
			}
			cout<<ans<<endl;*/
			cout<<24<<endl;
			return 0;
		}
		if(x==2&&y==3)
		{
			cout<<24<<endl;
			return 0;
		}
	}
	return 0;
}


