#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct node_struct{
    int data;
    int next;
    int address;
    int order=0x7fffffff;
} node[maxn];

bool cmp1(node_struct a,node_struct b){
    return a.order<b.order;
}
bool cmp2(node_struct a,node_struct b){
    return a.order>b.order;
}
int main() {
    int begin,N,K;
    scanf("%d %d %d",&begin,&N,&K);
    int s1,s2,d;
    for( int i = 0 ; i < N ; i++ ){
        scanf("%d %d %d",&s1,&d,&s2);
        node[s1].data = d;
        node[s1].next = s2;
        node[s1].address = s1;
    }
    int count = 0 ;
    for( int p = begin ,i = 0 ; p != -1 ; i++ ,p = node[p].next){
        node[p].order = i;
        count++;
    }
    int temp;
    sort(node,node+maxn,cmp1);
    for(int i = 0 ; i < count/K ; i++){
        sort(node+i*K,node+i*K+K,cmp2);
    }
    node[count].address = -1;
    for (int i = 0; i < count; i++) {
        if(i == count-1) {
            printf("%05d %d -1\n",node[i].address,node[i].data);
        } else {
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
        }
    }
    return 0;
}