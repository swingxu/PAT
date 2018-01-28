#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1010;
int N,L,G[maxn][maxn] = {0};
bool vis[maxn] = {false};

struct Node {
    int id;
    int layer;
};

int BFS(int query,int level){
    int numF=0;
    queue<Node> q;
    Node start;
    start.id = query;
    start.layer = 0;
    q.push(start);
    vis[start.id] = true;
    while(!q.empty()){
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for(int i = 1 ; i <= N ; i++){
            if(G[u][i] > 0){
                Node next ;
                next.id = i;
                next.layer = topNode.layer+1;
                if(vis[next.id] == false && next.layer <= L){
                    q.push(next);
                    vis[next.id] = true;
                    numF++;
                }
            }
        }
    }
    return numF;
}

int main() {
    scanf("%d%d",&N,&L);
    int num,p;
    for(int i = 1 ; i <= N ; i++){
        scanf("%d",&num);
        for(int j = 0 ; j < num ; j++){
            scanf("%d",&p);
            G[p][i] = 1;
        }
    }
    scanf("%d",&num);
    int query;
    for(int i = 0 ; i < num ; i++){
        scanf("%d",&query);
        memset(vis,false,sizeof(vis));
        int numforward = BFS(query,L);
        printf("%d\n",numforward);
    }
    return 0;
}