#include <iostream>

int main() {
    int N ;
    scanf("%d",&N);
    int a[100];
    a[0] = 0;
    for(int i = 1 ; i <= N ; i++){
        scanf("%d",&a[i]);
    }
    int sum = 5 * N;
    for(int i = 1 ; i <=N ; i++){
        int d = a[i] - a[i-1];
        if(d > 0){
            sum += (d*6);
        } else {
            sum += (-d*4);
        }
    }
    printf("%d\n",sum);
    return 0;
}