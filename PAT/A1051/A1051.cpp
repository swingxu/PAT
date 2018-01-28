#include <iostream>
#include <string>
using namespace std;

/*
 * 逆序判断
 * 栈内元素判断
 * */

int main() {
    int M,N,K;
    scanf("%d%d%d",&M,&N,&K);
    string str[100];
    for(int k = 0 ; k < K ; k++){
        bool flag = true;
        int max=0,x,num=1,min=0x7fffffff;
        for(int n = 0 ; n < N ; n++){
            scanf("%d",&x);
            if(x>max) {
                max = x;
                min = x;
                num = 1;
            } else {
                if(x>min){
                    flag = false;
                } else {
                    min = x;
                    num++;
                }
            }
            if(num>M) flag = false;
        }

        if(flag == true) str[k] = "YES";
        else str[k] = "NO" ;
    }
    for(int k = 0 ; k < K ; k++) {
        cout<<str[k]<<endl;
    }
    return 0;
}