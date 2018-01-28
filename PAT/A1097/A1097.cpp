#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxn = 100010;

struct node_struct{
    int address;
    int data = 10001;
    int next;
    int order = 0x7fffffff;
    int flag = 1;
} node[maxn];

bool cmp1(node_struct a , node_struct b){
    if(abs(a.data)!=abs(b.data)) {
        return abs(a.data) < abs(b.data);
    } else {
        return a.order < b.order ;
    }
}

bool cmp2(node_struct a , node_struct b){
    if(a.flag!=b.flag) {
        return a.flag>b.flag;
    } else {
        return a.order<b.order;
    }
}
int main() {
    int begin,N,add1,add2,d;
    scanf("%d %d",&begin,&N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d",&add1,&d,&add2);
        node[add1].address = add1;
        node[add1].next = add2;
        node[add1].data = d;
    }
    int p , count = 0;
    for (p = begin ; p!=-1 ; p = node[p].next) {
        node[p].order = count;
        count++;
    }
    sort(node,node+maxn,cmp1);
    for(int i = 0 ; i < count ; i++){
        if(abs(node[i].data) == abs(node[i+1].data)) node[i+1].flag = 0;
    }
    sort(node,node+count,cmp2);
    node[count].address = -1;
    int end=0;
        for(int i = 0 ; i < count ; i++){
            if(end == 0){
                if(node[i+1].flag != 0){
                    printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
                } else {
                    printf("%05d %d -1\n",node[i].address,node[i].data);
                    end=1;
                }
            } else {
                if(node[i+1].address != -1){
                    printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
                } else {
                    printf("%05d %d -1\n",node[i].address,node[i].data);
                }
            }
        }
    return 0;
}