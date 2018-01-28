#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct score{
    char id[100];
    int v;
    int t;
    int rank;
} stu[100010];

bool cmp(score a , score b){
        if(a.rank==b.rank) {
            if((a.v+a.t)!=(b.v+b.t)) return a.v+a.t>b.v+b.t;
            else {
                if(a.v!=b.v) return a.v>b.v;
                else return strcmp(a.id,b.id)<0;
            }
        }

        else return a.rank>b.rank;
};

int main() {
    int num,rank1,rank2,count=0;
    scanf("%d %d %d",&num,&rank1,&rank2);
    for(int i = 0 ; i<num ; i++){
        scanf("%s %d %d",&stu[i].id,&stu[i].v,&stu[i].t);
        if(stu[i].v<rank1 || stu[i].t<rank1){
            stu[i].rank = 0;
            continue;
        }
        count++;
        if(stu[i].v>=rank2&&stu[i].t>=rank2) stu[i].rank = 4;
        if(stu[i].v>=rank2&&stu[i].t<rank2) stu[i].rank = 3;
        if(stu[i].v<rank2&&stu[i].t<rank2&&stu[i].v>=stu[i].t) stu[i].rank = 1;
    }
    sort(stu,stu+num,cmp);
    printf("%d\n",count);
    for(int i = 0 ; i<count ;i++){
        printf("%s %d %d\n",stu[i].id,stu[i].v,stu[i].t);
    }

    return 0;
}