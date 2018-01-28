#include <iostream>
#include <algorithm>
using namespace std;

int n,group[1010],father[1010]={0},Count[1000]={0};

bool cmp(int a,int b){
    return a>b;
}
void init (int n){
    for(int i = 0 ; i < n ;i++){
        father[i] = i;
    }
}

int findF(int a){
    int x=a;
    while(father[a]!=a){
        a = father[a];
    }
    while(father[x]!=x){
        int z = x;
        x = father[x];
        father[z] = a;
    }
    return a;
}

void Union(int a , int b){
    int fa = findF(a);
    int fb = findF(b);
    if(fa != fb) {
        father[fa] = fb;
    }
};

int main() {
    int n;
    scanf("%d",&n);
    init(n);
    for(int i = 1 ; i <= n ; i++){
        int m;
        scanf("%d: ",&m);
        for(int j = 0 ; j < m ; j++){
            int v;
            scanf("%d",&v);
            if(group[v] == 0){
                group[v] = i ;
            } else {
                Union(i,group[v]);
            }
        }
    }
    int sum=0;
    for(int i = 1 ; i <= n ; i++){
        int x = findF(i);
        if(Count[x] == 0) sum++;
        Count[x]++;
    }
    printf("%d\n",sum);
    sort(Count,Count+n,cmp);
    for(int i = 0 ; i < sum ; i++){
        printf("%d",Count[i]);
        if(i != sum-1) printf(" ");
    }
    return 0;
}