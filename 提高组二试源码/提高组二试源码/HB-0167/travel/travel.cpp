# include <cstdio>
# include <iostream>
using namespace std;
int lian1[5050],lian2[5050];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,i,j,x,y,cheng=1,_cheng[1];
	cin>>n>>m;
	for(i=0;i<m;i++)
		cin>>lian1[i]>>lian2[i];
	cout<<"1"<<" ";
	for(i=1;i<n;i++)
	{
		_cheng[0]=_cheng[1];
		for(j=0;j<m;j++)
		{
			if(lian1[j]==cheng)
			{
				_cheng[1]=lian2[j];
				x=j;
				y=j;
				break;
			}
			if(lian2[j]==cheng)
			{
				_cheng[1]=lian1[j];
				x=j;
				y=j;
				break;
			}
		}
		for(j=y;j<m;j++)
		{
			if(lian1[j]==cheng)
				if(lian2[j]<_cheng[1])
				{
					_cheng[1]=lian2[j];
					x=j;
				}
			if(lian2[j]==cheng)
				if(lian1[j]<_cheng[1])
				{
					_cheng[1]=lian1[j];
					x=j;
				}
		}
		if(_cheng[1]==cheng)
		{
			cheng=_cheng[0];
			i--;
		}
		else
		{
			cout<<_cheng[1]<<" ";
			cheng=_cheng[1];
		}
		lian1[x]=10000;
		lian2[x]=10000;
	}
	return 0;
}
