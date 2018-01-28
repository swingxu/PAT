#include <iostream>
#include <queue>
using namespace std;

struct mouse {
    int m,rank;
} mice[1010];

int main() {
    int N,G;
    scanf("%d%d",&N,&G);
    for (int i = 0; i < N; i++) {
        scanf("%d",&mice[i].m);
    }
    int no;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        scanf("%d",&no);
        q.push(no);
    }
    int group_num;
    while(q.size()!=1){
        int temp = q.size();
        group_num = q.size()%G==0?q.size()/G:q.size()/G+1;
        for (int i = 0; i < group_num; i++) {
            int maxm=0,maxno,k;
            for (int j = i*G ; j < i*G+G && j < temp; j++) {
                k = q.front();
                mice[k].rank = group_num + 1;
                if(mice[k].m>maxm){
                    maxm = mice[k].m;
                    maxno = k;
                }
                q.pop();
            }
            q.push(maxno);
        }
    }
    mice[q.front()].rank = 1 ;
    for(int i = 0 ; i < N ; i++){
        printf("%d",mice[i].rank);
        if(i<N-1) printf(" ");
    }
    return 0;
}