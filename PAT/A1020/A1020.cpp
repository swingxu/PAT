
#include <iostream>
#include <queue>
using namespace std;
int post[35],in[35],N;

struct node{
    int data;
    node* lchild;
    node* rchild;
};


node* create(int postL,int postR,int inL,int inR){
    if(postL > postR) {
        return NULL;
    }
    node* root = new node ;
    root->data = post[postR];
    int i ;
    for (i = inL; i <= inR; i++) {
        if(in[i] == post[postR]) {
            break;
        }
    }
    int numleft = i - inL;
    root->lchild = create(postL,postL+numleft-1,inL,i-1);
    root->rchild = create(postL+numleft,postR-1,i+1,inR);
    return root;
};

int num = 0;
void BFS(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* now = q.front();
        q.pop();
        printf("%d",now->data);
        num ++;
        if(num < N) printf(" ");
        if(now->lchild != NULL) {
            q.push(now->lchild);
        }
        if(now->rchild != NULL) {
            q.push(now->rchild);
        }
    }

}
int main() {
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        scanf("%d",&post[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d",&in[i]);
    }
    node* root = create(0,N-1,0,N-1);
    BFS(root);
    return 0;
}

