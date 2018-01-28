#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    int height;
} ;

node* newnode(int v){
    node* Node = new node;
    Node->height = 1;
    Node->data = v;
    Node->left = Node->right = NULL;
    return Node;
}

int getHeight(node* Node){
    if(Node == NULL) return 0;
    return Node->height;
}

void updateHeight(node* root){
    root->height = max(getHeight(root->left),getHeight(root->right))+1;
}

int getBalanceFactor(node* root) {
    return getHeight(root->left) - getHeight(root->right);
}

void L(node* &root){
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root){
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root,int v){
    if(root == NULL){
        root = newnode(v);
        return;
    }
    if(v < root->data){
        insert(root->left,v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->left) == 1){
                R(root);
            } else {
                L(root->left);
                R(root);
            }
        }
    } else {
        insert(root->right,v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root) == -1){
                L(root);
            } else {
                R(root->right);
                L(root);
            }
        }
    }
}

int main(){
    int N,v;
    node* root = NULL;
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&v);
        insert(root,v);
    }
    printf("%d\n",root->data);
    return 0;
}
