#include <iostream>
#include <set>
using namespace std;
const int N = 51;

set<int> st[N];

int main() {
    int N,ans[2010][2];
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        int num ;
        scanf("%d",&num);
        for (int j = 0; j < num; j++) {
            int x;
            scanf("%d",&x);
            st[i].insert(x);
        }
    }
    int qnum;
    scanf("%d",&qnum);
    for (int k = 0; k < qnum; k++) {
        int a,b;
        scanf("%d%d",&a,&b);
        int total=st[b-1].size(),same=0;
        for (set<int>::iterator it = st[a-1].begin(); it != st[a-1].end(); it++) {
            if (st[b-1].find(*it) != st[b-1].end()) same++;
            else total++;
        }
        ans[k][0] = same;
        ans[k][1] = total;
    }
    for(int k = 0; k < qnum ;k++){
        printf("%.1lf%%\n",ans[k][0] * 100.0/ans[k][1]);
    }
    return 0;
}