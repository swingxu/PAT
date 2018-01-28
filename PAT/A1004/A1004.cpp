#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    vector<int> child;
    int level = 0;
} node[110];

int n,line;

int layer_count = 0;
int layer[110] = {0};
void BFS(int root){
    queue<int> q;
    q.push(root);
    node[root].level = 1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(node[temp].child.size() == 0){
            layer[node[temp].level]++;
        }
        if(node[temp].level > layer_count) layer_count = node[temp].level;
        for(int i = 0 ; i < node[temp].child.size() ; i++){
            q.push(node[temp].child[i]);
            node[node[temp].child[i]].level = node[temp].level + 1;
        }
    }
}
int main() {
    scanf("%d%d",&n,&line);
    int no,num = 0;
    for(int i = 0 ; i < line ; i++){
        scanf("%d%d",&no,&num);
        for(int i = 0 ; i < num ; i++){
            int temp;
            scanf("%d",&temp);
            node[no].child.push_back(temp);
        }
    }
    BFS(1);
    for(int i = 1 ; i <= layer_count ; i++){
        printf("%d",layer[i]);
        if(i != layer_count) printf(" ");
    }
    return 0;
}