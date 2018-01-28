#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1050;
int N,tree[MAXN] = {-1},data[MAXN];

int k = 0;
void inOrder(int root){
    if(root > N) return;
    inOrder(root*2);
    tree[root] = data[k++];
    inOrder(root*2+1);
}

int main() {
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&data[i]);
    }
    sort(data,data+N);
    inOrder(1);
    for(int i = 1 ; i <= N ; i++){
        printf("%d",tree[i]);
        if(i<N) printf(" ");
        else printf("\n");
    }
    return 0;
}