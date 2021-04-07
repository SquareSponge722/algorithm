# include<cstdio>
# include<algorithm>

using namespace std;

int n,a[100050],sun;
long long sum;

void _sum(int L,int R)
{
	int i,j,min=L,temp;
	if(L<1 || R>n || L>R) return;

	for(i=L;i<=R;i++)
	{
		if(a[i]<a[min]) min=i;
	}
	sum+=a[min];temp=a[min];
	for(i=L;i<=R;i++)
	{
		a[i]-=temp;
		if(!a[i]) sun--;
	}
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j=0;
	scanf("%d",&n);
	sun=n;
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	_sum(1,n);
	while(sun>0)
	{
		i=1;
		while(a[i]==0 && i<=n)
			i++;
		j=i;
		while(a[j]!=0 && j<=n)
			j++;
		_sum(i,j-1);
	}
	printf("%lld",sum);
	return 0;
}
