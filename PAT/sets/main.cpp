#include <cstdio>

int isRoot[1000],father[1000];

void init(int n){
    for(int i = 0 ; i < n ; i++){
        father[i] = i ;
    }
}

int findR(int a){
    while(father[a]!=a){
        a = father[a];
    }

}
void Union(int a,int b){
    int fa = findR(a);
    int fb = findR(b);
    if(fa!=fb){
        father[fa] = fb;
    }
}

int main() {
    int n,g;
    init(n);
    for(int i = 0 ; i < g ; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Union(a,b);
    }
    return 0;
}