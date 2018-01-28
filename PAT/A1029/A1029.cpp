#include <iostream>
#define MAX 1000010
const int INF = 0x7fffffff;
int main() {
    int a[MAX]={0},b[MAX]={0},ans;
    int A,B,i=0,j=0;
    scanf("%d",&A);
    for(int x = 0 ; x < A ;x++){
        scanf("%d",&a[x]);
    }
    scanf("%d",&B);
    for(int x = 0 ; x < B ;x++){
        scanf("%d",&b[x]);
    }
    a[A]=b[B]=INF;
    while(i+j<=(A+B+1)/2-1 ){
        if(a[i]<b[j]) {
            ans = a[i];
            i++;
        } else {
            ans = b[j];
            j++;
        }
    }
    printf("%d",ans);
    return 0;
}