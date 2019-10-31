#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
#include<math.h>
#define LL long long
#define mx 10010
using namespace std;

void rec(int num)
{
    //printf("rec==%d\n",num);
    if(num==1) {return ;}
    if(num==0) {printf("0");return ;}
    if(num==2) {printf("2");return ;}

        while(num>0)
        {
            double k=(log(num)/log(2));
            int lo=(int)k;//printf("while==%d, lo=%d\n",num,lo);
            if(lo==1) printf("2");
            else    printf("2(");

            rec(lo);
          //printf("  %d",num);
           num=num-(int)(pow(2,lo));
           if(lo!=1)
           printf(")");
           if(num>0) printf("+");
        }
        return ;
}

int main()
{
    //int num=128;
    //double k=(log(num)/log (2));
    //printf("%d",(int)k);
    printf("137=");rec(137);
    printf("\n1315=");rec(1315);
    printf("\n73=");rec(73);
    printf("\n136=");rec(136);
    printf("\n255=");rec(255);
    printf("\n1384=");rec(1384);
    printf("\n16385=");rec(16385);
    printf("\n");
    return 0;
}    