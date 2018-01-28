#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct node {
    int address;
    int data;
    int next;
    bool flag=0;
} no[maxn];

bool cmp (node a,node b){
    if(a.flag == 0 || b.flag == 0 ){
        return a.flag>b.flag;
    } else{
        return a.data<b.data;
    }
    return a.data<b.data;
}

int main() {
    int N,top;
    scanf("%d %d",&N,&top);
    int s1,s2,d;
    for(int i = 0 ; i < N ; i++){
        scanf("%d %d %d",&s1,&d,&s2);
        no[s1].data = d;
        no[s1].address = s1;
        no[s1].next = s2;
    }
    int count=0;
    for( int p = top ; p!=-1 ; p = no[p].next){
        no[p].flag = 1;
        count ++;
    }
    sort(no,no+maxn,cmp);
    int next;
    if(count == 0){
        printf("0 1\n");
    } else{
        printf("%d %05d\n",count,no[0].address);
        for (int j = 0; no[j].flag==1 ; j++) {
            if(no[j+1].flag == 0) {
                printf("%05d %d -1\n",no[j].address,no[j].data);
            }
            else {
                next = no[j+1].address;
                printf("%05d %d %05d\n",no[j].address,no[j].data,next);
            }
        }
    }

    return 0;
}