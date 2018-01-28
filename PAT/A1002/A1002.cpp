#include <iostream>
const int maxn = 1050;
double a[maxn] = {0};

int main() {
    int an = 0,bn = 0;
    scanf("%d",&an);
    int n,num = 0;
    for(int i = 0 ; i < an ; i++){
        scanf("%d",&n);
        double temp;
        scanf("%lf",&temp);
        a[n] += temp;
    }
    scanf("%d",&bn);
    for(int i = 0 ; i < bn ; i++){
        scanf("%d",&n);
        double temp;
        scanf("%lf",&temp);
        a[n] += temp;
    }
    for(int i = 0 ; i < maxn ; i++){
        if(a[i] != 0 ) num++;
    }
    printf("%d",num);
    for(int i = maxn ; i >= 0 ; i--){
        if(a[i] != 0){
            printf(" %d ",i);
            printf("%.1lf",a[i]);
        }
    }
    printf("\n");
    return 0;
}