#include <iostream>
#include <algorithm>
using namespace std;

int up(int n){
    int x[10],i=0,ans=0;
    while(n/10!=0){
        x[i++] = n%10 ;
        n = n/10 ;
    }
    x[i++] = n;
    while(i<=3) x[i++] = 0;
    sort(x,x+4);
    for (int j = 0; j <= 3 ; ++j) {
        ans = ans * 10 + x[j];
    }
    return ans;
}

int down(int n){
    int x[10],i=0,ans=0;
    while(n/10!=0){
        x[i++] = n%10 ;
        n = n/10 ;
    }
    x[i++] = n;
    while(i<=3) x[i++] = 0;
    sort(x,x+4);
    for (int j = 3; j >= 0 ; --j) {
        ans = ans * 10 + x[j];
    }
    return ans;
}

int main() {
    int N,ans=1;
    scanf("%d",&N);
    ans = down(N) - up(N);
    while(ans != 6174){
        if(ans==0) {
            printf("%04d - %04d = %04d\n",down(N),up(N),ans);
            break;
        } else {
            printf("%04d - %04d = %04d\n",down(N),up(N),ans);
            N = ans ;
            ans = down(N) - up(N);
        }
    }
    if(ans==6174) printf("%04d - %04d = %04d\n",down(N),up(N),ans);
    return 0;
}