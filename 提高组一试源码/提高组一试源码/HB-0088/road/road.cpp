#include <cstdio>
int main()
{freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,a,b,c,d,e,f,g,sum;
scanf("%d\n",&n);
if(n==1&&scanf("%d",&a))
printf("%d",a);

else
if(n==2&&scanf("%d %d",&a,&b)&&a>=b)
printf("%d",a);
else
if(n==2&&a<b)
printf("%d",b);

else
if(n==3&&scanf("%d %d %d",&a,&b,&c))
{if(a>=b&&b>=c)
printf("%d",a);
else
if(a>=c&&c>=b)
{sum=b+(c-b)+(a-b);
printf("%d",sum);
}
else
if(b>=a&&a>=c||b>=a&&a<=c&&b>=c)
printf("%d",b);
else
if(c>=b&&b>=a)
printf("%d",c);
else
if(c>=a&&a>=b)
{sum=b+(a-b)+(c-b);
printf("%d",sum);
}
}

else
if(n==4&&scanf("%d %d %d %d",&a,&b,&c,&d))
{if(a>=b&&b>=c&&c>=d)
printf("%d",a);
else
if(a>=b&&b>=d&&d>=c)
{sum=c+(a-c)+(d-c);
printf("%d",sum);
}
else
if(a>=d&&d>=c&&c>=b)
{sum=b+(a-b)+(d-b);
printf("%d",sum);
}
else
if(a>=c&&c>=d&&d>=b)
{sum=b+(a-b)+(c-b);
printf("%d",sum);
}
else
if(a>=d&&d>=b&&b>=c)
{sum=c+(a-c)+(d-c);
printf("%d",sum);
}
else
if(a>=c&&c>=b&&b>=d)
{sum=d+(b-d)+(c-b)+(a-c);
printf("%d",sum);
}
else
if(b>=a&&a>=c&&c>=d)
{sum=b;
printf("%d",sum);
}
else
if(b>=a&&a>=d&&d>=c)
{sum=c+(d-c)+(b-c);
printf("%d",sum);
}
else
if(b>=c&&c>=d&&d>=a)
{sum=b;
printf("%d",sum);
}
else
if(b>=d&&d>=c&&c>=a)
{sum=a+(c-a)+(b-c)+(d-c);
printf("%d",sum);
}
else
if(b>=d&&d>=a&&a>=c)
{sum=c+(b-c)+(d-c);
printf("%d",sum);
}
else
if(b>=c&&c>=a&&a>=d)
{sum=b;
printf("%d",sum);
}
}
return 0;
}
