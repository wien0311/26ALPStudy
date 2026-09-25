#include <stdio.h>

int main() {
    int a,b,c,sum,arr[10]={0},n,count=0,temp;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    sum=a*b*c;
	
    temp=sum;
    while(temp>0) {
        temp/=10;
        count+=1;
    }

    for(int i=0;i<count;i++) {
        n=sum%10;
        sum/=10;
        arr[n]+=1;
    }
    for (int i=0;i<10;i++)
        printf("%d\n",arr[i]);

    return 0;
}