#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 510;
const int INF = 0x3fffffff;

int N,M,C1,C2,node[maxn] = {0},G[maxn][maxn],d[maxn],w[maxn],num[maxn];
bool vis[maxn] = {false};

void Dijkstra(int s){
    memset(num,0, sizeof(num));
    memset(w,0,sizeof(w));
    fill(d,d+maxn,INF);
    d[s] = 0;
    w[s] = node[s];
    num[s] = 1;
    for(int i = 0 ; i < N ; i++){
        int u = -1 , min = INF;
        for(int j = 0 ; j < N ; j++){
            if(d[j] < min){
                min = d[j];
                u = j;
            }
        }
        vis[u] = true;
        for(int v = 0 ; v < N ; v++){
            if(!vis[v] && G[u][v]!=INF){
                if(d[u]+G[u][v] < d[v]){
                    d[v] = d[u]+G[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + node[v];
                } else if(d[u]+G[u][v] == d[v]){
                    if(w[u] + node[v] > w[v]){
                        w[v] = w[u] + node[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&node[i]);
    }
    int a,b,temp;
    fill(G[0],G[0]+maxn*maxn,INF);
    for(int i = 0 ; i < M ; i++){
        scanf("%d%d%d",&a,&b,&temp);
        G[a][b] = temp;
        G[b][a] = temp;
    }
    Dijkstra(C1);
    printf("%d %d\n",num[C2],w[C2]);
    return 0;
}