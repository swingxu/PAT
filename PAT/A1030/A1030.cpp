#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 510;
const int INF = 0x3fffffff;

int N,M,S,D;
int G[MAXN][MAXN],d[MAXN],fee[MAXN][MAXN],cost[MAXN] = {0},pre[MAXN];
bool vis[MAXN] = {false};

void Dijkstra (int s){
    fill(d,d+MAXN,INF);
    fill(cost,cost+MAXN,INF);
    for(int i = 0 ; i < N ; i++) pre[i] = i;
    d[s] = 0;
    cost[s] = 0;
    for(int i = 0 ; i < N ; i++){
        int min = INF, u = -1;
        for(int j = 0 ; j < N ; j++){
            if(d[j] < min && !vis[j]) {
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0 ; v < N ; v++){
            if(!vis[v] && G[u][v]!=INF){
                if(G[u][v] + d[u] < d[v]){
                    d[v] = G[u][v] + d[u];
                    cost[v] = cost[u] + fee[u][v];
                    pre[v] = u;
                } else if (G[u][v] + d[u] == d[v]){
                    if(fee[u][v] + cost[u] < cost[v]){
                        cost[v] = fee[u][v] + cost[u];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}

void DFS(int end,int now){
    if(end == now){
        printf("%d ",end);
        return;
    }
    DFS(end,pre[now]);
    printf("%d ",now);
}

int main() {
    scanf("%d%d%d%d",&N,&M,&S,&D);
    int a,b;
    fill(G[0],G[0] + MAXN * MAXN ,INF);
    for(int i = 0 ; i < M ; i++){
        scanf("%d%d",&a,&b);
        scanf("%d%d",&G[a][b],&fee[a][b]);
        G[b][a] = G[a][b];
        fee[b][a] = fee[a][b];
    }
    Dijkstra(S);
    DFS(S,D);
    printf("%d %d\n",d[D],cost[D]);
    return 0;
}