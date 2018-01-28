#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
bool exist[10050] = {false};
int num[10050] = {0};
int father[10050];
vector<int> G[10050];

int findf(int data){
    int x = data;
    while(father[data] != data){
        data = father[data];
    }
    while(father[x] != x){
        int z = x;
        x = father[x];
        father[z] = data;
    }
    return data;
}

void Union(int a,int b){
    int fa = findf(a);
    int fb = findf(b);
    if(fa != fb){
        father[fa] = fb;
    }
}

void init(){
    for(int i = 0 ; i <= N ; i++){
        father[i] = i ;
    }
}

int maxh = 0;
set<int> temp,ans;
void DFS(int now,int height ,int pre){
    if(height > maxh){
        temp.clear();
        temp.insert(now);
        maxh = height;
    } else if (height == maxh) {
        temp.insert(now);
    }
    for(int i = 0 ; i < G[now].size();i++){
        if(G[now][i] == pre) continue;
        DFS(G[now][i],height+1,now);
    }
}

int main() {
    scanf("%d",&N);
    int a,b;
    init();
    for(int i = 0 ; i < N-1 ; i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a,b);
    }
    int sum = 0;
    for(int i = 1 ; i <= N ; i++){
       if(!exist[findf(i)]) {
           sum++;
           exist[findf(i)] = true;
       }
    }
    if(sum > 1){
        printf("Error: %d components",sum);
    } else {
        DFS(1,1,-1);
        ans = temp;
        DFS(*ans.begin(),1,-1);
        set<int>::iterator it;
        for(it = temp.begin() ; it != temp.end() ;it++){
            ans.insert(*it);
        }
        for(it= ans.begin() ; it != ans.end() ; it++){
            printf("%d\n",*it);
        }
    }
    return 0;
}