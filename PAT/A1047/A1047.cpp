#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int M = 40010;
const int C = 2550;
char name[M][6];

vector<int> Course[C];

bool cmp(int a,int b){
    return strcmp(name[a],name[b])<0;
}


int main() {
    int m,n;
    scanf("%d%d",&m,&n);
    for (int i = 0; i < m; i++) {
        int course,sum;
        scanf("%s %d",name[i],&sum);
        for (int j = 0; j < sum; j++) {
            scanf("%d",&course);
            Course[course].push_back(i);
        }
    }


    for (int k = 1; k <= n; k++) {
        int size = Course[k].size();
        printf("%d %d\n",k,size);
        sort(Course[k].begin(),Course[k].end(),cmp);
        for (int i = 0; i < size; i++) {
            int no = Course[k][i];
            printf("%s\n",name[no]);
        }
    }

    return 0;
}