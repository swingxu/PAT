#include <cstring>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 50;
int N,pre[maxn],in[maxn];

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* create(int preL,int preR,int inL,int inR){
    if(preL > preR){
        return NULL;
    }
    node* root = new node ;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++) {
        if(pre[preL]==in[k]) break;
    }
    int numLeft = k - inL ;
    root->lchild = create(preL+1,preL+numLeft,inL,k-1);
    root->rchild = create(preL+numLeft+1,preR,k+1,inR);
    return root;
}

int countN = 0;
void PostReverse(node* root){
    if(root == NULL){
        return;
    }
    PostReverse(root->lchild);
    PostReverse(root->rchild);
    printf("%d",root->data);
    countN++;
    if(countN < N) printf(" ");
}

int main() {
    scanf("%d",&N);
    int i=0,j=0,temp;
    char s[5];
    stack<int> stk;
    for(int k = 0 ; k<N*2 ; k++){
        scanf("%s",s);
        if(strcmp(s,"Push")==0){
            scanf("%d",&temp);
            stk.push(temp);
            pre[i++] = temp;
        } else {
            in[j++] = stk.top() ;
            stk.pop();
        }
    }
    node* root = create(0,N-1,0,N-1);
    PostReverse(root);
    return 0;
}