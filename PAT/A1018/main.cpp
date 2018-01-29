#include <iostream>

int main() {
    int n,radix;
    scanf("%d%d",&n,&radix);
    int d[1100],len = 0;
    while(n != 0){
        d[len++] = n%radix;
        n /= radix;
    }
    bool flag = true;
    for(int i = 0 ; i < len/2 ; i++){
        if(d[i] != d[len - 1 - i]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        printf("Yes\n");
        for(int i = len - 1 ; i >= 0 ; i--){
            printf("%d",d[i]);
            if(i != 0) printf(" ");
        }
    } else {
        printf("No\n");
        for(int i = len - 1 ; i >= 0 ; i--){
            printf("%d",d[i]);
            if(i != 0) printf(" ");

        }
    }
    if(len == 0)
        printf("0");
    return 0;
}