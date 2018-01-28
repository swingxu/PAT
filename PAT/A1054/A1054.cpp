#include <iostream>
#include <map>
using namespace std;

/*
 * 1 迭代器的使用
 * 2 find */

map<int,int> _count;

int main() {
    int M,N,num;
    scanf("%d%d",&M,&N);
    for( int i = 0 ; i<N ;i++ ) {
        for( int j = 0 ; j<M ; j++ ){
            scanf("%d",&num);
            if(_count.find(num)!=_count.end()) _count[num]++;
            else _count[num] = 1;
        }
    }
    int MAX = 0 , k = 0;
    for (map<int,int>::iterator it = _count.begin();it!=_count.end();it++) {
        if(it->second > MAX){
            k = it -> first;
            MAX = it -> second;
        }
    }
    printf("%d\n",k);
    return 0;
}