#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a ,int b){
    return a<b;
}
int main() {
    int N,p,a[100010],i,j;
    scanf("%d%d",&N,&p);
    for( i = 0 ; i<N ; i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N,cmp);
    for(i = 0 ; i<N ; i++){
        if((long long)a[i]*p>=a[N-1]) break;
    }
    for(j = N-1 ; j>=0 ;j--){
        if((long long)a[0]*p>=a[j]) break;
    }
    printf("%d",(N-i)>(j+1)? (N-i):(j+1));
    return 0;
}