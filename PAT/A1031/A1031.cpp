#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    char word[90];
    int len,n1,n2;
    scanf("%s",word);
    len = strlen(word);
    for(n2=3;n2<=len;n2++){
        if((len+2-n2)%2) continue;
        n1 = (len + 2 - n2)/2;
        if (n1<=n2) break;
    }
    for(int i = 0 ; i < n1 ; i++){
        for(int j = 0 ; j < n2 ; j++){
            if(i== (n1-1)){
                printf("%c",word[n1-1+j]);
            }
            else{
                if(j==0) printf("%c",word[i]);
                else if (j==n2-1) printf("%c",word[len-1-i]);
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}