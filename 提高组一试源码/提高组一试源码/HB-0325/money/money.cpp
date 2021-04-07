#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

bool cmp(const int a,const int b)
{
    return a<b;
}

bool pd(int *a,int sz)
{
    int i,j;
    for(i=2;i<sz;i++)
        for(j=1;j<=i;j++)
            if((a[sz]%a[i])%a[j]==0)
                return true;
    return false;
}

int main()
{
    int t,n,i,a[101]={0},j,m,k,flag[101]={0},m1,m2,zdz;
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
            flag[j]=0;
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        m=n;
        for(j=1;j<=n;j++)
            scanf("%d",&a[j]);
        sort(a+1,a+n+1,cmp);
        for(j=n;j>1;j--)
            for(k=1;k<j;k++)
                if(a[j]%a[k]==0)
                {
                    m--;
                    flag[j]=1;
                    break;
                }
        m1=a[1];
        j=2;
        while(flag[j]==1&&j<=n)
            j++;
        if(j>n)
        {
            printf("1\n");
            continue;
        }
        m2=a[j];
        zdz=max(m1*m2-m1-m2,m2);
        j=n;
        while(zdz<a[j])
        {
            if(flag[j]==0)
            {
                flag[j]=1;
                m--;
            }
            j--;
        }
        if(a[j]==m2)
        {
            printf("2\n");
            continue;
        }
        for(j=n;j>2;j--)
            if(flag[j]==0&&pd(a,j)==true)
                m--;
        printf("%d\n",m);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
