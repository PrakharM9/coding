#include <stdio.h>

int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d\n",&b);
    int c=(a>b)?b:a;
    int d=(a>b)?a:b;
    int count=0;
    int lcm;
    for (int i=1;i<=c;i+=1){
        if (c%i==0 && d%i==0){
            lcm=i;
        };
    };
    printf("HCF = %d\n",lcm);
    while (count==0){
        if (d%c==0){
            printf("LCM = %d\n",d);
            count+=1;
        } 
        else {
            d+=d;
        }
    }
    return 0;
}