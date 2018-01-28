#include <iostream>
const int MAXN = 110;

int N,order[MAXN];

struct node {
    int data;
    node* l;
    node* r;
};

void insert(int data,node* &root){
    if(root == NULL) {
        root = new node;
        root->data = data;
        root->l = NULL;
        root->r = NULL;
    }
    if(root->data > data){
        insert(data,root->l);
    } else {

    }
}

node* createBST(int data[],int N){
    node* root = NULL;
    for(int i = 0 ; i < N ; i++){
        insert(data[i],root);
    }
}
int main() {
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&order[i]);
    }

    return 0;
}