#include <stdio.h>

main() {
    int arr[10],n,num,M,i;
	int SN;
    scanf("%d",&n);
    for (i=0;i<=9;i++)
    	arr[i]=0;
    	
    do{
        num=n%10;
        n/=10;
        arr[num]+=1;
    }while(n>0);
    
    //for (i=0;i<=9;i++)
    //	printf("%d ",arr[i]);//debuging
    SN=(arr[6]+arr[9])/2 + (arr[6] + arr[9]) % 2;
    //printf("%d\n",SN);//debuging
    M=arr[0];
    
    for(i=1;i<9;i++) {
        if(i==6)
            continue;
        if(M<arr[i])
            M=arr[i];
    }
    
    if(M>=SN)
        printf("%d\n",M);
    else
        printf("%d\n",SN);
}
