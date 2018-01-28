#include <iostream>
int max(int a){
    switch(a){
        case 2:
            return 29;
        case 1:
            return 17;
        case 0:
            return 10000000;
    }
}

int main() {
    int A[3],B[3],C[3],x=0;
    scanf("%d.%d.%d",&A[0],&A[1],&A[2]);
    scanf("%d.%d.%d",&B[0],&B[1],&B[2]);
    for(int i = 2; i>=0 ; i--){
        C[i] = (A[i]+B[i]+x) % max(i);
        x =( A[i] + B[i] ) / max(i);
    }
    for (int i = 0; i < 3; ++i) {
        printf("%d",C[i]);
        if(i!=2) printf(".");
        else printf("\n");
    }
    return 0;
}