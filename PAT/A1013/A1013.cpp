#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1050;

int N,M,K,G[maxn][maxn];
bool vis[maxn] = {false};

void DFS(int point,int current){
    if(point == current) return;
    vis[point] = true;
    for(int i = 1 ; i <= N ; i++){
        if(G[point][i] > 0) {
            if(vis[i] == false) DFS(i,current);
        }
    }
}

int island_num;
void DFStrave(int current){
    for(int i = 1 ; i <= N ; i++){
        if(!vis[i] && i!=current){
            DFS(i,current);
            island_num++;
        }
    }
}


int main() {
    cin >> N >> M >> K ;
    for(int i = 0 ; i < M ; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a][b] = G[b][a] = 1;
    }
    int x;
    for(int i = 0 ; i < K ; i++){
        scanf("%d",&x);
        memset(vis,false,sizeof(vis));
        island_num = 0;
        DFStrave(x);
        printf("%d\n",island_num-1);
    }
    return 0;
}