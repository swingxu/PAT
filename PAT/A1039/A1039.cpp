#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 26*26*26*10+1;

vector<int> Selection[M];

int getID(char a[]){
    int id = 0 ,i = 0;
    for(i = 0 ; i < 3 ; i++){
        id = id * 26 + (a[i] - 'A') ;
    }
    id = id * 10 + (a[i] - '0');
    return id;
}

int main() {
    char stu[5];
    int StuNum,CourseNum,idx,stunum;
    scanf("%d%d",&StuNum,&CourseNum);
    for (int i = 0; i < CourseNum; i++) {
        scanf("%d %d",&idx,&stunum);
        for (int j = 0; j < stunum; j++) {
            scanf("%s",stu);
            Selection[getID(stu)].push_back(idx);
        }
    }
    for (int k = 0; k < StuNum; k++) {
        scanf("%s",stu);
        int id = getID(stu);
        sort(Selection[id].begin(),Selection[id].end());
        printf("%s %d",stu,Selection[id].size());
        if(Selection[id].size()!=0) printf(" ");
        for (int i = 0; i < Selection[id].size(); i++) {
            printf("%d",Selection[id][i]);
            if(i<Selection[id].size()-1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}