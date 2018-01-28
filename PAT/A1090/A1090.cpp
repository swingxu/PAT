#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MAXN = 100010;

int N;
double p,r;

struct Node {
    vector<int> child;
} node[MAXN];

int temp,num = 0;
double sum=0;
void DFS(int index,int count){
    if(node[index].child.size() == 0){
        if(count > temp) {
            num = 0;
            temp = count;
            sum = p * pow((100+r)/100,temp);
        }
        if (count == temp) {
            num++;
        }
        return;
    }
    for (int i = 0; i < node[index].child.size(); ++i) {
        DFS(node[index].child[i],count+1);
    }
};

int main() {
    scanf("%d %lf %lf",&N,&p,&r);
    int root;
    for(int i = 0 ; i < N ; i++){
        int node_num;
        scanf("%d",&node_num);
        if(node_num != -1){
            node[node_num].child.push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root,0);
    printf("%.2lf %d\n",sum,num);
    return 0;
}