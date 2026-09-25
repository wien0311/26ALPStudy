#include <stdio.h>
#include <string.h>

int main() {
    char a1[1000], a2[1000];
    int arr1[1000], arr2[1000],count=0;
    scanf("%c",&a1);
    scanf("%c",&a2);
    
    for(int i=0; i<strlen(a1);i++) 
        arr1[i]=a1[i];
    for(int i=0; i<strlen(a2);i++)
        arr2[i]=a2[i];
    
    for (int i=0; i<strlen(a1); i++) {
        for(int j=0; j<strlen(a2); j++) {
            if (arr1[i]!=arr2[j]) count+=1;
        }
    }
    printf("%d",count);

    return 0;
}