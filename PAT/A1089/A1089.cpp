#include <iostream>
#include <algorithm>
using namespace std ;

int N,a1[10000],a2[10000],temp[10000];

bool isSame(int x[],int y[]){
    bool flag = true;
    for (int i = 0 ; i < N ; i++){
        if(x[i]!=y[i]) {
            return false;
        }
    }
    return true ;
}

bool insertsort(){
    bool flag = true;
    for(int i = 1 ; i < N ; i++){
        if(isSame(tem))
    }
}

int main() {
    scanf("%d",&N);
    for(int i = 0 ; i<N ; i++){
        scanf("%d",&a1[i]);
        temp[i] = a1[i];
    }
    for(int i = 0 ; i<N ; i++){
        scanf("%d",&a2[i]);
    }

    return 0;
}