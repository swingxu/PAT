#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N;

struct node{
    int data;
    int lchild;
    int rchild;
};

struct nd{
    int left;
    int right;
}nds[20];

bool mp[20] = {false};
void create_nd(int no,char a,char b){
    if(a >= '0'&&a <= '9') {
        nds[no].left = a - '0';
        mp[a-'0'] = true;
    } else {
        nds[no].left = -1;
    }
    if(b >= '0'&&b <= '9') {
        nds[no].right = b - '0';
        mp[b-'0'] = true;
    } else {
        nds[no].right = -1;
    }
}

queue<int> q;
int num = 0;
void LayerOrder (int r) {
    q.push(r);
    while(!q.empty()){
        int top = q.front();
        printf("%d",top);
        num++;
        if(num<N) printf(" ");
        else printf("\n");
        q.pop();
        if(nds[top].right!=-1){
            q.push(nds[top].right);
        }
        if(nds[top].left!=-1){
            q.push(nds[top].left);
        }
    }
}

int num2 = 0;
void PostOrder(int root){
    if(root == -1) {
        return;
    }
    PostOrder(nds[root].right);
    printf("%d",root);
    num2++;
    if(num2<N) printf(" ");
    else printf("\n");
    PostOrder(nds[root].left);

}

int main() {
    scanf("%d",&N);
    char a,b;
    for(int i = 0 ; i<N ; i++){
        scanf("%*c%c %c",&a,&b);
        create_nd(i,a,b);
    }
    int r;
    for(r = 0 ; r<N ;r++){
        if(!mp[r]) break;
    }
    LayerOrder(r);
    PostOrder(r);
    return 0;
}