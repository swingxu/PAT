#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct cake{
    double price;
    double amount;
    double total;
} mooncake[1010];

bool cmp(cake a , cake b){
    return a.price>b.price;
}
int main() {
    int N;
    double need,profit=0;
    scanf("%d %lf",&N,&need);
    for (int i = 0; i < N; ++i) {
        scanf("%lf",&mooncake[i].amount);
    }
    for(int i = 0 ; i < N ;++i){
        scanf("%lf",&mooncake[i].total);
        mooncake[i].price = mooncake[i].total/mooncake[i].amount;
    }
    sort(mooncake,mooncake+N,cmp);
    for(int i = 0 ; i < N;++i){
        if(mooncake[i].amount>=need) {
            profit+=(need*mooncake[i].price);
            break;
        }
        else {
            profit+=mooncake[i].total;
            need=need-mooncake[i].amount;
        }
    }
    printf("%.2lf",profit);
    return 0;
}