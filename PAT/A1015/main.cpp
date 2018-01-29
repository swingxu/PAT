#include <iostream>
#include <math.h>
using namespace std;

/*
 * 打印的格式一定要注意……因为No没区分大小写卡了20分钟...
 */
bool isPrime(int n) {
    if(n <= 1) return false;
    int temp = (int)sqrt(n * 1.0);
    for(int i = 2 ; i <= temp ;i++){
        if(n%i == 0) return false;
    }
    return true;
}

int convert(int n,int radix){
    int d[111];
    int len = 0;
    while(n != 0) {
        d[len++] = n%radix;
        n /= radix;
    }
    int ans = 0;
    for(int i = 0 ; i < len ; i++){
        ans = ans*radix + d[i];
    }
    return ans;
}

int main() {
    int a,b;
    while(scanf("%d",&a) != EOF){
        if(a < 0) break;
        scanf("%d",&b);
        if(isPrime(a)&&isPrime(convert(a,b))) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}