#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100000
using namespace std;

bool cmp(int a, int b){
    if(a<=0&&b<=0) return a<b;
    else return a>b;
}

int main() {
    int coupon[N]={0},cnum,product[N]={0},pnum,profit=0;
    scanf("%d",&cnum);
    for(int i=0 ; i<cnum ; i++){
        scanf("%d",&coupon[i]);
    }
    scanf("%d",&pnum);
    for(int i=0 ; i<pnum ; i++){
        scanf("%d",&product[i]);
    }
    sort(coupon,coupon+cnum,cmp);
    sort(product,product+pnum,cmp);
    int i=0,j=0;
    while(coupon[i]!=0&&product[j]!=0){
        if(coupon[i]*product[j]>0){
            profit += coupon[i]*product[j];
            i++,j++;
        } else {
            if(coupon[i]<0) j++;
            if(product[j]<0) i++;
        }
    }
    printf("%d\n",profit);
    return 0;
}