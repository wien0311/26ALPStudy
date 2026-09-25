    #include <stdio.h>
    #include <string.h>

    int main() {
        char s[100];
		scanf("%s", s);
		int arr[26]={0},k=strlen(s),num;

        for (int i=0; i<k; i++) {
            num=s[i]-'a';
            arr[num]+=1;
        }
        for(int i=0; i<26; i++)
            printf("%d ",arr[i]);
        
        return 0;
    }