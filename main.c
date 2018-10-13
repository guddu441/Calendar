#include<stdio.h>
char month[13][15]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
int numberofdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int determineFirstDayOfYear(int year)
{
     int d1, d2, d3;
     d1 = (year - 1.)/ 4.0;
     d2 = (year - 1.)/ 100.;
     d3 = (year - 1.)/ 400.;
     return (year + d1 - d2 + d3) %7;
}

void calander(int first,int a,int b)
{
    int i,leap=0,fn,total=0;
    if((a==2)&&(b%4==0))
    {
        leap=1;
    }
    for(i=1;i<=a-1;i++)
    {
       total=total+numberofdays[i];
    }
    fn=(total+first)%7;
   for(i=1;i<=fn;i++)
   {
       printf("  \t");
   }
   for(i=1;i<=numberofdays[a]+leap;i++)
   {
       printf("%3d\t",i);
       if((i+fn)%7==0)
       {
           printf("\n");
       }
   }
}

int main()
{
    int a,b,first;
    scanf("%d %d",&a, &b);
    printf("%s %d\n\n",month[a],b);
    printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
    first=determineFirstDayOfYear(b);
    calander(first,a,b);
    return 0;
}
