#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int MAX = 100010;

struct Node {
    vector<int> child ;
    int pnum = 0 ;
} node[MAX];

int N;
double p,r;
bool map[MAX] = {false};
int root;

void findroot(){
    for(int i = 0 ; i < N ; i++){
        if (map[i] == false) {
            root = i;
            break;
        }
    }
}

double sum = 0;
void DFS(int index,int count){
    if(node[index].child.size() == 0) {
        sum += node[index].pnum * p * pow((100+r)/100,count);
        return;
    }
    for (int i = 0; i < node[index].child.size(); i++) {
        DFS(node[index].child[i],count+1);
    }
}

int main() {
    scanf("%d %lf %lf",&N,&p,&r);
    for (int i = 0; i < N; i++) {
        int child_num,temp;
        scanf("%d",&child_num);
        if(child_num != 0){
            for (int j = 0; j < child_num; j++) {
                scanf("%d",&temp);
                node[i].child.push_back(temp);
                map[temp] = true;
            }
        } else {
            scanf("%d",&temp);
            node[i].pnum = temp ;
        }
    }
    findroot();
    DFS(root,0);
    printf("%.1lf",sum);
    return 0;
}