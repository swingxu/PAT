#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> temp,ans,fac;

int N,K,P,maxfacsum=-1;

int power(int x){
    int ans = 1;
    for(int i = 0 ; i<P ; i++){
        ans *= x;
    }
    return ans;
}

void init(){
    int i = 0,temp = 0;
    while(temp <= N){
        fac.push_back(temp);
        temp = power(++i);
    }
}

void DFS(int index,int nowK,int sum,int facsum){
    if(nowK==K && sum == N){
        if(facsum > maxfacsum){
            ans = temp;
            maxfacsum = facsum;
        }
        return;
    }
    if(sum > N || nowK > K) return;
    if( index -1 >= 0 ){
        temp.push_back(index);
        DFS(index,nowK+1,sum+fac[index],facsum+index);
        temp.pop_back();
        DFS(index-1,nowK,sum,facsum);
    }
}

int main() {
    scanf("%d%d%d",&N,&K,&P);
    init();
    DFS(fac.size()-1,0,0,0);
    if(maxfacsum == -1) printf("Impossible\n");
    else {
        printf("%d = %d^%d",N,ans[0],P);
        for(int i = 1 ;i < ans.size();i++){
            printf(" + %d^%d",ans[i],P);
        }
        printf("\n");
    }
    return 0;
}