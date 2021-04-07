#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;
int T;
const int N=30000;
int a[N];
int n;
int nn;
bool flag[N];
void init()
{
	scanf("%d",&n);
	for (int i=0; i<n; i++)
		scanf("%d",&a[i]),flag[i]=true;
	nn=n;
}
void w_slx(int aa)
{

	if(aa==1)
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				if(i!=j)
				{
					if(((a[i]==a[j]) && flag[j])||((a[j]%a[i])==0 && flag[j]))
					{
						nn--;
						flag[j]=false;
					}
				}
			}
		}

	if(aa==2)
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				if(i!=j)
				{
					int sum=a[i]+a[j];
					for(int k=0; k<n; k++)
					{
						if((a[k]%sum)==0 && flag[k])
							nn--,flag[k]=false;
					}
				}
			}
		}
	if(aa==3)
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				for (int k=0; k<n; k++)
				{
					if(i!=j !=k)
					{
						int sum=a[i]+a[j]+a[k];
						for (int q=0; q<n; q++)
						{
							if((a[q]%sum)==0 && flag[q])
							{
								nn--;
								flag[q]=false;
							}
						}
					}
				}
			}

		}
	if(aa==4)
	{
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				for (int k=0; k<n; k++)
				{
					for (int ii=0; ii<n; ii++)
						if(i!=j!=ii!=k)
						{
							int sum=a[i]+a[j]+a[k]+a[ii];
							for (int q=0; q<n; q++)
							{
								if((a[q]%sum)==0 && flag[q])
								{
									nn--;
									flag[q]=false;
								}
							}
						}
				}
			}

		}
	}
	if(aa==5)
	{
		if(aa==4)
		{
			for (int i=0; i<n; i++)
			{
				for (int j=0; j<n; j++)
				{
					for (int k=0; k<n; k++)
					{
						for (int ii=0; ii<n; ii++)
							for (int jj=0; jj<n; jj++)
								if(i!=jj!=j!=k!=ii)
								{
									int sum=a[i]+a[j]+a[k]+a[ii]+a[jj];
									for (int q=0; q<n; q++)
									{
										if((a[q]%sum)==0 && flag[q])
										{
											nn--;
											flag[q]=false;
										}
									}
								}
					}
				}

			}
		}
	}
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		init();
		for (int b=0; b<n; b++)
			w_slx(b);
		printf("%d",nn);
	}
	return 0;
}
