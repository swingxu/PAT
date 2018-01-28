#include <iostream>
#include <cstdio>


int main() {
    int seq;
    double a[3][3],profit=1.0;
    for(int i = 0 ; i <3 ;i++){
        for(int j = 0 ; j<3 ; j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for(int i = 0 ; i < 3 ; i++){
        double max=0;
        for (int j = 0 ;j < 3;j++){
            if(a[i][j]>max) {
                seq = j;
                max = a[i][j];
            }
        }
        switch(seq){
            case 0 : printf("W ");
                break;
            case 1 : printf("T ");
                break;
            case 2 : printf("L ");
                break;
        }
        profit *= max;
    }
        printf("%.2lf\n",(profit*0.65-1)*2);
    return 0;
}