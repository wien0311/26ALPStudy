#include <stdio.h>

int main() {
	int n,v,k,count=0;
	scanf("%d",&n);
#pragma diag_suppress 28
	int arr[n];
	for (int i=0; i<n; i++)
		arr[i]=0;
		
	for (int i=0; i<n; i++) {
		scanf("%d",&k);
		arr[i]=k;
	}
	scanf("%d",&v);
	
	for(int i=0; i<n; i++) {
		if (v==arr[i]) 
			count+=1;
	}
	printf("%d",count);
	
	return 0;
}