#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 100010;
vector<int> node[MAXN];
const double MIN = 1e12;

int N,num=0;
double p,r,ans = MIN;

void DFS(int index,int depth){
    if(node[index].size() == 0) {
        double price = p * pow(1+r,depth);
        if(price<ans){
            ans = price;
            num = 1;
        } else if(price == ans){
            num++;
        }
        return ;
    }
    for(int i = 0 ; i < node[index].size() ; i++){
        DFS(node[index][i],depth+1);
    }
}


int main (){
    int child,k;
    scanf("%d%lf%lf",&N,&p,&r);
    r /= 100;
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&k);
        if(k!=0){
            for(int j = 0 ; j < k ;j++){
                scanf("%d",&child);
                node[i].push_back(child);
                }
        }
    };
    DFS(0,0);
    printf("%.4lf %d\n",ans,num);
    return 0;
};