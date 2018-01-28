#include <cstdio>
#include <vector>
using namespace std;

int N,pre[1050],seq[1050];
vector<int> vi[2];

struct node {
    int data;
    node* lchild;
    node* rchild;
};

void insert(node* &q,int x){
    if(q == NULL){
        q = new node;
        q->data = x;
        q->lchild = q->rchild = NULL;
        return;
    }
    else if(x < q->data){
        insert(q->lchild,x);
    } else {
        insert(q->rchild,x);
    }
}

node* createBST(int data[],int n){
    node* root = NULL;
    for(int i = 0 ; i < N ; i++){
        insert(root,data[i]);
    }
    return root;
}

void preorder(node* root){
    if(root == NULL)
        return;
    vi[0].push_back(root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void preorder_m(node* root){
    if(root == NULL)
        return;
    vi[1].push_back(root->data);
    preorder_m(root->rchild);
    preorder_m(root->lchild);
}

int count_num = 0;
void postorder(node* root){
    if(root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d",root->data);
    count_num++;
    if(count_num < N) {
        printf(" ");
    } else {
        printf("\n");
    }
}

void postorder_m(node* root){
    if(root == NULL)
        return;
    postorder_m(root->rchild);
    postorder_m(root->lchild);
    printf("%d",root->data);
    count_num++;
    if(count_num < N) {
        printf(" ");
    } else {
        printf("\n");
    }
}

int main() {
    scanf("%d",&N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&seq[i]);
    }
    node* ROOT = createBST(seq,N);
    preorder(ROOT);
    preorder_m(ROOT);
    bool flag1 = true;
    bool flag2 = true;
    for(int i = 0 ; i < N ; i++){
        if(seq[i] != vi[0][i]) {
            flag1 = false;
            break;
        }
    }
    for(int i = 0 ; i < N ; i++){
        if(seq[i] != vi[1][i]) {
            flag2 = false;
            break;
        }
    }
    if(flag1||flag2){
        printf("YES\n");
        if(flag1 == true){
            postorder(ROOT);
        } else {
            postorder_m(ROOT);
        }
    } else {
        printf("NO\n");
    }

    return 0;
}