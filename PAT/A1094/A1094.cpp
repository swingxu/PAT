#include <iostream>
#include <vector>
#include <queue>
using namespace std ;
const int MAXN = 150;

int M,N;

struct Node {
    vector<int> child;
    int layer;
} node[MAXN];

bool findR[MAXN] = {false};

int layerCount[MAXN] = { 0 };

void BFS (int index) {
    queue<int> q;
    q.push(index);
    node[index].layer = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        layerCount[node[temp].layer]++;
        for(int i = 0 ; i < node[temp].child.size() ; i++){
            node[node[temp].child[i]].layer = node[temp].layer + 1;
            q.push(node[temp].child[i]);
        }
    }
}

int main() {
    scanf("%d %d",&N,&M);
    int Nd,child_num;
    for(int i = 0 ; i < M ; i++){
        int child_temp;
        scanf("%d %d",&Nd,&child_num);
        for(int j = 0 ; j < child_num ; j++){
            scanf("%d",&child_temp);
            node[Nd].child.push_back(child_temp);
            findR[child_temp] = true;
        }
    }
    int root ;
    for(int i = 1 ; i <= N ; i++){
        if(!findR[i]){
            root = i;
            break;
        }
    }
    BFS(root);
    int max = -1 ,level = 0;
    for(int i = 1 ; i <= N ; i++){
        if(layerCount[i] > max) {
            max = layerCount[i] ;
            level = i ;
        }
    }
    printf("%d %d",max,level);
    return 0;
}