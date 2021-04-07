#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    long long int n,i=1,flag2=1;
    long int ts=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%ld",&n);
    long int d[n+1]={0};
    for(i=1;i<=n;i++)
        scanf("%d",&d[i]);
    while(1)
    {
        i=flag2;
        while(i<=n&&d[i]==0)
            i++;
        flag2=i;
        if(i>n)
            break;
        while(i<=n&&d[i]>0)
        {
            d[i]=d[i]-1;
            i++;
        }
        ts++;
    }
    printf("%ld",ts);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
