#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
//포인터를 잘 몰라서 코드 찾아보고 참고. 
int main() {
    int arr[5], sum=0;
    for(int i=0; i<5; i++) scanf("%d", &arr[i]);

    sum=(arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5;

    qsort(arr, 5, sizeof(int), compare);//qsort 함수도 찾아보며 알아냄. 
    
    //for(int i=0; i<5; i++) printf("%d \n",arr[i]);//debuging
    printf("%d\n%d\n",sum,arr[2]);

    return 0;
}