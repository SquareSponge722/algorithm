#include <stdio.h>

freopen("road.in","r",stdin);
freopen("road.out","rw",stdout);
int main()
{

    int n;
    scanf("%d",&n);
    int len[n];
    int i,j,k,l;
    int cnt=0;
    int temp1=0;
    int temp2=n;
    len[0]=0;
    for(i=1;i<n;i++)
    {
        scanf("%d ",&len[i]);
    }
    len[n]=0;
    for(k=temp1+1;k<=temp2-2;k++)
    {
        if(len[k]==0)
        {
            temp2=k;

            break;
        }
        else
        {
            for(j=temp1+1;j<=temp2-2;j++)
            {
                len[k]=len[k]-1;
                cnt++;
            }
            for(l=temp2-1;l<=n-1;l++)
            {
                len[k]=len[k]-1;
                cnt++;
            }
        }
    }
    //for(l=temp1+1;l<=temp2-2;l++)
    {

    }
    printf("%d",cnt);
}
