#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 150;

int N , data[MAXN];

struct Node {
    int data;
    int left;
    int right;
}node[MAXN];

int k = 0 ;
void inorder(int root){
    if(root == -1) return;
    inorder(node[root].left);
    node[root].data = data[k++];
    inorder(node[root].right);
}

int _count = 0;
void BFS(int root){
    if(root == -1)
        return;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        _count++;
        printf("%d",node[temp].data);
        if(_count < N) printf(" ");
        else printf("\n");
        if(node[temp].left != -1) q.push(node[temp].left);
        if(node[temp].right != -1) q.push(node[temp].right);
    }
    return;
}

int main() {
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d %d",&node[i].left,&node[i].right);
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&data[i]);
    }
    sort(data,data+N);
    inorder(0);
    BFS(0);
    return 0;
}