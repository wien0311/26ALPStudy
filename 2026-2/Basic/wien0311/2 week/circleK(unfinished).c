/*
#include <stdio.h>

int main() {
    int n, k, count=0, num=0, sum=0;
    scanf("%d %d", &n, &k);
    int arr[n]={0};

    for(int i=1; i<=n; i++) {
        sum=k*i;
        if(sum>n) {
            sum=sum%n;
            count+=1
        }
    }
}
*/
/*
고민중; n배열을 k k*2 k*3이런식으로 구하려다 뭔가 복잡해져서
배열을 버리고 수학적으로 구할까 하다가 ---1
n/k+1배열을 만들어서 예를 들어 n==7, k==3이면
{1 2 3 4 5 6 7 1 2 3 4 5 6 7 1 2 3 4 5 6 7 1 2 3 4 5 6 7}
이런식으로 반복되는 배열을 만들어서 +=k번째로 구하는방법 ---2
*/
