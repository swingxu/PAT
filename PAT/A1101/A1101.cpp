#include <iostream>

int main() {
    int N,a[100010],flag[100010],ans[100010];
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&a[i]);
    }
    int max = 0 , min = 0x7fffffff;
    for(int i = 0 ; i < N ; i++){
        if(a[i]>=max) {
            max = a[i];
        } else {
            flag[i] = 1;
        }
    }
    int count=0,k=0;
    for (int j = N-1; j >= 0 ; j--) {
        if(a[j]<=min){
            min = a[j];
            if(flag[j] == 0) {
                count++;
                ans[k++]=a[j];
            }
        } else {
            flag[j] = 1;
        }
    }
    printf("%d\n",count);
    for(int i = count -1 ; i >= 0 ; i--){
        printf("%d",ans[i]);
        if(i!=0) printf(" ");
    }
    printf("\n");
    return 0;
}