#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,grade[4][2005];
int r[2005];
struct student{
    int rank[4];
}stu[2005];

map<string,int> s2i;
int n;
bool cmp (int a , int b){
    return grade[n][a] > grade[n][b];
}

void init(){
    fill(r,r+2005,2006);
    for(int i = 0 ; i < N ; i++){
        r[i] = i ;
    }
}

void ranking (){
    init();
    sort(r,r+N,cmp);
    int num = 1;
    stu[r[0]].rank[n] = 1;
    for(int i = 1 ; i < N ; i++){
        if(grade[n][r[i]]!=grade[n][r[i-1]]) {
            stu[r[i]].rank[n] = ++num;
        } else {
            stu[r[i]].rank[n] = stu[r[i-1]].rank[n] ;
            num ++;
        }
    }
}

char sub[4] = {'C','M','E','A'};

int main() {
    scanf("%d%d",&N,&M);
    for(int i = 0 ; i < N ; i++){
        string str;
        cin >> str;
        s2i[str] = i;
        scanf("%d%d%d",&grade[0][i],&grade[1][i],&grade[2][i]);
        grade[3][i] = (grade[0][i]+grade[1][i]+grade[2][i])/3;
    }
    for(int i = 0 ; i < 4 ; i++){
        n = i;
        ranking();
    }
    int level[4] = {3,2,1,4};
    for(int i = 0 ; i < M ; i++){
        string str;
        cin >> str;
        if(s2i.find(str) == s2i.end()){
            printf("N/A\n");
            continue;
        }
        int no = s2i.find(str)->second;
        int min=101,min_no;
        for(int j = 0 ; j < 4 ;j++){
            if(stu[no].rank[j] < min) {
                min = stu[no].rank[j];
                min_no = j;
            } else if (stu[no].rank[j] == min){
                if(level[j] > level[min_no]){
                    min_no = j;
                }
            }
        }
        printf("%d %c\n",min,sub[min_no]);
    }
    return 0;
}